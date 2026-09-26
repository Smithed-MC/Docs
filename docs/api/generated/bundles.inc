## /bundles
### <span class="bdg bdg-success">POST</span>

Update an existing bundle



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">token</span> <label class="sd-text-secondary">string</label>
Either Firebase Id Token or a valid PAT



#### Body Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">data</span> <label class="sd-text-secondary">[PackBundle](data-types.md)</label>
The data to replace the existing with, omitting the `owner` field.



#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">CREATED - 201</span> <label class="sd-text-secondary">string</label>

<span class="bdg bdg-primary">UNAUTHORIZED - 401</span> <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Upload a new bundle"
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

<br/>


