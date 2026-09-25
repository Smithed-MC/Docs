# Technical Slots (v{{ tech_slots_version }})
> A library to facilitate the use of the player's body and saddle slots for player modifications.

::::{grid} 2

:::{grid-item}
```{button-link} https://api.smithed.dev/v2/download?pack=tech-slots
:color: primary
:outline:
:expand:
{octicon}`download;1em` Download
```
:::

:::{grid-item}
```{button-link} https://github.com/Smithed-MC/Libraries/tree/main/smithed_libraries/packs/tech-slots/
:color: primary
:outline:
:expand:
{octicon}`mark-github;1em` Source
```
:::

::::


There are two ways to interface with this library: manually calling functions in the library to run common code, or running the automated library functions to trigger the entire process. It is recommended to use the manual calls for finer control, and to limit the execution of macro commands. In both cases, modifiers can be restored automatically upon death.

## Additional Restore Functionality
```{include} tech-slots/restore_logic.md
```

## Manual Calls (Recommended)
```{include} tech-slots/manual_calls.md
```

## Automatic Calls
```{include} tech-slots/automatic_calls.md
```
