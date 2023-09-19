---
myst:
  substitutions:
    summary:  "Extra `id` metadata to include in your `pack.mcmeta`"
    required: "Every pack should include this field in their `pack.mcmeta`"
    example:  "For the pack, The Creeper's Code, the `id` field in `pack.mcmeta` should be \"tcc\""
---

# Pack IDs
{{ convention_header }}

```{important}
:class: warning

This convention is currently being evaluated.
```

Pack IDs are simply a new field to be added to `pack.mcmeta` to help **identify** packs. Just add `id` as a top level field and use a unique string that represents your pack. This `id` should be stable (it shouldn't change) once you have published your pack and it should match the id chosen when uploading your pack to Smithed.

```json
{
    "id": "my-pack",
    "pack": {
        "pack_format": "...",
        "description": "my cool pack"
    }
}
```

## The Why

While pack ids seem like a minor addition, it gives us the ability to identity a pack in the simplest manner possible. Since packs don't need to register their own namespace, there's no other way to identify a pack other than it's directory or zip name (which has several other issues, since players can rename zips).

Pack creators adding an `id` field will allow us to build tooling to understand packs making tools such as `weld` more powerful in recognizing and correctly merging packs.

```{seealso}
Weld uses pack ids to be able to set priorities and pack conditions possible. This lets your pack to be able to rely on other packs (such as ensuring your pack runs after `tcc`, for example).
```
