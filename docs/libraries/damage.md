# Damage
> This library implements complex damage calculation math in order to emulate applying damage to both players and entities

::::{grid} 2

:::{grid-item}
```{button-link} https://api.smithed.dev/download?pack=smithed:damage
:color: primary
:outline:
:expand:
{octicon}`download;1em` Download
```
:::

:::{grid-item}
```{button-link} https://github.com/Smithed-MC/Libraries/tree/main/smithed_libraries/packs/damage/
:color: primary
:outline:
:expand:
{octicon}`mark-github;1em` Source
```
:::

::::


| Library Function                          | Description 
| ---                                       | ---         
| `#smithed.damage:entity/apply`            | Applies damage from the score `@s smithed.damage` directly to the hp of the entity of `@s`
| `#smithed.damage:entity/apply/armor`      | Does the same as `entity/apply` except respects armor values
| `#smithed.damage:entity/apply/explosion`  | Does the same as `entity/apply/armor` except respects `Blast Protection` enchantments
| `#smithed.damage:entity/apply/projectile` | Does the same as `entity/apply/armor` except respects `Projectil Protection` enchantments

## `#smithed.damage:entity/apply*`
> Note, the interface for all of the functions above are the same

```{include} damage/entity/apply.md
```

## Custom Death Messages Events
```{include} damage/player/damage_messages.md
```


## Damage Events
```{include} damage/player/damage_events.md
```
