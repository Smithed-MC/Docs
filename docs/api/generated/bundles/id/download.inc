## /bundles/:id/download
### <span class="bdg bdg-success">GET</span>

Download a pack bundle. This route wraps `/download` and returns the same information.


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The bundle's UID, unlike packs and users, bundles do not have a plaintext ID


#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">mode</span> <label class="sd-text-secondary">'datapack' | 'resourcepack' | 'both' = 'both'</label>
Which files should be downloaded from the API.

<span class="bdg bdg-dark">version</span> <label class="sd-text-secondary">string? = '</label>
'
Which version of the bundle to download




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">ArrayBuffer</label>

<span class="bdg bdg-primary">NOT_FOUND - 404</span> <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Download a bundle's resourcepack"
    ```ts
    fetch('https://api.smithed.dev/v2/bundles/123456789/download?mode=resourcepack')
    ```

<br/>


