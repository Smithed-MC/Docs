
# Data Types

### Item

A modified version of vanilla SNBT. The count and Slot tags may or may not be required, depending on the situation.
#### Format :
```ts
{
    id: string
    components: dict[string, any]
    item_tag: string[]
}
```
#### Examples :
```SNBT
{
    Slot: 1b,
    id: "minecraft:crafting_table"
}
```
```SNBT
{
    Slot: 0b,
    item_tag: ["#minecraft:logs"]
}
```
```SNBT
{
    count:1,
    components:{"minecraft:custom_data":{
        smithed:{id:"airdox_:simpledrawer/drawer"}
    }}
}
```


### ShapedRecipe
A list of 3 lists of items with no count and a slot for each item. Each item as a Slot.

#### Format :
```ts
{
    0:Item[],
    1:Item[],
    2:Item[]
}
```


#### Example with a 3 lines recipe :
```SNBT
{
    0:[{Slot:0b,item_tag:["#minecraft:logs"]}, {Slot:1b,item_tag:["#minecraft:logs"]}, {Slot:2b,item_tag:["#minecraft:logs"]}],
    1:[{Slot:0b,item_tag:["#minecraft:logs"]}, {Slot:1b,id:"minecraft:crafting_table"}, {Slot:2b,item_tag:["#minecraft:logs"]}],
    2:[{Slot:0b,id:"minecraft:smooth_stone"}, {Slot:1b,id:"minecraft:smooth_stone"}, {Slot:2b,id:"minecraft:smooth_stone"}]
}
```
#### Example with a 2 lines recipe :
```SNBT
{
    0:[{Slot:0b,id:"minecraft:barrel"},{Slot:1b,id:"minecraft:iron_nugget"},{Slot:2b,id:"minecraft:air"}],
    1:[{Slot:0b,id:"minecraft:book"},{Slot:1b,item_tag:["#minecraft:planks"]},{Slot:2b,id:"minecraft:air"}]
}
```


### ShapelessRecipe
A list of items and with a count for each item and no slots.

#### Format :
```ts
Item[]
```



#### Example with a 4 items recipe :
```SNBT
[
    {id:"minecraft:barrel",count:1},
    {id:"minecraft:iron_nugget",count:1},
    {id:"minecraft:book",count:1},
    {item_tag:["#minecraft:planks"],count:1}
]
```


