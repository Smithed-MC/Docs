---
myst:
  substitutions:
    summary:  "Formatting your `CustomModelData` to avoid clashing with other packs"
    required: "Any usage of the `CustomModelData` field on custom items"
    example:  "Items from The Creeper's Code should have `CustomModelData` beginning with `033`"
---

# CMD Prefixing
{{ convention_header }}

```{admonition} 🚧 In Construction 🚧
:class: warning

This page isn't complete yet, check back often for future updates!
```


CMD Prefixing is essentially offsetting your `CustomModelData` by some extremely large number. This is to avoid overlapping cmd's.

```{admonition} Example
:class: note

I have a cool sword texture I want to apply to the diamond sword model, instead of using `CustomModelData` 1, I would use `CustomModelData` 4250001
```

## Resources
- [List of people's prefixes](https://mcdatapack.vercel.app/)
  - This is an old portal we will remake soon!
