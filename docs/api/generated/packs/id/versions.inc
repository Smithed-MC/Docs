## /packs/:id/versions
### <span class="bdg bdg-success">GET</span>

Get the list of a pack's versions


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">PackVersion</label>

<span class="bdg bdg-primary">NOT_FOUND - 404</span> <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Get a pack's versions"
    ```ts
    fetch('https://api.smithed.dev/v2/packs/coc/versions')
    ```

<br/>


### <span class="bdg bdg-success">POST</span>

Add to the list of a pack's versions


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.


#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">token</span> <label class="sd-text-secondary">string</label>
Either Firebase Id Token or a valid PAT

<span class="bdg bdg-dark">version</span> <label class="sd-text-secondary">string</label>
The valid semver version number to assign



#### Body Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">data</span> <label class="sd-text-secondary">[PackVersion](data-types.md)</label>
The data to add to the list



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
    fetch('https://api.smithed.dev/v2/packs/coc/versions?token=FOO&version=0.0.1', {
      method: 'POST',
      body: {data: <PackVersion>},
      headers: {'Content-Type': 'application/json'}
    })
    ```

<br/>


