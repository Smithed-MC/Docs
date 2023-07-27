
# Function Tag

### `#smithed.crafter:event/recipes`
A function tag to implement shaped recipes. Register your recipes in the function tag like this:

```mcfunction
execute 
    store result score @s smithed.data 
    if entity @s[scores={smithed.data=0}] 
    if data storage smithed.crafter:input recipe{ShapedRecipe} 
    run loot replace block ~ ~ ~ container.16 loot example:my_craft
```

Example (Heavy Workbench):

```mcfunction
execute 
    store result score @s smithed.data 
    if entity @s[scores={smithed.data=0}] 
    if data storage smithed.crafter:input recipe{ShapedRecipe} 
    run loot replace block ~ ~ ~ container.16 loot smithed.crafter:blocks/table
```
Where ShapedRecipe is [this](https://wiki.smithed.dev/libraries/crafter/data_types/#example-with-a-3-lines-recipe)


Example : 
```mcfunction
execute 
    store result score @s smithed.data 
    if entity @s[scores={smithed.data=0}] 
    if data storage smithed.crafter:input recipe{ShapedRecipe}
    if data storage smithed.crafter:main root.temp{crafting_input:{2:[]}} 
    run loot replace block ~ ~ ~ container.16 loot simpledrawer:impl/items/guide
```
Where ShapedRecipe is [this](https://wiki.smithed.dev/libraries/crafter/data_types/#example-with-a-2-lines-recipe)

### `#smithed.crafter:event/shapeless_recipes`
A function tag to implement shapeless recipes.
