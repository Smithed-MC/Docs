## /packs/:id/versions/:versionId
### <span class="bdg bdg-success">PATCH</span>

Add to the list of a pack's versions


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.
**versionId**:
The version number to target


#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">token</span> <label class="sd-text-secondary">string</label>
Either Firebase Id Token or a valid PAT



#### Body Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">data</span> <label class="sd-text-secondary">[PackVersion](data-types.md)</label>
The data to merge/overwrite with



#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">string</label>

<span class="bdg bdg-primary">NOT_FOUND - 404</span> <label class="sd-text-secondary">ApiError</label>

<span class="bdg bdg-primary">UNAUTHORIZED - 401</span> <label class="sd-text-secondary">ApiError</label>

<span class="bdg bdg-primary">FORBIDDEN - 403</span> <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Add a version to a pack"
    ```ts
    fetch('https://api.smithed.dev/v2/packs/coc/versions/0.0.1?token=FOO', {
      method: 'PATCH',
      body: {data: <PackVersion>},
      headers: {'Content-Type': 'application/json'}
    })
    ```

<br/>


### <span class="bdg bdg-success">DELETE</span>

Add to the list of a pack's versions


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.
**versionId**:
The version number to target


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

!!! note "Delete a version"
    ```ts
    fetch('https://api.smithed.dev/v2/packs/coc/versions/0.0.1?token=FOO', {
      method: 'DELETE',
    })
    ```

<br/>


