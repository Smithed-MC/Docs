# Damage (v{{ damage_version }})

!!! warning
    This library is deprecated as of Minecraft 1.20 with the introduction of the `/damage` command.

> This library implements complex damage calculation math in order to emulate applying damage to both players and entities

<div class="grid" markdown>


<div class="grid-item" markdown>

[:octicons-download-16: Download](https://api.smithed.dev/v2/download?pack=damage){ .md-button }

</div>

<div class="grid-item" markdown>

[:octicons-mark-github-16: Source](https://github.com/Smithed-MC/Libraries/tree/main/smithed_libraries/packs/damage/){ .md-button }

</div>


</div>


| Library Function                          | Description 
| ---                                       | ---         
| `#smithed.damage:entity/apply`            | Applies damage from the score `@s smithed.damage` directly to the hp of the entity of `@s`
| `#smithed.damage:entity/apply/armor`      | Does the same as `entity/apply` except respects armor values
| `#smithed.damage:entity/apply/explosion`  | Does the same as `entity/apply/armor` except respects `Blast Protection` enchantments
| `#smithed.damage:entity/apply/projectile` | Does the same as `entity/apply/armor` except respects `Projectil Protection` enchantments

## `#smithed.damage:entity/apply*`
> Note, the interface for all of the functions above are the same

--8<-- "libraries/damage/entity/apply.md"

## Custom Death Messages Events
--8<-- "libraries/damage/player/damage_messages.md"


## Damage Events
--8<-- "libraries/damage/player/damage_events.md"
