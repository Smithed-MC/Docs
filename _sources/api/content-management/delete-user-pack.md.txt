<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.5em 0em'></div>

{octicon}`alert` Authentication required

::::::{grid} 1 1 2 2
:padding: 0 0 0 0
:margin: 0 0 0 0

:::::{grid-item} 

Set the JSON structure for a user's pack. 

## Parameters

Query parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.5em 0em'></div>

{octicon}`info` You only need to specify UID or Username, one **must** be specified


{bdg-dark}`token` <label class="sd-text-secondary">string</label> <label class="sd-text-warning">Required</label><br/>
Either your user IDToken or a PAT
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.5em 0em'></div>

{bdg-dark}`uid` <label class="sd-text-secondary">string</label> <label class="sd-text-warning">Required</label><br/>
The UID of the user whose pack you are trying to retrieve
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.5em 0em'></div>

{bdg-dark}`username` <label class="sd-text-secondary">string</label> <label class="sd-text-warning">Required</label><br/>
The username of the user whose pack you are trying to retrieve
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.5em 0em'></div>

{bdg-dark}`pack` <label class="sd-text-secondary">string</label> <label class="sd-text-warning">Required</label><br/>
The ID of the pack you're trying to retrieve
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.5em 0em'></div>

:::::
:::::{grid-item}
### Code Samples
:::{card} {bdg-primary}`POST` `/deleteUserPack`
```js
const token = '...'
const query = `username=smithed&pack=actionbar&token=${token}`

const resp = await fetch('https://api.smithed.dev/deleteUserPack?' + query, {
  method: 'POST', 
})
```
:::
### Response
:::{card} 
{bdg-success}`200` OK
:::
:::::
::::::