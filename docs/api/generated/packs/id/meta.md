## /packs/:id/meta
### {bdg-success}`GET`

Retrieve a pack's metadata
#### URL Parameters<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.

#### Possible Responses<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
{bdg-primary}`OK` <label class="sd-text-secondary">PackMetaData</label>

{bdg-primary}`NOT_FOUND` <label class="sd-text-secondary">ApiError</label>

#### Examples<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
::::{admonition} Set a packs's data
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/packs/coc/meta')
```
::::

