---
myst:
  substitutions:
    url_start: "https://raw.githubusercontent.com/Smithed-MC/Libraries/main/smithed_libraries/packs/"
    url_end: "/pack.png"
---

# Libraries
```{admonition} 🚧 In Construction 🚧
:class: warning

Library documentation is heavily in construction. Expect hefty changes as we figure out what works best! Feel free to leave us feedback at our appropriate channels.
```

Checkout our list of standard libraries. Most of these libraries are optional, but some are required for compatibility reasons. All libraries in Smithed are MIT licensed and are free to be used outside the Smithed ecosystem.

:::{dropdown} General guide on Smithed Libraries
Smithed libraries will vary in shape and size but they do stick with the same format of invoking them. Most libraries contain a set of function tags which invoke specific behavior, we call these APIs (borrowed from the computing world). They essentially act as an interface into our library and most of them expect a bit of data to work on!

We pass data to our library functions primarily through two formats:
  - scoreboard values set on entities or fakeplayers
  - raw nbt stored directly in storage 

## Example
```mcfunction
# Theoretical `smithed.library` API
scoreboard players set @s smithed.library 20
function #smithed.library:api
# or
data modify storage smithed.library:input message set value "my cool message"
function #smithed.library:api
```

```{note}
We use function tags instead of normal functions to interface w/ our libraries for two reasons:
  - Function tags ensure that a certain API is called only once
    - If there are multiple versions of the same library in a world, it'll always call the newest versioned function!
    - This is the basis of versioning (and why we use [Lantern Load](https://github.com/LanternMC/Load))!
  - Function tags also *float* the library functions to the top of the in-game autocomplete which makes it much easier to find and test!
```

## Library Inputs

Each library may have a varying number of library functions and even more number of inputs. We use a set of tables at the top of each library's documentation to help us track what inputs mean what. Note, not all libraries have a function, some just implement behavior, such as the [Prevent Aggression](prevent-aggression.md) library!

Here's an example of one such table (from the [Damage](damage.md) library):

### `#smithed.damage:entity/apply`
| Input Name         | Input Type | Input Source | Input Objective/Path | 
| ---                | ---        | ---          | ---                  | 
| 'Amount of damage' | score      | @s           | smithed.damage       | 

This table helps us track what data we can pass to the `#smithed.damage:entity/apply` function. Here, we see we need to pass in a score which presents the amount of damage on the entity `@s` and the objective `smithed.damage`.

```mcfunction
scoreboard players set @s smithed.damage 10
function #smithed.damage:entity/apply
```


### `#smithed.actionbar:message`
| Input Name         | Input Type | Input Source     | Input Objective/Path    | 
| ---                | ---        | ---              | ---                     | 
| 'Raw Message'      | storage    | message.raw      | smithed.actionbar:input | 
| 'Priority Level'   | storage    | message.priority | smithed.actionbar:input | 

This table showcases how we describe storage-based data as here we have two fields we can pass in one `data` command!

```mcfunction
data modify storage smithed.actionbar:input message set value {raw: "my actionbar", priority: "conditional"}
function #smithed.actionbar:message
```

:::


:::{dropdown} A brief note on our `mcfunction` samples
Within these docs, there are several `mcfunction` code samples to look through. For sake of documentation, we use an expanded syntax set of mcfunction to help clarify complex structures in a simpler manner.

## Normal Commands
```mcfunction
# main
execute as @a if score @s my_obj matches 10 run summon ~ ~ ~ zombie {CustomName:'{"text": "Spooky Zombie"}', Tags: ["new"]}
execute as @e[type=zombie, tag=new] run function namespace:nested_function

# nested_function
scoreboard players set @s my_obj 10
tag @s remove new
```
These verbose commands represent two functions and have commands with several execute subcommands within them. While these commands are vanilla, they don't make particularly nice documentation as they are difficult to read and parse, even with syntax highlighting. Here's how the docs will represent these commands.

## What you'll see here
```{code-block} mcfunction
:force:
execute as @a
    if score @s my_obj matches 10
    run summon ~ ~ ~ zombie {
        CustomName: '{"text": "Spooky Zombie"}',
        Tags: ["new"]
    }

execute as @e[type=zombie, tag=new] run function namespace:nested_function:
    scoreboard players set @s my_obj 10
    tag @s remove new
```
Here, we break up long commands on multiple lines as seen in the first, long `execute` command. The second command showcases how we embed a function within the same file (the syntax might be recognizable to python users). We'll try to stick to simple, understandable, transformations of the vanilla commands to avoid large mismatches with how most people write commands!

```{note}
All examples of our custom syntax format are actually borrowed from the [bolt](https://github.com/mcbeet/bolt) project. This means our examples can be compiled into vanilla commands if using the [beet](https://github.com/mcbeet/beet) toolchain with the bolt project.

We use simple parts of bolt within our libraries' source as well!
```
:::


---

::::{grid} 1 1 2 3
:gutter: 4

:::{grid-item-card}
:link: actionbar
:link-type: doc
:img-bottom: https://raw.githubusercontent.com/Smithed-MC/Libraries/main/smithed_libraries/packs/actionbar/pack.png

Actionbar ・ v{{ actionbar_version }}
^^^

**Required** for packs that use the actionbar as it coordinates actiobar usage across data packs.
:::

:::{grid-item-card}
:link: crafter
:link-type: doc
:img-bottom: https://raw.githubusercontent.com/Smithed-MC/Libraries/main/smithed_libraries/packs/crafter/pack.png

Crafter ・ v{{ crafter_version }}
^^^

Provides a polished custom crafting block for you to use.
:::

:::{grid-item-card}
:link: custom-block
:link-type: doc
:img-bottom: https://raw.githubusercontent.com/Smithed-MC/Libraries/main/smithed_libraries/packs/custom-block/pack.png

Custom Block ・ v{{ custom_block_version }}
^^^

A customizable API to make custom blocks easier to work with.
:::

:::{grid-item-card}
:link: damage
:link-type: doc
:img-bottom: https://raw.githubusercontent.com/Smithed-MC/Libraries/main/smithed_libraries/packs/damage/pack.png

Damage ・ {{ damage_version }}
^^^

Allows you to apply score-based damage values to both players and entities
:::

:::{grid-item-card}
:link: prevent-aggression
:link-type: doc
:img-bottom: https://raw.githubusercontent.com/Smithed-MC/Libraries/main/smithed_libraries/packs/prevent-aggression/pack.png

Prevent Aggression ・ {{ prevent_aggression_version }}
^^^

Simply protects custom wandering traders from aggressive zombies
:::

:::{grid-item-card}
:link: item
:link-type: doc
:img-bottom: https://raw.githubusercontent.com/Smithed-MC/Libraries/main/smithed_libraries/packs/item/pack.png

Item ・ {{ item_version }}
^^^

*TODO*
:::

::::

---


```{card} 🌙 ・ Nightly Download
:link: https://nightly.link/Smithed-MC/Libraries/workflows/nightly-build/main/packs.zip
:link-type: url
:text-align: center

The latest bleeding edge version of the all of the libraries.
```


:::{card} {fab}`github` ・ Github
:link: https://github.com/Smithed-MC/Libraries
:link-type: url
:text-align: center

Repo where the source for all the libraries are located.
:::

```{toctree}
:hidden:
actionbar
crafter
custom-block
damage
prevent-aggression
item
```
