## /packs/:id/versions/latest
### <span class="bdg bdg-success">DELETE</span>

Returns the latest version of the specified pack


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.


#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">version</span> <label class="sd-text-secondary">[MinecraftVersion](data-types.md)?</label>
Optionally, get the latest version for the specified game version




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">PackVersion</label>

<span class="bdg bdg-primary">NOT_FOUND - 404</span> <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Get the latest version for 1.19"
    ```ts
    fetch('https://api.smithed.dev/v2/packs/coc/versions/latest?version=1.19', {})
    ```

<br/>


