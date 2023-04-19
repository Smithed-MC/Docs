## /download
### {bdg-success}`GET`

This route facilitates the download and merging of packs off of the platform.



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`pack` <label class="sd-text-secondary">string</label>
The ID (uid or plaintext) of the pack to merge. A specific version can be specified with the following format `<id>@<version>`. Version can be a semver comparison.
Many packs can be downloaded by specifiying the parameter multiple times

{bdg-dark}`version` <label class="sd-text-secondary">[MinecraftVersion](/api/data-types#packdata)?</label>
The targeted version of Minecraft. Any packs that do not have atleast 1 version supporting this will be skipped.

{bdg-dark}`mode` <label class="sd-text-secondary">'datapack'|'resourcepack'|'both' = 'both'</label>
What should be downloaded, if both is specified then the datapack and resourcepack are served zipped within the download.




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">ArrayBuffer</label>

{bdg-primary}`SERVER_ERROR - 500` <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Download packs
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/download?pack=tcc&pack=manic&version=1.19)
```
::::

<br/>


