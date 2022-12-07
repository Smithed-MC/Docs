## Shaped Recipes
All shaped recipes follow a general format

```mcfunction
execute store result score @s smithed.data
    if entity @s[scores={smithed.data=0}]
    if data storage smithed.crafter:input root.temp{
        crafting_input: {
            0: [<stuff>], 1: [<stuff>], 2: [<stuff>]
        }
    }
    run loot replace block ~ ~ ~ container.16 loot my_loot_table:here
# or using /item
execute store result score @s smithed.data if entity @s[scores={smithed.data=0}] if data storage smithed.crafter:input root.temp{crafting_input:{0:[<stuff>],1:[<stuff>],2:[<stuff>]}} run item replace block ~ ~ ~ container.16 with stick{item_nbt:1b}
```

To create your own recipe with the generator:
 Go to  
Fill in your ingredients and output
Follow step 1 from below to get it working in game
To create your own recipe manually:
1. Create a new function and add your command
@tag smithed:crafter/events/recipes
execute store result score @s smd.data if entity @s[scores={smd.data=0}] if data storage smd:crafter root.temp{crafting_input:<stuff from below>} run loot replace block ~ ~ ~ container.16 loot <loot>
2. Add your nbt check
The general format is as follow
{
    0: [
        {id:"item",Slot:0b},{id:"item",Slot:1b},{id:"item",Slot:2b}
    ],
    1: [
        {id:"item",Slot:0b},{id:"item",Slot:1b},{id:"item",Slot:2b}
    ],
    2: [
        {id:"item",Slot:0b},{id:"item",Slot:1b},{id:"item",Slot:2b}
    ]
}
# Condensed
{0:[{id:"item",Slot:0b},{id:"item",Slot:1b},{id:"item",Slot:2b}],1:[{id:"item",Slot:0b},{id:"item",Slot:1b},{id:"item",Slot:2b}],2: [{id:"item",Slot:0b},{id:"item",Slot:1b},{id:"item",Slot:2b}]}
If you want a row to be completely empty, instead of putting it as all air or empty above, do the following:
execute store result score @s smd.data if entity @s[scores={smd.data=0}] if data storage smd:crafter root.temp{crafting_input:<stuff from above>} if data storage smd:crafter root.temp{crafting_input:{2:[]}} run loot replace block ~ ~ ~ container.16 loot <loot>
​