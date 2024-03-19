## /bundles
### {bdg-success}`POST`

Update an existing bundle



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

{bdg-primary}`CREATED - 201` <label class="sd-text-secondary">string</label>

{bdg-primary}`UNAUTHORIZED - 401` <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Upload a new bundle
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/bundles', {
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


