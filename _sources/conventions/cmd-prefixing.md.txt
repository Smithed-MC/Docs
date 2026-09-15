---
myst:
  substitutions:
    summary: "Formatting your `custom_model_data` to avoid clashing with other packs"
    required: "Any usage of the `custom_model_data` field on custom items based on vanilla item models"
    example: "Items from Gamemode4 should have `custom_model_data` that use `strings` with a `gm4` namespace"
---

# CMD Prefixing
{{ convention_header }}

```{important} 
The convention is largely unneccessary with modern Minecraft changes. Since the introduction of [item components](minecraft.wiki/w/data_components) in 1.20.5, the new `item_model` component can be used to display any item model on any item which allows for extremely flexible displaying of custom items.

The only use-case for this convention for now is to still support packs who rely on overriding vanilla item files in order to display optional textures for custom items.
```
The `custom_model_data` component defines several types of data that can help you avoid conflicts with other packs' custom items. This is *only* neccessary in the context where a creator wants to create a data pack with an **optional** resource pack. Since there are not many packs with these requirements, it's likely any risk of conflict is minimal.

The best case is to use the `strings` subcomponent field of the main component and define values that are using your [namespace](/conventions/namespacing) as a prefix. This ensures proper compatibility for people overriding the same vanilla files (relying on weld to merge said files). You could also use the other fields such as `flags` and such with namespacing.

```{admonition} Example
:class: note

I have a cool sword texture I want to apply to the diamond sword model, instead of using `CustomModelData` 1, I would use `CustomModelData` 4250001
```

```{seealso}
The original version of this convention was based on the set of conventions set by the MC Datapack community via [a webapp](https://mcdatapack.vercel.app/) where creators could select numerical prefixes for `CustomModelData` values that would only be used by their data and resource packs.

Since the introduction of Smithed, we had planned to supercede this system but never got around to it until Mojang (thankfully!) killed any reason to maintain it.

You may see these numbers in the wild by packs for a myriad of reasons but there's no new reason to use them.
```