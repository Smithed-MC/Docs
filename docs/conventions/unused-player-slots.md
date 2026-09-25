---
myst:
  substitutions:
    summary: "Standardized method to modify the player's body and saddle slots"
    required: "When using the player's body or saddle slots for custom behavior, or storing/modifying player inventories"
    example: "Adding a persistent thorns effect to the player"
---

# {{new_bdg}} Unused Player Slots
{{ convention_header }}

As of 1.21.5, body and saddle slots were added to all mobs, including players. These are typically used for horse armor and saddles, but with the introduction of these unused equipment slots to the player, we have newfound access to apply modifications to players, for example, applying enchantments to players without modifying existing armor pieces.

When modifying these slots, it's important to do so in a way that does not delete other modifications made by other datapacks. For ease of use, the saddle slot and body slot serve different purposes under this standard: the saddle slot is for instantaneous modifications and the body slot is for persistent modifications.

Items placed in the body and saddle slots should not be dropped upon player death. Datapacks that store player inventory/equipment should ignore the saddle and body slots, and datapacks should not allow for unequipping or swapping the items in these slots. I.e. datapacks should not use these slots for non-technical purposes (e.g. treating the body slot as a backpack slot that can be filled with a backpack item). 

## Saddle Slot
The saddle slot should be used to apply instantaneous, one-time modifications. Specifically, the saddle slot should be used when an item can be removed from a player on the same tick it is equipped. By definition, this means the saddle slot should never be equipped with an item that is meant to persist on the player. Treat the saddle slot as temporary and volatile. The slot should be cleared in the same tick it is equipped, so items can be equippable in the saddle slot (e.g. for right-click instant activation). 

To ensure the item is not dropped upon player death, the item should be cleared within the same tick.

## Body Slot
The body slot should be used to apply semi-persistent, long-lasting modifications. Specifically, the body slot should be used when item data needs to exist on a player for more than 1 tick. Unlike the saddle slot, the item in the body slot should be treated as permanent. Instead, data should be added to whatever item is in the body slot (e.g. via item modifiers), adding an item to the slot if one does not already exist. Datapacks following this convention should not under any circumstances delete the item in the body slot.

When placing an item in the body slot, the equippable component should set the equip sound to be silent: `{slot:"body",equip_sound:"intentionally_empty"}`, and the Curse of Vanishing and Curse of Binding enchantments should be applied. Additionally, the `{smithed:{ignore:{everything:1b}}}` [custom data](/conventions/tag-specification) should be set. These components are set to ensure the items act as purely technical placeholders and isn't dropped upon death.

## Helper Library
In practice, the usage of the body slot is a little more complicated when considering some modifications may need to be kept upon death (e.g. permanently making certain players immune to arrows for an RPG datapack with classes). This is an important feature for packs that want to use this slot for fully permanent effects. The optional library [Smithed Tech Slots](/libraries/tech-slots) is available to facilitate this.

Along with the fully persistent helper functions, the library also supplies helper functions for applying instantaneous modifiers with the saddle slot, and semi-persistent (i.e. removed upon death) modifiers with the body slot.

## Examples

::::{dropdown} Applying an instantaneous modification

Below shows example code to apply an item to the saddle slot for an instananeous "one-shot" effect. Note that this uses a quirk in which setting the player’s gamemode to spectator then to another gamemode will immediately apply an enchantment with the minecraft:location_changed effect.

```{code-block} json
:caption: "ns/enchantment/ignite.json"
{
  "description": "",
  "supported_items": "minecraft:saddle",
  "weight": 1,
  "max_level": 1,
  "min_cost": {
    "base": 0,
    "per_level_above_first": 0
  },
  "max_cost": {
    "base": 0,
    "per_level_above_first": 0
  },
  "anvil_cost": 0,
  "slots": [
    "saddle"
  ],
  "effects": {
    "minecraft:location_changed": [
      {
        "effect": {
          "type": "minecraft:ignite",
          "duration": 2
        }
      }
    ]
  }
}
```

```{code-block} json
:caption: "ns/enchantment/absorption.json"
{
  "description": "",
  "supported_items": "minecraft:saddle",
  "weight": 1,
  "max_level": 1,
  "min_cost": {
    "base": 0,
    "per_level_above_first": 0
  },
  "max_cost": {
    "base": 0,
    "per_level_above_first": 0
  },
  "anvil_cost": 0,
  "slots": [
    "saddle"
  ],
  "effects": {
    "minecraft:location_changed": [
      {
        "effect": {
          "type": "minecraft:apply_mob_effect",
          "to_apply": "minecraft:absorption",
          "min_duration": 10,
          "max_duration": 30,
          "min_amplifier": 0,
          "max_amplifier": 1
        }
      }
    ]
  }
}
```

```{code-block} mcfunction
:caption: "ns/function/apply_saddle.mcfunction"
# ignite the player on fire
item replace entity @s saddle with minecraft:stick[minecraft:equippable={slot:"saddle",equip_sound:"intentionally_empty"},minecraft:enchantments={"ns:ignite":1}]
gamemode spectator @s
gamemode survival @s

# apply randomized absorption
item replace entity @s saddle with minecraft:stick[minecraft:equippable={slot:"saddle",equip_sound:"intentionally_empty"},minecraft:enchantments={"ns:absorption":1}]
gamemode spectator @s
gamemode survival @s

# clean up
item replace entity @s saddle with air
```

```{note}
In a real implementation, the original gamemode should be checked before performing the spectator gamemode swap so the original gamemode can be restored.
```

::::

::::{dropdown} Applying a semi-persistent modification

Below shows example code to apply an modification to the body slot.

```{note}
By default, this item and thus its modifiers would be deleted upon death.
```

```{code-block} mcfunction
:caption: "ns/function/apply_body.mcfunction"
# put an item in the body slot if not already present
execute unless items entity @s armor.body * run item replace entity @s armor.body with minecraft:poisonous_potato[!minecraft:consumable,minecraft:equippable= {slot:"body",equip_sound:"intentionally_empty"}, enchantments={"minecraft:vanishing_curse":1,"minecraft:binding_curse":1}, minecraft:custom_data={smithed:{ignore:{everything:1b}}}]

# forcefully add vanishing and binding curses if it doesn’t already exist
execute unless items entity @s armor.body *[minecraft:enchantments~[{enchantments:["binding_curse","vanishing_curse"]}]] run item modify entity @s armor.body {function:"minecraft:set_enchantments", enchantments:{"minecraft:binding_curse":1,"minecraft:vanishing_curse":1}}

# apply projectile protection to the player
item modify entity @s armor.body {function:"minecraft:set_enchantments", enchantments:{"minecraft:projectile_protection":255}}
```

```{note}
There are ways to force the equip sound to be silent, but it is more complicated than simply setting the equippable component due to the requirement of preserving other data in the equippable component. The sound does not technically break convention, so this is left as an exercise to the reader.
```

::::
