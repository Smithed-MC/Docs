## /packs/:id/gallery/:index
### {bdg-success}`GET`

Retrieve a pack's gallery image


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.
**index**:
The index of the gallery image counting from 0



#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">image/webp</label>

{bdg-primary}`NOT_FOUND - 404` <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Fetch a packs's first gallery image (if it's present)
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/packs/bound/gallery/0')
```
::::

<br/>


