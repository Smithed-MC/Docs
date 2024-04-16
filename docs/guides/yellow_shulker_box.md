# Yellow Shulker Box
> An ancient technique empowering data pack artists since 1.14

Shulker boxes normally drop themselves containing their contents inside. In 1.14, new loot table changes have allowed us to directly drop their contents into the world. Using a standardized loot table, we can directly use commands such as `loot replace` to simulate the shulker box breaking and drop items into the player's inventory, ender chest, and more. Over the years, new techniques were introduce (e.g. item modifiers) to be able to modify items within the player inventory which are more convinent but at times, we've still relied on this table for our player item data manipulation needs.

Normally, this loot table will function 1:1 with vanilla (just dropping the shulker box containing it's contents). If the shulker box is mined with a specific item containing custom data, `{drop_contents: 1b}`, it'll drop the contents itself instead. Generally, pack creators use a shulker box stuffed aware in a force loaded chunk (often outside the max world border), where they stuff items into the shulker box and inject into the player's inventory.

```{important}
It's critical that pack creators using this loot table use the exact same table since this directly overrides the in-game table. Otherwise, behavior is not consistent due to pack order, especially if the methodology changed between tables.
```

```{hint}
You might be wondering why the loot table is *specifically* the `yellow_shulker_box` one and not the normal one. This loot table was created during the snapshot cycle for 1.14 and originally for the normal `shulker_box`. At some point, changes were needing to be made to the loot table. To avoid breaking the original loot table, the community shifted to the `yellow_shulker_box` cementing it for versions to come!
```

## General Usage

- Load the cooresponding loot table to your desired version under `data/minecraft/loot_tables/blocks/yellow_shulker_box.json`.
- Set a `yellow_shulker_box` in a known location (oftentimes located in a far forcedloaded chunk outside the max world border).
  - We'll assume `0 0 0` for now.
- Remove the items of the shulker box to ensure a clean slate.
  - `data remove block 0 0 0 Items`
- Add desired items into shulker box
  - e.g. `data modify block 0 0 0 Items append value {Slot: 0b, ...}`
- Load items into player inventory
  - `loot replace entity @s inventory.0 mine 0 0 0 stick{drop_contents:1b}`

## Changes to the loot table

Over the years, Mojang has adjusted the loot table format and conditions for this loot table to function properly. The community has upgraded this version over time. We've listed all known versions of this loot table here for reference.

```{note}
These loot tables were standardized long before Smithed and `weld` existed. Therefore, there are no `weld` rules generally created for the older tables. However, in 1.20.5, we've decided to introduce `weld` rules to increase compatibility with packs that decide to do other forms of modification to these loot tables.
```

::::{dropdown} **1.20.5** (Latest)

```{important}
1.20.5 introduced major breaking changes to items which affects this loot table. We've taken the opportunity to modernize this loot table to enable better `weld` adaptability (by separating the logic into multiple pools).

Additionally, the loot table has abandoned the `air` item since this is no longer usable by commands. Now it only expects **any** item that contains the `drop_contents` in the `custom_data` component.
```

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
