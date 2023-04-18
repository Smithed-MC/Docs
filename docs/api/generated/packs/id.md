## /packs/:id
### {bdg-success}`GET`

Retrieve a pack's data
#### URL Parameters<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.

#### Possible Responses<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
{bdg-primary}`OK` <label class="sd-text-secondary">PackData</label>

{bdg-primary}`NOT_FOUND` <label class="sd-text-secondary">ApiError</label>

#### Examples<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
::::{admonition} Fetch a packs's data
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/packs/coc')
```
::::

### {bdg-success}`PATCH/PUT`

Update a pack's data
#### URL Parameters<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.
#### Query Parameters<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
{bdg-dark}`token` <label class="sd-text-secondary">string</label>
Either Firebase Id Token or a valid PAT
#### Possible Responses<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
{bdg-primary}`OK` <label class="sd-text-secondary">string</label>

{bdg-primary}`NOT_FOUND` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`UNAUTHORIZED` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`FORBIDDEN` <label class="sd-text-secondary">ApiError</label>

#### Examples<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
::::{admonition} Set a packs's data
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/packs/coc?token=NOT_TODAY_HAHA', {
  method:'PATCH',
  body: {data: <Pack Data>},
  headers: {'Content-Type': 'application/json'}
})
```
::::

### {bdg-success}`DELETE`

Delete a specific pack
#### URL Parameters<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.
#### Query Parameters<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
{bdg-dark}`token` <label class="sd-text-secondary">string</label>
Either Firebase Id Token or a valid PAT
#### Possible Responses<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
{bdg-primary}`OK` <label class="sd-text-secondary">string</label>

{bdg-primary}`NOT_FOUND` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`UNAUTHORIZED` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`FORBIDDEN` <label class="sd-text-secondary">ApiError</label>

#### Examples<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>
::::{admonition} Set a packs's data
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/packs/coc?token=NOT_TODAY_HAHA', {
  method:'DELETE'
})
```
::::

