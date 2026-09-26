# <span class="bdg bdg-primary-line">v1</span> Custom Merging Rules

Smithed defines a set of custom merging rules that can be applied to *any* JSON file by defining a custom field, `__smithed__`.

## Motivation

When defining resources for the vanilla namespace, pack creators have little choice than to override the vanilla file, manually injecting their intended changes. This means if multiple creators target the same file, the game will take the latest loaded pack which overrides the table, nullifying any changes other packs might have changes. This is *especially* apparent when dealing with loot tables since it's quite common to need to add new drops to mobs like zombies, etc.

Weld provides a solution to allow packs to *specify* custom behavior when targetting specific JSON files allowing multiple packs to inject their custom json without overriding each other.

## Top-level fields

At the base of `__smithed__`, you can define the following fields.

<span class="bdg bdg-info-line">id</span> <code class="sd-text-secondary">str (defined by `pack.mcmeta`)</code> - **Should not be *manually* defined** since this is automatically set.

<span class="bdg bdg-info-line">version</span> <code class="sd-text-secondary">int (*1*)</code> - The version of the `__smithed__` data model. This is automatically specifed to the latest version. You only need to specify this if you need your pack to load an older version of these models.

<span class="bdg bdg-info-line">override</span> <code class="sd-text-secondary">bool (*false*)</code> - If true, the json file defining this will **override** other pack's json files with the same namespace. This should **only** be used for Smithed bundles as it defines destructive behavior (completely skipping the merging process).

<span class="bdg bdg-info-line">rules</span> <code class="sd-text-secondary">list[[Rule](rule.md)] (*empty*)</code> - A list of rules that define the custom merging behavior. This is the main field you define for your custom merging rules.

<span class="bdg bdg-info-line">priority</span> <code class="sd-text-secondary">[Priority](priority.md) (*empty*)</code> - A priority definition which specifies the ordering of when this file's merging rules should activate compared to other packs being welded.

!!! tip
    The Smithed data model has a ton of reasonable defaults so there's no need to overwelm youself with every fields' functionality. The abundunce is here for flexibility *when you need it*!

## Other

Additionally, there are some extra details you can include in the [pack.mcmeta](mcmeta.md) of your project.

---

