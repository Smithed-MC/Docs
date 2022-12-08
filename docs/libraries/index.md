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
```mcfunction
execute as @a
    if score @s my_obj matches 10
    run summon ~ ~ ~ zombie {
        CustomName: '{"text": "Spooky Zombie"}',
        Tags: ["new"]
    }

execute as @e[type=zombie, tag=new] run function namespace:nested_function
    scoreboard players set @s my_obj 10
    tag @s remove new
```
Here, we break up long commands on multiple lines as seen in the first, long `execute` command. The second command showcases how we embed a function within the same file (the syntax might be recognizable to python users). We'll try to stick to simple, understandable, transformations of the vanilla commands to avoid large mismatches with how most people write commands!

```{note}
All examples of our custom syntax format are actually borrowed from the [bolt](https://github.com/mcbeet/bolt) project. This means our examples can be compiled into vanilla commands if using the [beet](https://github.com/mcbeet/beet) toolchain with the bolt project.

We use simple aspects of bolt within our libraries' source as well!
```
:::


---

::::{grid} 1 1 2 3
:gutter: 4

```{grid-item-card}
:link: actionbar
:link-type: doc
:img-bottom: https://raw.githubusercontent.com/Smithed-MC/Libraries/main/smithed_libraries/packs/actionbar/pack.png

Actionbar
^^^

**Required** for packs that use the actionbar as it coordinates actiobar usage across data packs.
```

```{grid-item-card}
:link: crafter
:link-type: doc
:img-bottom: https://raw.githubusercontent.com/Smithed-MC/Libraries/main/smithed_libraries/packs/crafter/pack.png

Crafter
^^^

Provides a polished custom crafting block for you to use.
```

```{grid-item-card}
:link: custom-block
:link-type: doc
:img-bottom: https://raw.githubusercontent.com/Smithed-MC/Libraries/main/smithed_libraries/packs/custom-block/pack.png

Custom Block
^^^

A customizable API to make custom blocks easier to work with.
```

```{grid-item-card}
:link: damage
:link-type: doc
:img-bottom: https://raw.githubusercontent.com/Smithed-MC/Libraries/main/smithed_libraries/packs/damage/pack.png

Damage
^^^

Allows you to apply score-based damage values to both players and entities
```

```{grid-item-card}
:link: prevent-aggression
:link-type: doc
:img-bottom: https://raw.githubusercontent.com/Smithed-MC/Libraries/main/smithed_libraries/packs/prevent-aggression/pack.png

Prevent Aggression
^^^

Simply protects custom wandering traders from aggressive zombies
```

```{grid-item-card}
:link: item
:link-type: doc
:img-bottom: https://raw.githubusercontent.com/Smithed-MC/Libraries/main/smithed_libraries/packs/item/pack.png

Item
^^^

*TODO*
```

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
