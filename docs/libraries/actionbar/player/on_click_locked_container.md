Locked containers will send an event before allowing the vanilla message to show
You can add locked container events by adding your function to the tag `#smithed.actionbar:event/player/on_click_locked_container`.  
This library tracks the full block data of the clicked locked container in data storage `smithed.actionbar:data block`.

### Example Implementation
`function: example:clicked_locked_container`
```mcfunction
# ignore blocks with the a specific lock
execute if data storage smithed.actionbar:data block{Lock:"Ignore Me!"} run data remove storage smithed.actionbar:input message
# alternate way to ignore blocks (this time with a custom name)
execute if data storage smithed.actionbar:data block{CustomName:'{"text":"Custom Block"}'} run scoreboard players set $locked smithed.actionbar.temp 0
# send a custom lock message (in this example to send a reason that it's locked)
execute if data storage smithed.actionbar:data block{CustomName:'{"text":"Custom Block"}'} run data modify storage smithed.actionbar:input message set value {json:'{"text":"Someone is currently using this block!"}',priority:'notification',freeze:20}
```
`tag: #smithed.actionbar:event/player/on_click_locked_container`
```json
{
  "values": [
      "example:clicked_locked_container"
  ]    
}
```