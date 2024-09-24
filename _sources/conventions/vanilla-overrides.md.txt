---
myst:
  substitutions:
    summary:  "Extra metadata to define custom merging for any `json` resource"
    required: "Only when overriding any vanilla resource (under `minecraft` namespace)"
    example:  "Replacing iron ingots with iron nuggets for zombies (loot table)"
---

# Vanilla Overrides
{{ convention_header }}

One rough edge of compatibility between data packs are the vanilla namespaced resources. The default game's biomes, loot tables, advancements — these are difficult to override as other packs might clash causing a loss of behavior. We have solved this problem by integrating a custom merging solution into [**Weld**](weld).

**Weld** is a tool to help merge data and resource packs in an efficient manner. Similar to how the game automatically merges tag files, **Weld** allows you to define extra metadata to define how you would like your JSON-type files to merge. This allows you to define an override which is **compatible** with other weld-enabled packs!

```{note}
The goal of Weld is to preserve the original author's intent with their modification/creation of the file being merged. 
```

## Metadata
Smithed metadata is stored within the `__smithed__` element of the JSON file. Here, you can define how you want to **inject** your data into the vanilla resource. This is done through a set of rules which are defined in the `rules` element. 

```{note}
Any extra fields, such as the `__smithed__` field, will be ignored by the game when loaded. This allows you to define a *valid* loot table file while also being able to customize is when `weld` is used on your pack.
```

```{code-block} json
:caption: Here is a simple example of us appending a new pool that drops iron ingots
{
  // Fields from `minecraft:blocks/dirt`
  "__smithed__": {
    "rules": [
      {
        "type": "append",
        "target": "pools",
        "source": {
          "value": {
            "rolls": 1,
            "bonus_rolls": 0,
            "entries": [
              {
                "type": "minecraft:item",
                "name": "minecraft:iron_ingot"
              }
            ]
          }
        }
      }
    ]
  }
}
```

```{note}
We use comments in our `json` blocks here but they will **not** work in-game.
```

Here, we define a list of rules which apply multiple adjustments to the loot table. In this example, we define an `append` rule which targets the original `pools` field and appends a new entry defined by the `source` field. This will result in a loot table with a new pool that will drop an iron ingot.

It's pretty common to define your intended resource in the vanilla namespace, then use the `__smithed__` rule to define how you want to merge into the vanilla resource when welded. This allows you to have the intended behavior if your pack is used without `weld`, a really important feature.

## Examples

::::{dropdown} The simplest usage: appending into `pools`

The most common use case of welding for the purposes of this convention is appending a new pool or entry into a vanilla loot table. This example adds a pool that drops `iron_nugget`s into the zombie loot table.

```{code-block} json
:caption: "`minecraft:entities/zombies` loot table *from [tcc](https://beta.smithed.dev/packs/ssISzemBUMUEFJWYuB1V)*"

{
  "type": "minecraft:entity",
  "pools": [
    {
      "rolls": 1,
      "entries": [
        {
          "type": "minecraft:item",
          "functions": [
            {
              "function": "minecraft:set_count",
              "count": {
                "type": "minecraft:uniform",
                "min": 0,
                "max": 2
              },
              "add": false
            },
            {
              "function": "minecraft:looting_enchant",
              "count": {
                "type": "minecraft:uniform",
                "min": 0,
                "max": 1
              }
            }
          ],
          "name": "minecraft:rotten_flesh"
        }
      ]
    },
    {
      "rolls": 1,
      "entries": [
        {
          "type": "minecraft:item",
          "name": "minecraft:iron_ingot"
        },
        {
          "type": "minecraft:item",
          "name": "minecraft:carrot"
        },
        {
          "type": "minecraft:item",
          "name": "minecraft:potato",
          "functions": [
            {
              "function": "minecraft:furnace_smelt",
              "conditions": [
                {
                  "condition": "minecraft:entity_properties",
                  "predicate": {
                    "flags": {
                      "is_on_fire": true
                    }
                  },
                  "entity": "this"
                }
              ]
            }
          ]
        }
      ],
      "conditions": [
        {
          "condition": "minecraft:killed_by_player"
        },
        {
          "condition": "minecraft:random_chance_with_looting",
          "chance": 0.025,
          "looting_multiplier": 0.01
        }
      ]
    },
    // This pool is new behavior from TCC
    {
      "rolls": 1,
      "entries": [
        {
          "type": "item",
          "weight": 1,
          "name": "minecraft:iron_nugget",
          "functions": [
            {
              "function": "set_count",
              "count": {
                "min": 0,
                "max": 1
              }
            },
            {
              "function": "looting_enchant",
              "count": {
                "min": 0,
                "max": 1
              }
            }
          ]
        }
      ]
    }
  ],
  "random_sequence": "minecraft:entities/zombie",
  "__smithed__": {
    "rules": [
      // This rule then appends our new pool into the vanilla one.
      {
        "type":"append",
        "target":"pools",
        "source": {
          // We use `reference` source as a way to re-use the json we wrote earlier.
          "type":"reference",
          "path":"pools[2]"
        }
      }
    ]
  }
}
```

