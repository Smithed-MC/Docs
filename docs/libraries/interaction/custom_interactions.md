Custom interactions exist as a shortcut for custom functionality without having to list out a full command or function location when summoning the interaction.

Built into this library is the `sit` custom interaction type, which will have the player sit "on" the interaction. (More information on this below)

Custom interaction types are tied to the interaction type (right or left click). For instance, the `sit` custom interaction is only supported for `on_right_click`.

These custom types will run a function tag using the interaction type and the custom string. For example, `custom: "sit"` runs the function tag `#smithed.interaction:event/on_right_click/custom/sit`, located at `data/smithed.interaction/tags/function/event/on_right_click/custom/sit.json`. 

Read up on function tags on the [Minecraft Wiki](https://minecraft.wiki/w/Function_tag_(Java_Edition)), if you're new to using them in this way.
