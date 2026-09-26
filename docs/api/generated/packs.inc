## /packs
### <span class="bdg bdg-success">GET</span>

Get a list of packs which meet the specified criteria



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">search</span> <label class="sd-text-secondary">string</label>
A search query against the name or id of the pack

<span class="bdg bdg-dark">sort</span> <label class="sd-text-secondary">[SortOptions](data-types.md)</label>
How to sort the requested data

<span class="bdg bdg-dark">limit</span> <label class="sd-text-secondary">int = 20</label>
How many packs to send. Maximum of 100 per request.

<span class="bdg bdg-dark">start</span> <label class="sd-text-secondary">int = 0</label>
How far into the queries should be counted

<span class="bdg bdg-dark">category</span> <label class="sd-text-secondary">[PackCategory](data-types.md)[]?</label>
Which categories should the pack be a part of

<span class="bdg bdg-dark">version</span> <label class="sd-text-secondary">[MinecraftVersion](data-types.md)[]?</label>
Which versions should the pack support

<span class="bdg bdg-dark">hidden</span> <label class="sd-text-secondary">boolean = false</label>
Should unlisted packs be returned.

<span class="bdg bdg-dark">scope</span> <label class="sd-text-secondary">string[]?</label>
A list of variable lookups starting with `data.` or `meta.`




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">{id: string, displayName: string, data?: any, meta?: any}</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Get a list of packs that are marked as Extensive and their descriptions"
    ```ts
    fetch('https://api.smithed.dev/v2/packs?category=Extensive&scope=data.display.description')
    ```

<br/>


### <span class="bdg bdg-success">POST</span>

Upload a new pack to the plaform



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">token</span> <label class="sd-text-secondary">string</label>
Either Firebase Id Token or a valid PAT

<span class="bdg bdg-dark">id</span> <label class="sd-text-secondary">string</label>
The plaintext id for the pack



#### Body Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">data</span> <label class="sd-text-secondary">[PackData](data-types.md)</label>



#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">{packId: string}</label>

<span class="bdg bdg-primary">CONFLICT - 409</span> <label class="sd-text-secondary">ApiError</label>

<span class="bdg bdg-primary">UNAUTHORIZED - 401</span> <label class="sd-text-secondary">ApiError</label>

<span class="bdg bdg-primary">FORBIDDEN - 403</span> <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Upload a new pack called foobar"
    ```ts
    fetch('https://api.smithed.dev/v2/packs/coc?token=NOT_TODAY_HAHA&id=foobar', {
      method:'POST',
      body: {data: <Pack Data>},
      headers: {'Content-Type': 'application/json'}
    })
    ```

<br/>


