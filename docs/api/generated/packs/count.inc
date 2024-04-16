## /packs/count
### {bdg-success}`GET`

Similar to /packs, this route returns the number of packs which match the criteria



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`search` <label class="sd-text-secondary">string</label>
A search query against the name or id of the pack

{bdg-dark}`category` <label class="sd-text-secondary">[PackCategory](/api/data-types)[]?</label>
Which categories should the pack be a part of

{bdg-dark}`version` <label class="sd-text-secondary">[MinecraftVersion](/api/data-types)[]?</label>
Which versions should the pack support

{bdg-dark}`hidden` <label class="sd-text-secondary">boolean = false</label>
Should unlisted packs be returned.




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">number</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Number of packs which contain `the`
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/packs/count?search=the')
```
::::

<br/>


