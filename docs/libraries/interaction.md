# Interaction (v{{ interaction_version }})
> A small library that serves to enable easier usage of interaction entities.

::::{grid} 2

:::{grid-item}
```{button-link} https://api.smithed.dev/v2/download?pack=interaction
:color: primary
:outline:
:expand:
{octicon}`download;1em` Download
```
:::

:::{grid-item}
```{button-link} https://github.com/Smithed-MC/Libraries/tree/main/smithed_libraries/packs/interaction/
:color: primary
:outline:
:expand:
{octicon}`mark-github;1em` Source
```
:::

::::

Usage entails putting data on the interaction entity. Specifically, giving the interaction the `smithed.interaction` tag and then adding custom data in the entity's `data` field.

Usually, this is done by summoning the interaction with the relevant data like below:
```{code-block} mcfunction
summon minecraft:interaction ~ ~ ~ { \
  Tags: ["smithed.interaction"], \
  data: { \
    smithed_interaction: { \
      on_right_click: { \
        command: "say hello world" \
      } \
    } \
  } \
}
```
However, you can also use `/tag` and `/data` to add the tag and data respectively if you wish.

## Basics

```{include} interaction/basics.md
```

## Custom Interactions

```{include} interaction/custom_interactions.md
```

### `custom: sit`
```{include} interaction/custom_sit.md
```
