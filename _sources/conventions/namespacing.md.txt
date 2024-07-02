---
myst:
  substitutions:
    summary:  "Adding friendly prefixes to names of content in your pack"
    required: "On file paths, tags, scores, teams, and storage"
    example:  "`tcc` as a namespace for the `tcc.dummy` scoreboard"
---

# Namespacing
{{ convention_header }}

Namespacing is when you prefix your content with something in order to prevent the collision of names.

Your packs should have a consistent and clear namespace which can be attributed towards you. These can be based off of your pack name, your author name, some sort of abbreviation commonly attributed towards your pack, etc.

## Examples

Here are a short list of namespaces currently used in the pack ecosystem.
- `tcc` for ["The Creeper's Code"](https://smithed.dev/packs/creepermagnet_/tcc)
- `rx.playerdb` for ["PlayerDB"](https://github.com/rx-modules/PlayerDB)

### Scoreboard
My pack's name is "The Creeper's Code", so I'll use "tcc" as my prefix
```mcfunction
# Instead of
scoreboard objectives add dummy dummy
# You need to use
scoreboard objectives add tcc.dummy dummy 
```
Changes like this prevent other packs from overwriting your scores and tags.

### Storage
Namespacing storage is similar..
```mcfunction
# Instead of
data merge storage data {foo: "bar"}
# You should use
data merge storage tcc:data {foo: "bar"}
```

## Things required to be prefixed
- File paths (`namespace:function` or `author.namespace:function`)
- Tags `@e[tag=namespace.example]`
- Scores
- Teams
- Storage
