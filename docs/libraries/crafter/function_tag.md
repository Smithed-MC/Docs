
# Function Tag

## `#smithed.crafter:event/recipes`
A function tag to implement shaped recipes. 

| Input Name                | Input Type   | Input Source             | Input Objective/Path             | 
| ---                       | ---          | ---                      | ---                              | 
| 'Success of the craft'    | score        | @s                       | smithed.data                     | 
| 'Crafting recipe'         | storage      | recipe                   | smithed.crafter:input            |


### Format :
The function tag will be called, implement your recipes like this

```{code-block} mcfunction
:force:
execute 
    # Success of the craft (for performance)
    store result score @s smithed.data 
    if entity @s[scores={smithed.data=0}]
    # The actual recipe check 
    if data storage smithed.crafter:input recipe<ShapedRecipe>
    # The result of the recipe
    run loot replace block ~ ~ ~ container.16 loot example:my_craft
```


### Examples :

#### Heavy Workbench:

```{code-block} mcfunction
:force:
execute 
    store result score @s smithed.data 
    if entity @s[scores={smithed.data=0}] 
    if data storage smithed.crafter:input recipe<ShapedRecipe>
    run loot replace block ~ ~ ~ container.16 loot smithed.crafter:blocks/table
```
Where ShapedRecipe is [this](https://wiki.smithed.dev/libraries/crafter/data_types/#example-with-a-3-lines-recipe)


#### Guide : 
```{code-block} mcfunction
:force:
execute 
    store result score @s smithed.data 
    if entity @s[scores={smithed.data=0}] 
    if data storage smithed.crafter:input recipe<ShapedRecipe>
    if data storage smithed.crafter:main root.temp{crafting_input:{2:[]}} 
    run loot replace block ~ ~ ~ container.16 loot simpledrawer:impl/items/guide
```
Where ShapedRecipe is [this](https://wiki.smithed.dev/libraries/crafter/data_types/#example-with-a-2-lines-recipe)

## `#smithed.crafter:event/shapeless_recipes`
A function tag to implement shapeless recipes. 

| Input Name                            | Input Type   | Input Source             | Input Objective/Path             | 
| ---                                   | ---          | ---                      | ---                              | 
| 'Success of the craft'                | score        | @s                       | smithed.data                     | 
| 'The number of items in the craft'    | score        | count                    | smithed.data                     | 
| 'Crafting recipe'                     | storage      | recipe                   | smithed.crafter:input            |


### Format :
The function tag will be called, implement your recipes like this
```{code-block} mcfunction
:force:
execute 
    # Success of the craft (for performance)
    store result score @s smithed.data 
    if entity @s[scores={smithed.data=0}] 
    # The count check
    if score count smithed.data matches ItemCount
    # The actual recipe check
    if data storage smithed.crafter:input {recipe:<ShapelessRecipe>}
    # The result of the recipe
    run loot replace block ~ ~ ~ container.16 loot example:my_craft_shapeless
```


### Examples :

#### Flint and Copper :

```{code-block} mcfunction
:force:
execute 
    store result score @s smithed.data 
    if entity @s[scores={smithed.data=0}] 
    if score count smithed.data matches 2
    if data storage smithed.crafter:input {recipe:<ShapelessRecipe>}
    run loot replace block ~ ~ ~ container.16 loot example:flint_and_copper
```
Where ShapelessRecipe is :
```SNBT
[
    {id:"minecraft:copper_ingot",count:1},
    {id:"minecraft:flint",count:1}
]
```


## Advanced uses :
A list of advanced uses of the crafter library.

- [Flags](https://github.com/Smithed-MC/Libraries/blob/main/smithed_libraries/packs/crafter/data/smithed.crafter/functions/impl/block/table/crafting/output/clear_input/advanced.mcfunction) To register custom flags when crafting to use tools, empty buckets, etc...
- [Item Tags](https://github.com/Smithed-MC/Libraries/blob/main/smithed_libraries/packs/crafter/data/smithed.crafter/functions/impl/block/table/crafting/input/query_tags.mcfunction) To register custom items tags
- [Custom crafting table](https://github.com/Smithed-MC/Libraries/blob/main/smithed_libraries/packs/crafter/data/smithed.crafter/functions/impl/block/table/break/drop_item.mcfunction) To register your own crafting table.


