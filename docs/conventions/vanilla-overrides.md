# Vanilla Overrides
> So you want to override the default vanilla loot tables... and more!

```{admonition} 🚧 In Construction 🚧
:class: warning

**Weld** isn't a completed tool yet so there may be future changes!
```

One rough edge of natural compatibility between data packs are vanilla resources. The default game's biomes, loot tables, advancements — these are difficult to override as other packs might clash causing a lost of behavior. We have solved this problem by integrating a custom merging solution via **Weld**.

**Weld** is a tool to help merge data and resource packs in an efficient manner. Similar to how the game automatically merges tag files, **Weld** allows you to define extra metadata to define how you would like your JSON-type files to merge. This allows you to define an override which is **compatible** with other weld-enabled packs!

```{note}

The goal of Weld is to preserve the original author's intent with their modification/creation of the file being merged. 
```

```{important}

This is only required if you are overwriting **VANILLA loot tables**.
```

## Metadata
Smithed metadata is stored within the __smithed__ element of the JSON file.
```json
// Example
{
    "pools": [
        {
            "entries": [
                {
                    "type": "item",
                    "item": "minecraft:dirt"
                }
            ]
        }
    ],
    // Here is where the metadata is stored
    "__smithed__": {
    
    }
}
```

```{note}

We use comments in our `json` blocks here but they will not work in-game.
```

### Priority
Priority determines in what order your rule run since the changes from one rule can affect the results of the next. 
- `default` -> The default priorty value, higher values run first (Vanilla loot tables are handled first regardless)
- `after` -> A list of packs for the rules to run after
- `before` -> A list of packs for the rules to run before

### Rules
Rules have a few different types to accomplish different tasks. All current rules follow a Target/Source format

```json
// Some code
{
    "type": "EXAMPLE",
    "target": "pools",
    "source": {
        "type": "smithed:reference",
        "path": "pools[0]"
    },
    "conditions": []
}
```

- `smithed:merge` -> Completely overrides the targeted data
- `smithed:append` -> Appends the source value to the target
- `smithed:prepend` -> Prepends the source value to the target
- `smithed:insert` -> Inserts a value in the target at the specified index
  - "index" element used to specify within the JSON

### Sources
Sources provide rules with the data they need, currently there are 2 types of sources
- `smithed:reference` -> Returns the data at the specified path
- `smithed:value` -> Returns the data specified in data, this is also chosen if no valid type is specified

### Conditions
Conditions allow you to have rules execute conditionally. There are only 2 types of conditions:
- `smithed:pack_check` -> Check if a certain pack is installed
  - `id` -> The pack id to check for (based on the Smithed Database ID)
- `smithed:inverted` -> Inverts the result of its child condition
  - `condition` -> The condition to invert

#### Example

```json
{
    "pools": ["data here"],
    "__smithed__": {
        "rules": [
            {
                "type": "smithed:append",
                "target": "pools",
                "source":{
                    "type": "smithed:reference",
                    "path": "pools[1]"
                },
                "conditions":[
                    {
                        "type": "smithed:pack_check",
                        "id": "creepermagnet_:tcc"
                    }
                ]
            }
        ],
        "priority":{
            "after": [
                "hashs:undermagic"
            ],
            "before": [
                "starmute:terralith"
            ]
        }
    }
}
