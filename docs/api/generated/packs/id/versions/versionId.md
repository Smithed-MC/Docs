## /packs/:id/versions/:versionId
### {bdg-success}`PATCH`

Add to the list of a pack's versions
#### URL Parameters<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.
**versionId**:
The version number to target
#### Query Parameters<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
{bdg-dark}`token` <label class="sd-text-secondary">string</label>
Either Firebase Id Token or a valid PAT
#### Possible Responses<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
{bdg-primary}`OK` <label class="sd-text-secondary">string</label>

{bdg-primary}`NOT_FOUND` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`UNAUTHORIZED` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`FORBIDDEN` <label class="sd-text-secondary">ApiError</label>

#### Examples<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
::::{admonition} Add a version to a pack
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/packs/coc/versions/0.0.1?token=FOO', {
  method: 'PATCH',
  body: {data: <PackVersion>},
  headers: {'Content-Type': 'application/json'}
})
```
::::

### {bdg-success}`DELETE`

Add to the list of a pack's versions
#### URL Parameters<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.
**versionId**:
The version number to target
#### Query Parameters<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
{bdg-dark}`token` <label class="sd-text-secondary">string</label>
Either Firebase Id Token or a valid PAT
#### Possible Responses<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
{bdg-primary}`OK` <label class="sd-text-secondary">string</label>

{bdg-primary}`NOT_FOUND` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`UNAUTHORIZED` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`FORBIDDEN` <label class="sd-text-secondary">ApiError</label>

#### Examples<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
::::{admonition} Delete a version
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/packs/coc/versions/0.0.1?token=FOO', {
  method: 'DELETE',
})
```
::::

