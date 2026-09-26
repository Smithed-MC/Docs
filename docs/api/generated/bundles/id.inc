## /bundles/:id
### <span class="bdg bdg-success">GET</span>

Retrieve a bundle's data


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The bundle's UID, unlike packs and users, bundles do not have a plaintext ID




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">PackBundle</label>

<span class="bdg bdg-primary">NOT_FOUND - 404</span> <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Retrieve a bundle"
    ```ts
    fetch('https://api.smithed.dev/v2/bundles/123456789')
    ```

<br/>


### <span class="bdg bdg-success">DELETE</span>

Delete a bundle from the database


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The bundle's UID, unlike packs and users, bundles do not have a plaintext ID


#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">token</span> <label class="sd-text-secondary">string</label>
Either Firebase Id Token or a valid PAT




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">string</label>

<span class="bdg bdg-primary">NOT_FOUND - 404</span> <label class="sd-text-secondary">ApiError</label>

<span class="bdg bdg-primary">UNAUTHORIZED - 401</span> <label class="sd-text-secondary">ApiError</label>

<span class="bdg bdg-primary">FORBIDDEN - 403</span> <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Delete a bundle"
    ```ts
    fetch('https://api.smithed.dev/v2/bundles/123456789?token=ILOVESMITHED', {method: 'DELETE'})
    ```

<br/>


### <span class="bdg bdg-success">PUT</span>

Update an existing bundle


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The bundle's UID, unlike packs and users, bundles do not have a plaintext ID


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

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">string</label>

<span class="bdg bdg-primary">NOT_FOUND - 404</span> <label class="sd-text-secondary">ApiError</label>

<span class="bdg bdg-primary">UNAUTHORIZED - 401</span> <label class="sd-text-secondary">ApiError</label>

<span class="bdg bdg-primary">FORBIDDEN - 403</span> <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Update a bundle"
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

<br/>


