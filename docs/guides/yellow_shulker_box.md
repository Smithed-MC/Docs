# Yellow Shulker Box
> An ancient technique empowering data pack artists since 1.14

Shulker boxes normally drop themselves containing their contents inside. In 1.14, new loot table changes have allowed us to directly drop their contents. Using a standardized loot table, we can directly use commands such as `loot replace` to simulate the shulker box breaking and drop items into the player's inventory, ender chest, and more. Over the years, new techniques were introduce (e.g. item modifiers) to be able to modify items within the player inventory which are more convinent but at times, we've still relied on this table for our player item data manipulation needs.

This loot table is setup to normally drop the shulker box under normal game conditions but to drop it's contents if mined with a specific item `minecraft:air{drop_contents: 1b}` (and since `air` can't have nbt, this item is impossible to obtain even with commands). Generally, pack creators use a shulker box stuffed aware in a force loaded chunk (often outside the max world border), where they stuff items into the shulker box and inject into the player's inventory.

```{important}
It's critical that pack creators using this loot table use the exact same table since this directly overrides the in-game table. Otherwise, behavior is not consistent due to pack order, especially if the methodology changed between tables.
```

```{hint}
You might be wondering why the loot table is *specifically* the `yellow_shulker_box` one and not the normal one. This loot table was created during the snapshot cycle for 1.14 and originally for the normal `shulker_box`. At some point, changes were needing to be made to the loot table. To avoid breaking the original loot table, the community shifted to the `yellow_shulker_box` cementing it for versions to come!
```

## Changes to the loot table

Over the years, Mojang has adjusted the loot table format and conditions for this loot table to function properly. The community has upgraded this version over time. We've listed all known versions of this loot table here for reference.

```{note}
These loot tables were standardized long before Smithed and `weld` existed. Therefore, there are no `weld` rules generally created for the older tables. However, in 1.20.5, we've decided to introduce `weld` rules to increase compatibility with packs that decide to do other forms of modification to these loot tables.
```

::::{dropdown} **1.20.5** (Latest)

```{literalinclude} tables/1.20.5.json
:language: json
```

::::

::::{dropdown} 1.18-1.20.4

```{literalinclude} tables/1.18-1.20.4.json
:language: json
```

::::

::::{dropdown} 1.17

```{literalinclude} tables/1.17.json
:language: json
```

::::

::::{dropdown} 1.14-1.16

```{literalinclude} tables/1.14-1.16.json
:language: json
```

::::

## Credits

This page is merely a reference guide to one of the oldest standards that the community has settled on. Here are an unordered lists of community members who have contributed in some effect to this standard.

- Lue
- Ael
- vdvman1
- Misode
- rx97
- BPR

[Link to the original FAQ post from the MCC Discord](https://discord.com/channels/154777837382008833/157097006500806656/655840284189392902)
