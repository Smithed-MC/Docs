The library comes with common code to easily run certain functions. These are recommended to reduce overhead and control the modifications with greater control. Specifically, there are the following functions: 
* `#smithed.tech_slots:modifier/trigger`
  * triggers the instant activation of location_changed enchantment effects (by changing gamemode)
* `#smithed.tech_slots:player/set_body_item`
  * sets up the body item with the proper data (without clearing existing body item data)
* `#smithed.tech_slots:storage/save_modifier`
  * saves a modifier to be restored upon death
* `#smithed.tech_slots:storage/forget_modifier`
  * removes a modifier that was saved

### `modifier/trigger`
`#smithed.tech_slots:modifier/trigger` is used to instantly activate enchantment effects. This uses a unique quirk that makes `location_changed` enchantment effect activate instantly within a function call by changing the player’s gamemode from spectator to another gamemode.

#### Example
```{code-block} mcfunction
# ignite the player on fire
item replace entity @s saddle with minecraft:stick[minecraft:equippable={slot:"saddle",equip_sound:"intentionally_empty"},minecraft:enchantments={"ns:absorption":1}]
function #smithed.tech_slots:modifier/trigger

# give player randomized absorption
item replace entity @s saddle with minecraft:stick[minecraft:equippable={slot:"saddle",equip_sound:"intentionally_empty"},minecraft:enchantments={"ns:ignite":1}]
function #smithed.tech_slots:modifier/trigger

# clean up
item replace entity @s saddle with air
```

### `player/set_body_item`
`#smithed.tech_slots:player/set_body_item` is used to initialize the body slot item. This will place an item in the slot if one doesn’t already exist and ensure it has curse of binding, curse of vanishing, and a silent equip sound. The library automatically sets the body item upon first join and respawning, but it is a good practice to set the item before running a modifier in case something removes the item.

#### Example
```{code-block} mcfunction
function #smithed.tech_slots:player/set_body_item
item modify entity @s armor.body {function:"minecraft:set_enchantments", enchantments:{"minecraft:projectile_protection":255}}
```

### `storage/save_modifier`
`#smithed.tech_slots:storage/save_modifier` is used to preserve an item modifier to be restored to the body slot when the player respawns. This effectively makes saved modifiers permanent. 

Data storage `smithed.tech_slots:data input` must be set before with a `modifier` and optionally an `id`. While not necessary, the `id` field is recommended to use as a key when removing a saved modifier defined as an inline modifier. Otherwise the entire modifier will be checked against and may lead to conflicting hits (i.e. deletion of another modifier when forgetting with the modifier itself).

#### Examples
Using a resource location (no id required since the modifier should be unique)
```{code-block} mcfunction
function #smithed.tech_slots:player/set_body_item
item modify entity @s armor.body ns:blast_prot
data modify storage smithed.tech_slots:data input set value {modifier:"ns:blast_prot"}
function #smithed.tech_slots:storage/save_modifier
```

Using an inline modifier (id added for uniqueness)
```{code-block} mcfunction
function #smithed.tech_slots:player/set_body_item
item modify entity @s armor.body {function:"minecraft:set_enchantments", enchantments:{"minecraft:blast_protection":255}}
data modify storage smithed.tech_slots:data input set value {id:"ns:blast_prot_id",modifier:{function:"minecraft:set_enchantments", enchantments:{"minecraft:blast_protection":255}}}
function #smithed.tech_slots:storage/save_modifier
```

### `storage/forget_modifier`
`#smithed.tech_slots:storage/forget_modifier` is used to remove an item modifier from the storage, stopping it from being reapplied when the player dies. Note that this doesn’t remove it from the player’s body item (hence the name “forget” instead of “remove”).

Data storage `smithed.tech_slots:data input` must be set before with a `modifier` or `id`. The entire `input` field will be checked against the storage, so it’s recommended to always overwrite the entire field (i.e. set not merge) to remove lingering data.

#### Examples
Using the id
```{code-block} mcfunction
data modify storage smithed.tech_slots:data input set value {id:"ns:blast_prot_id"}
function #smithed.tech_slots:storage/forget_modifier
```

Using the modifier itself
```{code-block} mcfunction
data modify storage smithed.tech_slots:data input set value {modifier:"ns:blast_prot"}
function #smithed.tech_slots:storage/forget_modifier
```
