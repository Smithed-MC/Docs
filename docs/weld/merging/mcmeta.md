# `pack.mcmeta``

In the `pack.mcmeta`, you can define a `__smithed__` field.

{bdg-info-line}`override` <code class="sd-text-secondary">bool (*false*)</code> - If true, every json file defined in this pack will **override** other pack's json files with the same namespace. This should **only** be used for Smithed bundles as it defines destructive behavior (completely skipping the merging process). Internally, this sets the `override` flag in downstream JSON resources to `true`.


## Overrides

Sometimes, it might be necessary to ensure your version of a specific resource be the root, reguardless of other files that might conflict, **including vanilla ones**. Of course, this feature is generally against compatibility and should **only** be used sparlingly for certain situations. Primarily, this feature is designed for Smithed Bundles, as it allows the patch pack to override behavior from the bundled packs.
