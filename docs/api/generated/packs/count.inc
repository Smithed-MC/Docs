## /packs/count
### <span class="bdg bdg-success">GET</span>

Similar to /packs, this route returns the number of packs which match the criteria



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">search</span> <label class="sd-text-secondary">string</label>
A search query against the name or id of the pack

<span class="bdg bdg-dark">category</span> <label class="sd-text-secondary">[PackCategory](data-types.md)[]?</label>
Which categories should the pack be a part of

<span class="bdg bdg-dark">version</span> <label class="sd-text-secondary">[MinecraftVersion](data-types.md)[]?</label>
Which versions should the pack support

<span class="bdg bdg-dark">hidden</span> <label class="sd-text-secondary">boolean = false</label>
Should unlisted packs be returned.




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">number</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Number of packs which contain `the`"
    ```ts
    fetch('https://api.smithed.dev/v2/packs/count?search=the')
    ```

<br/>


