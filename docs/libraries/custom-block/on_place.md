

When placing a block with a custom tag, it will call the function tag `#smithed.custom_block:event/on_place`.

This library tracks the full block data of the placed block in data storage `smithed.custom_block:main blockApi`.

| Input Name         | Input Type   | Input Source             | Input Objective/Path          | 
| ---                | ---          | ---                      | ---                           | 
| 'Block unique id'  | storage      |  blockApi.id             | smithed.custom_block:main     |
| 'Block full data'  | storage      |  blockApi.__data         | smithed.custom_block:main     |



### Example Implementation :
`function: example:give_custom_block`
```{code-block} mcfunction
:force:
give @s barrel[
    custom_name='{"translate":"My Custom Block","color":"white","italic":false}',
    container=[{slot:0,item:{id:"minecraft:stone",count:1b,components:{"minecraft:custom_data":{
        smithed:{block:{id:"example:my_custom_block"}}
    }}}}]]
# All available block are listed in the block tag #smithed.custom_block:placeable
```



`function: example:on_place`
```{code-block} mcfunction
:force:
# check if this is my custom block
execute 
    if data storage smithed.custom_block:main {blockApi:{id:"example:my_custom_block"}}
    run function example:my_custom_block/place:
        # Handle the custom block placement (the command is executed at the block location, and as the player)
        # You have to remove the first item in the block entity tag (if the block is a container)
        # And adding an entity at the block location

        # Example:
        execute summon marker run function example:my_custom_block/place_entity
        data remove block ~ ~ ~ Items[{Slot:0b}]
```
`tag: #smithed.custom_block:event/on_place`
```json
{
  "values": [
      "example:on_place"
  ]    
}
```

