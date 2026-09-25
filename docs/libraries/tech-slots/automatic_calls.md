The library also comes with an automatic way to trigger modifiers. These are provided for ease of use, but have greater overhead and less control than the manual calls. Specifically, there are the following functions:
* `#smithed.tech_slots:modifier/set_instant`
Applies the modifier to the player and instantly applies it
* `#smithed.tech_slots:modifier/set_constant`
Applies the modifier to the player until the player dies
* `#smithed.tech_slots:modifier/set_permanent`
Applies the modifier to the player until it is forgotten and the player dies

```{note}
There is no automatic call for removing a permanent item modifier. This can be achieved by using `#smithed.tech_slots:modifier/set_constant` to apply a cancelling modifier to the body slot, and then using `#smithed.tech_slots:storage/forget_modifier` to remove it from the registry.
```

All of these calls have the same use pattern: set the input data, and run the function tag. Data storage `smithed.tech_slots:data input` must be set before with a `modifier` and optionally an `id`. While not necessary, the `id` field is recommended when using the `#smithed.tech_slots:modifier/set_permanent` function as a key when removing the modifier defined as an inline modifier. Otherwise the entire modifier will be checked against and may lead to conflicting hits (i.e. deletion of another modifier when forgetting with the modifier itself). 

### Example
```mcfunction
data modify storage smithed.tech_slots:data input set value {id:"ns:blast_prot_id", modifier:{function:"minecraft:set_enchantments", enchantments:{"minecraft:blast_protection":255}}}
function #smithed.tech_slots:modifier/set_permanent
```

```{note}
This example applies to each automatic call by just changing the function call to one of the other automatic calls.
```
