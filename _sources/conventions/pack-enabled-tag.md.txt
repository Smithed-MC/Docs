---
myst:
  substitutions:
    summary: "Marking your datapack as enabled (and optionally what version)"
    required: "For all data packs willing to support cross-datapack functionality"
    example: "Gamemode 4 Bat Grenades won't drop any items if it detects that Myriad is installed"
---

# {{new_bdg}} Pack Enabled Tags
{{ convention_header }}

This convention adds a predicate to mark a datapack as enabled. Additionally, context integer (number) providers can be used to return the version of a datapack. To prevent load errors, the predicate and number provider(s) are wrapped with tags, similar to function tags used for library API calls.

## Terminology
There are two types of datapacks that will be referenced throughout this document: “producer” datapacks and “consumer” datapacks. A “producer” supplies its own version information while a “consumer” checks a “producer’s” version information. In practice, a datapack could be a producer, consumer, or both (or neither if they are not following this convention). 

## Usage

### Pack Enabled Predicate
Each datapack will provide a predicate that always evaluates to `true`. The simplest implementation is a predicate with the type of `random_chance` with a `chance` of 1. The datapack will also provide a predicate tag that wraps that predicate. The naming scheme is not strictly enforced, but for consistency, it is recommended to put the predicate tag under `#ns:installed`, with `ns` being the namespace of the datapack (e.g. `#smithed.custom_block:installed`).

In order to detect an installed datapack, the consumer datapack will simply check if the producer datapack’s predicate tag returns `true`. Predicate tags are used to suppress load errors; the consumer datapack must include a predicate with an empty values list at the same resource location as the producer datapack (the previously coined `#ns:installed`). The replace field should be `false`, but that is the default.

#### Enabled Predicate Example Implementation
:::::{tab-set}
::::{tab-item} Files in Producer Pack
`data/ns_producer/predicate/installed.json`
```json
{
  "type": "minecraft:random_chance",
  "chance": 1
}
```

`data/ns_producer/tags/predicate/installed.json`
```json
{
  "values": [
    "ns_producer:installed"
  ]
}
```
::::

::::{tab-item} Files in Consumer Pack
`data/ns_producer/tags/predicate/installed.json`
```json
{
  "values": []
}
```

`data/ns_consumer/predicate/producer_installed.json`
```json
{
  "type": "minecraft:any_of",
  "terms": "#ns_producer:installed"
}
```
::::
:::::

