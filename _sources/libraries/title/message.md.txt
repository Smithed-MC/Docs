| Input Name                  | Input Type | Input Source              | Input Objective/Path    | 
| ---                         | ---        | ---                       | ---                     | 
| 'Raw Title'                 | storage    | message.title_raw         | smithed.title:input | 
| 'JSON Title'                | storage    | message.title_json        | smithed.title:input | 
| 'Raw Subtitle'              | storage    | message.subtitle_raw      | smithed.title:input | 
| 'JSON Subtitle'             | storage    | message.subtitle_json     | smithed.title:input | 
| 'Priority Level'            | storage    | message.priority          | smithed.title:input | 
| 'Message Duration'          | storage    | message.freeze            | smithed.title:input | 



Instead of using `/title` to display the message, set up the input storage and run the following command:
```mcfunction
function #smithed.title:message
```
## Message
Messages can be set as strings or as json objects. To set a string, use `raw`, and to
set a JSON object, use `json`. Below are examples for both types of messages. 
If both fields are set, the json object is shown.

Be sure to override the data in the storage to not have a subtitle from an other datapack.

### **Example of Raw Message** 
```mcfunction
data modify storage smithed.title:input message set value {
   title_raw: 'hello world',
   subtitle_raw: 'this is a subtitle',
   priority: 'persistent'
}
```
### **Example of JSON Message**
```mcfunction
data modify storage smithed.title:input message set value {
  title_json: '{"text": "Warning!", "color": "red"}',
  subtitle_json: '{"text": "You cannot complete this action!", "color": "red"}',
  priority: 'notification'
}
```
## Priority
Priorities are set via specific strings. The list below shows the priority in descending order, 
so for example notifications will show over conditional messages.
* `override`: This is the highest priority and will always override the current message, no matter what.
* `notification`: This is for brief, non-repeating, notification type messages, 
                  such as the vanilla "You can't sleep now" message.
* `conditional`: This should be used for any message which will display constantly on a condition. 
                 A good example is displaying a compass HUD while you hold a compass or showcasing the amount of XP
                 in a nearby tank. This doesn't include any persistent messages which toggle via a config option!
* `persistent`: This is the lowest priority message and is designated for messages which always displays 
                (or displays continously if a config value is set). You can think of this as a custom ui display 
                such as in Manic or even the Vanilla Tweaks coordinate HUD which always displays.  
## Message Duration
Additionally, you can also set a `freeze` field in the storage space. 
This will deteremine how many ticks your message should be protected against other messages with the same priority. 
By default, this field is set to 20, which corresponds to 1 second.
```mcfunction
data modify storage smithed.title:message input set value {
  title_raw: 'Random Event!',
  subtitle_raw: '',
  priority: 'notification',
  freeze: 30
}
```
The freeze value has a minimum value of 0 and a maximum value of 50.