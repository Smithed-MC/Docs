## /bundles/:id
### {bdg-success}`GET`

Retrieve a bundle's data


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The bundle's UID, unlike packs and users, bundles do not have a plaintext ID




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">PackBundle</label>

{bdg-primary}`NOT_FOUND - 404` <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Retrieve a bundle
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/bundles/123456789')
```
::::

<br/>


### {bdg-success}`DELETE`

Delete a bundle from the database


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The bundle's UID, unlike packs and users, bundles do not have a plaintext ID


#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`token` <label class="sd-text-secondary">string</label>
Either Firebase Id Token or a valid PAT




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">string</label>

{bdg-primary}`NOT_FOUND - 404` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`UNAUTHORIZED - 401` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`FORBIDDEN - 403` <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Delete a bundle
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/bundles/123456789?token=ILOVESMITHED', {method: 'DELETE'})
```
::::

<br/>


### {bdg-success}`PUT`

Update an existing bundle


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The bundle's UID, unlike packs and users, bundles do not have a plaintext ID


#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`token` <label class="sd-text-secondary">string</label>
Either Firebase Id Token or a valid PAT



#### Body Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`data` <label class="sd-text-secondary">[PackBundle](/api/data-types)</label>
The data to replace the existing with, omitting the `owner` field.



#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">string</label>

{bdg-primary}`NOT_FOUND - 404` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`UNAUTHORIZED - 401` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`FORBIDDEN - 403` <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Update a bundle
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/bundles/123456789', {
  method: 'PUT',
  body: {
     data: <PackBundle>
  },
  headers: {
     "Content-Type": "application/json"
  }
})
```
::::

<br/>


