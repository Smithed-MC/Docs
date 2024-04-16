## /packs/:id/versions/latest
### {bdg-success}`DELETE`

Returns the latest version of the specified pack


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.


#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`version` <label class="sd-text-secondary">[MinecraftVersion](/api/data-types)?</label>
Optionally, get the latest version for the specified game version




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">PackVersion</label>

{bdg-primary}`NOT_FOUND - 404` <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Get the latest version for 1.19
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/packs/coc/versions/latest?version=1.19', {})
```
::::

<br/>


