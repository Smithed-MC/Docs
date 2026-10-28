Example usage:
```{code-block} mcfunction
summon minecraft:interaction ~ ~ ~ { \
  Tags: ["smithed.interaction"], \
  data: { \
    smithed_interaction: { \
      on_right_click: { \
        custom: "sit", \
        height: 0.5 \
      } \
    } \
  } \
}
```

With this custom type there is an optional `height` field like above. This represents the height above the origin of the interaction that the player will sit. When this field is not present, it will default to half of the interactions hit box height.

Technically, this is acheived by summoning an empty item display for the player to sit on. This is done due to players taking their vehicles with them when they log out and we dont want players to take the interaction itself with them.

A consequence of the player riding a detached item display is that moving the interaction does **not** move the player sitting on it. For this use-case, you can set this custom height field to `"follow"`, which will have the player sit exactly at the interactions origin, but have the item display follow the interaction.
