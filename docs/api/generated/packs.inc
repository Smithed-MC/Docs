## /packs
### {bdg-success}`GET`

Get a list of packs which meet the specified criteria



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`search` <label class="sd-text-secondary">string</label>
A search query against the name or id of the pack

{bdg-dark}`sort` <label class="sd-text-secondary">[SortOptions](/api/data-types)</label>
How to sort the requested data

{bdg-dark}`limit` <label class="sd-text-secondary">int = 20</label>
How many packs to send. Maximum of 100 per request.

{bdg-dark}`start` <label class="sd-text-secondary">int = 0</label>
How far into the queries should be counted

{bdg-dark}`category` <label class="sd-text-secondary">[PackCategory](/api/data-types)[]?</label>
Which categories should the pack be a part of

{bdg-dark}`version` <label class="sd-text-secondary">[MinecraftVersion](/api/data-types)[]?</label>
Which versions should the pack support

{bdg-dark}`hidden` <label class="sd-text-secondary">boolean = false</label>
Should unlisted packs be returned.

{bdg-dark}`scope` <label class="sd-text-secondary">string[]?</label>
A list of variable lookups starting with `data.` or `meta.`




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">{id: string, displayName: string, data?: any, meta?: any}</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Get a list of packs that are marked as Extensive and their descriptions
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/packs?category=Extensive&scope=data.display.description')
```
::::

<br/>


### {bdg-success}`POST`

Upload a new pack to the plaform



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`token` <label class="sd-text-secondary">string</label>
Either Firebase Id Token or a valid PAT

{bdg-dark}`id` <label class="sd-text-secondary">string</label>
The plaintext id for the pack



#### Body Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`data` <label class="sd-text-secondary">[PackData](/api/data-types)</label>



#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">{packId: string}</label>

{bdg-primary}`CONFLICT - 409` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`UNAUTHORIZED - 401` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`FORBIDDEN - 403` <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Upload a new pack called foobar
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/packs/coc?token=NOT_TODAY_HAHA&id=foobar', {
  method:'POST',
  body: {data: <Pack Data>},
  headers: {'Content-Type': 'application/json'}
})
```
::::

<br/>