### Pack Version Number Providers
To convey version information, each datapack will provide a context integer provider tag in `#ns:major` that returns a non-negative integer via a context integer provider; again, tags are used since they can prevent load errors in the consumer pack when the producer pack is not installed. Optionally, `#ns:minor` and `#ns:patch` are recommended to convey more information about the version. [Semantic versioning](https://semver.org) is recommended so it is easier to understand when breaking changes happen versus when additional tie-in points have been added (patch is less necessary since it doesn’t inherently convey any relevant information). Again, the naming scheme is not strictly required for this convention, but recommended for consistency. 

To detect the version of a datapack, the consumer datapack will use their own predicate to check the value of the number providers supplied by the producer. This is most easily done by using a predicate with the type of `int_value_check`, a value of type `max` with an input checking the number provider tag, using the test to determine if the range is as expected (e.g. the major version is an exact value and the minor version is at least a certain value). Similar to the suppression of the predicate load errors, a number provider tag should be included in the consumer datapack. However, simply using an empty `values` list will throw a warning, so a dummy number provider that returns a negative value should be added to the tag. 

#### Version Number Provider Example Implementation
:::::{tab-set}
::::{tab-item} Files in Producer Pack
`data/ns_producer/context_int_provider/major.json`
```json
1
```

`data/ns_producer/context_int_provider/minor.json`
```json
2
```

`data/ns_producer/context_int_provider/patch.json`
```json
3
```

`data/ns_producer/tags/context_int_provider/major.json`
```json
{
  "values": [
    "ns_producer:major"
  ]
}
```

`data/ns_producer/tags/context_int_provider/minor.json`
```json
{
  "values": [
    "ns_producer:minor"
  ]
}
```

`data/ns_producer/tags/context_int_provider/patch.json`
```json
{
  "values": [
    "ns_producer:patch"
  ]
}
```
::::

::::{tab-item} Files in Consumer Pack
`data/ns_consumer/context_int_provider/neg_one.json`
```json
-1
```

```{admonition} Note
:class: note
The `neg_one` number provider is necessary to avoid warnings in the log when the producer pack is not installed.
```

`data/ns_producer/tags/context_int_provider/major.json`
```json
{
  "values": [
    "ns_consumer:neg_one"
  ],
  "replace": false
}
```

`data/ns_producer/tags/context_int_provider/minor.json`
```json
{
  "values": [
    "ns_consumer:neg_one"
  ],
  "replace": false
}
```

`data/ns_consumer/predicate/dependency_version_matches.json`
```json
{
  "type": "minecraft:all_of",
  "terms": [
    {
      "type": "minecraft:int_value_check",
      "value": {
        "type": "minecraft:max",
        "inputs": "#ns_producer:major"
      },
      "test": 1
    },
    {
      "type": "minecraft:int_value_check",
      "value": {
        "type": "minecraft:max",
        "inputs": "#ns_producer:minor"
      },
      "test": {
        "min": 2
      }
    }
  ]
}
```
```{admonition} Note
:class: note
Notice that `data/ns_producer/tags/context_int_provider/patch.json` is not included since the consumer does not check that tag.
```
::::
:::::

## Advanced Use Cases
The following is technically out of scope for this convention, but useful when dealing with conditionally enabled packs and packaged libraries. 

### Functionally Disabled
A datapack may wish to functionally disable itself if dependencies are not present or a version mismatch occurs. This is typically done by checking a value with a predicate as a conditional requirement in advancements, loot tables, etc. (The `datapack disable` command is unreliable as it relies on an assumption that the user did not rename the file). Therefore, it may be misleading to return that the pack is installed while it is functionally disabled. 

This can be solved by changing the installed predicate to one that returns true if and only if the dependency versions are as expected. The implementation is the same as the Version Number Providers consumer check, except the predicate will be used as its own installed predicate.

#### Conditionally Installed Example
All of these files go in the producer pack that changes its installed status when it is functionally disabled.

`data/my_datapack/context_int_provider/neg_one.json`
```json
-1
```

```{admonition} Note
:class: note
The `neg_one` number provider is necessary to avoid warnings in the log when the library dependency is not installed.
```

`data/library_dependency/tags/context_int_provider/major.json`
```json
{
  "values": [
    "my_datapack:neg_one"
  ],
  "replace": false
}
```

`data/library_dependency/tags/context_int_provider/minor.json`
```json
{
  "values": [
    "my_datapack:neg_one"
  ],
  "replace": false
}
```

`data/my_datapack/predicate/installed.json`
```json
{
  "type": "minecraft:all_of",
  "terms": [
    {
      "type": "minecraft:int_value_check",
      "value": {
        "type": "minecraft:max",
        "inputs": "#library_dependency:major"
      },
      "test": 1
    },
    {
      "type": "minecraft:int_value_check",
      "value": {
        "type": "minecraft:max",
        "inputs": "#library_dependency:minor"
      },
      "test": {
        "min": 2
      }
    }
  ]
}
```

### Packaged Library Version Resolution
The version checks break if there are multiple packs under the same namespace supplying different versions. This is irrelevant for almost all packs apart from packaged libraries. With packaged libraries, there is a likelihood that one datapack may contain a version of a library that is older than the same library that another datapack contains. Therefore, libraries may need to resolve the highest version and functionally disable themselves if their own version is not the latest version of the library. 

This can be done by performing conditional checks within the number providers instead of simply outputting an integer. 

#### Version Resolution Example Implementation
All of these files go in the producer pack that needs to resolve the version.

:::::{tab-set}
::::{tab-item} Version
These number providers provide a single source of truth, so it doesn't need to be updated in multiple locations.

`data/ns_library-v1.2.3/context_int_provider/internal/major.json`
```json
1
```

`data/ns_library-v1.2.3/context_int_provider/internal/minor.json`
```json
2
```


`data/ns_library-v1.2.3/context_int_provider/internal/patch.json`
```json
3
```
::::

::::{tab-item} Resolution
These resolve the library’s own version. major is technically redundant since it just pulls the `internal/major` value, but this makes for a nice file structure.

`data/ns_library-v1.2.3/context_int_provider/major.json`
```json
{
   "type": "minecraft:max",
   "inputs": "ns_library-v1.2.3:internal/major"
}
```


`data/ns_library-v1.2.3/context_int_provider/minor.json`
```json
{
  "type": "minecraft:conditional",
  "condition": {
    "type": "minecraft:int_value_check",
    "value": {
      "type": "minecraft:max",
      "inputs": "#ns_library:major"
    },
    "test": "ns_library-v1.2.3:internal/major"
  },
  "on_true": "ns_library-v1.2.3:internal/minor",
  "on_false": -1
}
```

`data/ns_library-v1.2.3/context_int_provider/patch.json`
```json
{
  "type": "minecraft:conditional",
  "condition": {
    "type": "minecraft:int_value_check",
    "value": {
      "type": "minecraft:max",
      "inputs": "#ns_library:major"
    },
    "test": "ns_library-v1.2.3:internal/major"
  },
  "on_true": {
    "type": "minecraft:conditional",
    "condition": {
      "type": "minecraft:int_value_check",
      "value": {
        "type": "minecraft:max",
        "inputs": "#ns_library:minor"
      },
      "test": "ns_library-v1.2.3:internal/minor"
    },
    "on_true": "ns_library-v1.2.3:internal/patch",
    "on_false": -1
  },
  "on_false": -1
}
```

::::

::::{tab-item} Tags
These are the same function tags that normally provide the version.

`data/ns_library/tags/context_int_provider/major.json`
```json
{
  "values": [
    "ns_library-v1.2.3:major"
  ]
}
```

`data/ns_library/tags/context_int_provider/minor.json`
```json
{
  "values": [
    "ns_library-v1.2.3:minor"
  ]
}
```

`data/ns_library/tags/context_int_provider/patch.json`
```json
{
  "values": [
    "ns_library-v1.2.3:patch"
  ]
}
```

```{admonition} Note
:class: note
Since the convention already specifies consumers to use max to check the version, these tags resolve to the latest library version without any changes to the consumer that is checking the version.
```

::::
:::::
