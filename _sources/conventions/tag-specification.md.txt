---
myst:
  substitutions:
    summary:  "Standarized tags to specify on your custom entities and items"
    required: "On any custom entity or item you add. Also for selectors selecting arbitrary entities"
    example:  "Transforming zombies into a custom frozen zombie would need a `smithed.entity` tag"
---

# Tag Specification
{{ convention_header }}

Smithed contains a set of standardized entity and item tags to help protect and indicate custom behavior to other packs. These allow packs to understand which blocks, entities, and items are normal and which ones are "custom."

## Custom Entities
Custom entities are specified by tags on the entity itself. All custom mobs should have these tags to allow other datapacks to distinguish between a normal mob and a custom one.
```{admonition} Example
:class: note

If I add a custom mob that is a variant of the husk, it should be exempt from someone else's pack that gives all husks new armor.
```

You should use these tags by either summoning it with the entity or applying it afterwards.
```mcfunction
# We could apply this data now or later, which ever you prefer
summon zombie ~ ~ ~ {CustomName: '"My Juicy Zombie"', Health:200.0f, Tags: ["smithed.entity"]}
```
You should *respect* these tags by excluding it from certain `@e` calls.
```mcfunction
# Note, we only convert zombies to juicy zombies if they aren't a `smithed.entity`
execute as @e[type=random, limit=1, type=zombie, tag=!smithed.entity]
  run data merge entity @s {CustomName: '"My Juicy Zombie"', Health: 200.0f}
```

When and where you decide to exclude a tag is based off of the specific tag described below:

### `smithed.entity`
> This tag functions as a separator between vanilla entities and base entities of custom mobs. 

Entities with this tag should be exempt to: 
  - Changes specific to the vanilla entity they are using as a base. 

```{admonition} Example
:class: note

Mobs based on the wandering trader, such as TCC’s iceologer, should have `smithed.entity`, and selectors to give the vanilla wandering trader new trades should have `tag=!smithed.entity`.
```

Entities with this tag should not be exempt to: 
  - Damage from commands 
  - Having effects applied via command 
  - Basically anything you can do to a bat in survival mode without operator permissions.

### `smithed.strict`
> Functions as a modifier for `smithed.entity`.
```{admonition} Warning
:class: warning

Including this tag on your entity **requires** you to include `smithed.entity`.
```

This is intended for boss entities or invisible technical marker entities.

Entities with this tag should be exempt to:
  - Changes to position, rotation
   - Basically everything listed under “not exempt” under `smithed.entity`

Entities with this tag should not be exempt to:
  - Damage from commands
  - Note that damage from commands should be ignored if the entity has `{Invulnerable:1b}`

## Custom Blocks
Custom blocks are specified by tags on an entity inside the block. All custom blocks should have an entity with this tag to allow other datapacks to distinguish between a normal block and a custom one.
```{admonition} Example
:class: note

If I add a custom crafter that uses a barrel, it should be exempt from someone else's pack that allows for pushable nbt blocks.
```
You should use the tag by summoning it with the entity when the block is placed.
```mcfunction
# We could apply this data now or later, which ever you prefer
setblock ~ ~ ~ obsidian
summon marker ~ ~ ~  
  {CustomName: '"My Custom Block"', Tags: ["smithed.block","smithed.entity","smithed.strict"]}
```
You should *respect* these tags by checking for the entity during certain block checks.
```mcfunction
# Note, we only convert obsidian to deepslate if the blocks don't have a `smithed.block` inside
execute at @s align xyz positioned ~0.5 ~0.5 ~0.5 if block ~ ~ ~ obsidian 
  unless entity @e[tag=smithed.block,distance=..0.5] run 
  setblock ~ ~ ~ deepslate
```
### `smithed.block`
> This tag functions as a separator between vanilla blocks and base blocks of custom blocks. 
Entities with this tag are to be used as custom block markers. 
```{admonition} Example
:class: note

Armor stands inside of a custom crafter should be marked with this tag.
```

## Custom Items
Custom items are specified by tags on in custom item nbt. All custom items should have these tags to allow other datapacks to distinguish between a normal item and a custom one.
```{admonition} Example
:class: note

If I add a custom item that is a clock, it should be exempt from someone else's pack that allows for clocks to change the time of day.
```

You should use these tags when creating the item.
```mcfunction
# We could apply this data now or later, which ever you prefer
give @s coal{display: {Name: '"Fossil Fuel"'}, smithed: {ignore: {functionality: 1b}}}
```
You should *respect* these tags by excluding it from certain item checks.
```mcfunction
# Note, we only apply effects to players holding coal if the item doesn't have the ignore flag
effect give @a[nbt={SelectedItem: {id: "minecraft:coal"}}, nbt=!{SelectedItem: {tag: {smithed: {ignore: {functionality: 1b}}}}}] weakness 10 0
```
### `{smithed:{ignore:{functionality:1b}}}`
> This tag should be used to mark an item that shouldn’t act like the base item for custom abilities.

Items with this tag should be exempt to: 
  - Gameplay specific changes to the vanilla item they are using as a base. 
```{admonition} Example
:class: note

Custom "poison apples" should use `{smithed:{ignore:{functionality:1b}}}` and food balance modules shouldn't count apples with `{smithed:{ignore:{functionality:1b}}}` as having eaten an apple.
```
### `{smithed:{ignore:{crafting:1b}}}`
> This tag should be used to mark an item that shouldn’t act like the base item as a crafting ingredient.

Items with this tag should be exempt to: 
  - Crafting with the vanilla item they are using as a base. 
```{admonition} Example
:class: note

Custom chestplates should use `{smithed:{ignore:{crafting:1b}}}` and custom crafting recipes shouldn't consider chestplates with `{smithed:{ignore:{crafting:1b}}}` as a valid chestplate item.
```
