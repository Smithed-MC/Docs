All actions are run `as` and `at` the interaction. You can re-target the player who interacted either by using `execute on target ...` for right click, or `execute on attacker ...` for left click. The player is also tagged with `smithed.interaction.player` if you'd prefer to use a target selector.

This library supports both right and left click interactions, with the data fields inside `data.smithed_interaction` being named `on_right_click` and `on_left_click` respectively.

Both of these support the following fields
- `command` : String representing a valid command.
- `function` : String representing a valid function [resource location](https://minecraft.wiki/w/Identifier) or `#` prefixed function tag resource location.
- `custom` : A custom string representing a custom interaction type. This will run a function tag using the interaction type (right or left click) and this custom string.

Additionally, it is supported behaviour to utilize any combination of actions at the same time. They will run in the order Custom, Function, Command.
