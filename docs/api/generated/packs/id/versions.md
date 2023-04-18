## /packs/:id/versions
### {bdg-success}`GET`

Get the list of a pack's versions
#### URL Parameters<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.

#### Possible Responses<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
{bdg-primary}`OK` <label class="sd-text-secondary">PackVersion</label>

{bdg-primary}`NOT_FOUND` <label class="sd-text-secondary">ApiError</label>

#### Examples<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
::::{admonition} Get a pack's versions
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/packs/coc/versions')
```
::::

### {bdg-success}`POST`

Add to the list of a pack's versions
#### URL Parameters<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.
#### Query Parameters<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
{bdg-dark}`token` <label class="sd-text-secondary">string</label>
Either Firebase Id Token or a valid PAT
{bdg-dark}`version` <label class="sd-text-secondary">string</label>
The valid semver version number to assign
#### Possible Responses<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
{bdg-primary}`OK` <label class="sd-text-secondary">string</label>

{bdg-primary}`NOT_FOUND` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`UNAUTHORIZED` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`FORBIDDEN` <label class="sd-text-secondary">ApiError</label>

#### Examples<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
::::{admonition} Add a version to a pack
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/packs/coc/versions?token=FOO&version=0.0.1', {
  method: 'POST',
  body: {data: <PackVersion>},
  headers: {'Content-Type': 'application/json'}
})
```
::::

