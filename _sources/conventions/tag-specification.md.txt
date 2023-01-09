# Tag Specification
Smithed contains a set of standardized entity tags to help protect and indicate custom entity behavior to other packs. These allow packs to understand which entities are normal and which entities are "custom".

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

## `smithed.entity`
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

## `smithed.strict`
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

## `smithed.block`
Entities with this tag are to be used as block markers. 
```{admonition} Example
:class: note

Armor stands inside of a custom crafter should be marked with this tag.
```
