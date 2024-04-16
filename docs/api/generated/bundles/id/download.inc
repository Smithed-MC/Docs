## /bundles/:id/download
### {bdg-success}`GET`

Download a pack bundle. This route wraps `/download` and returns the same information.


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The bundle's UID, unlike packs and users, bundles do not have a plaintext ID


#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`mode` <label class="sd-text-secondary">'datapack' | 'resourcepack' | 'both' = 'both'</label>
Which files should be downloaded from the API.

{bdg-dark}`version` <label class="sd-text-secondary">string? = '</label>
'
Which version of the bundle to download




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">ArrayBuffer</label>

{bdg-primary}`NOT_FOUND - 404` <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Download a bundle's resourcepack
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/bundles/123456789/download?mode=resourcepack')
```
::::

<br/>


