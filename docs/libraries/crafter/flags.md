# Advanced remove (flags)

Flags customize the way items are removed in the input while an item is crafted.


## Available flags

| Flag Name             | Behavior without flag                                    | Behavior with flag                    |
| ---------             | ----------------                                         | ------------------                    |
| `consume_buckets`     | Filled buckets are replaced by empty buckets             | Filled buckets are consumed           |
| `consume_tools`       | Tools durability decrease at every craft                 | Tools are totally consumed            |


## Example :

Flags have to be set when your recipe succeeds, for example in a shapeless recipe :

```{code-block} mcfunction
:force:
execute 
    store result score @s smithed.data 
    if entity @s[scores={smithed.data=0}] 
    if score count smithed.data matches 2
    if data storage smithed.crafter:input {recipe:<ShapelessRecipe>}
    run function ./give_result: 
        loot replace block ~ ~ ~ container.16 loot example:my_craft
        # Set the flags here, so that the water bucket is consumed, and the diamond axe is consumed too.
        data modify storage smithed.crafter:input flags append value "consume_buckets"
        data modify storage smithed.crafter:input flags append value "consume_tools"
```
Where ShapelessRecipe is :
```SNBT
[
    {id:"minecraft:water_bucket",count:1},
    {id:"minecraft:diamond_axe",count:1}
]
```


## Add a custom flag

To create your own flag, first pick up a unique name for your flag, for example `namespace:my_flag`. And add it to your recipe like the example above.

### `#smithed.crafter:event/advanced_remove`

Register a function to to this function tag, this function has the following inputs :

| Input Name                | Input Type   | Input Source             | Input Objective/Path             |
| ---                       | ---          | ---                      | ---                              |
| 'Item to process'         | entity       | @s                       | weapon.mainhand                  |
| 'Flags list'              | storage      | smithed.crafter:input    | flags                            |

And you need update the following output :

| Output Name                                   | Output Type  | Output Destination      | Output Objective/Path            |
| ---                                           | ---          | ---                     | ---                              |
| 'Success of operation'                        | score        | $temp                   | smithed.data                     |
| 'Item to replace in the crafter'              | entity       | @s                      | weapon.mainhand                  |

The default value of 'Success of operation' is 0, which by default juste remove one item. This whould be the default behavior if your flag is not present. If your flag is present and you want to change the item, set it to 1.