::::

::::{dropdown} Merging into an empty loot table

There might be times where you might be working with an empty resource file where you are adding your own data. In this case, `weld` will dynamically create the *expected* object within the JSON as you target it. For example, appending into a non-existant `pools` field will dynamically create an array.

An example of this behavior can be seen from GM4's bat grenades where add bat leather and gunpowder to bats, a mob that has an empty loot table by default.

```{admonition} Fun Fact
:class: tip

Both GM4's bat grenades and TCC add a rabbit hide equivalent to this loot table!
```

```{code-block} json
:caption: In vanilla, this loot table is completely empty!

{
  "type": "minecraft:entity",
  "pools": [
    {
      "rolls": 1,
      "entries": [
        {
          "type": "item",
          "name": "minecraft:gunpowder",
          "functions": [
            {
              "function": "set_count",
              "count": {
                "min": 1,
                "max": 3
              }
            }
          ]
        }
      ]
    },
    {
      "rolls": 1,
      "entries": [
        {
          "type": "item",
          "name": "minecraft:rabbit_hide",
          "functions": [
            {
              "function": "set_nbt",
              "tag": "{CustomModelData:3420001}"
            },
            {
              "function": "set_name",
              "name": {
                "translate": "item.gm4.bat_leather",
                "fallback": "Bat Leather",
                "italic": false
              }
            },
            {
              "function": "set_lore",
              "lore": [
                {
                  "translate": "text.gm4.bat_leather.1",
                  "fallback": "Would make for a very strange,",
                  "italic": true,
                  "color": "dark_gray"
                },
                {
                  "translate": "text.gm4.bat_leather.2",
                  "fallback": "very tiny jacket",
                  "italic": true,
                  "color": "dark_gray"
                }
              ]
            }
          ],
          "weight": 1
        },
        {
          "type": "empty",
          "weight": 5
        }
      ]
    }
  ],
  "random_sequence": "minecraft:entities/bat",
  "__smithed__": {
    "rules": [
      {
        "type": "smithed:append",
        "target": "pools",
        "source": {
          "type": "smithed:reference",
          "path": "pools[0]"
        }
      },
      {
        "type": "smithed:append",
        "target": "pools",
        "source": {
          "type": "smithed:reference",
          "path": "pools[1]"
        }
      }
    ]
  }
}
```

::::

::::{dropdown} Replacing a vanilla item with a new / custom one

This simplified loot table is just changing `iron_ingot` to `emerald` using the `replace` rule.

```{code-block} json
:caption: This is a 'fake' loot table for the sake of a demo.
{
  "type": "minecraft:entity",
  "pools": [
    {
      "rolls": 1.0,
      "entries": [
        {
          "type": "minecraft:item",
          "name": "minecraft:iron_ingot"
        }
      ]
    }
  ],
  "random_sequence": "minecraft:entities/zombie_villager",
  "__smithed__": {
    "rules": [
      // Replace `iron_ingot` with `emerald`
      {
        "type":"replace",
        "target": "pools[0].entries[0].name",
        "source": {
          "value": "minecraft:emerald",
        }
      }
    ]
  }
}
```