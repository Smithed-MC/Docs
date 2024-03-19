<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.5em 0em'></div>

{octicon}`info` No authentication needed

::::::{grid} 1 1 2 2
:padding: 0 0 0 0
:margin: 0 0 0 0

:::::{grid-item} 

Returns the JSON structure for all of a user's packs
## Parameters
Query parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.5em 0em'></div>

{octicon}`info` You only need to specify UID or Username, one **must** be specified

{bdg-dark}`uid` <label class="sd-text-secondary">string</label> <label class="sd-text-warning">Required</label><br/>
The UID of the user whose pack you are trying to retrieve
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.5em 0em'></div>

{bdg-dark}`username` <label class="sd-text-secondary">string</label> <label class="sd-text-warning">Required</label><br/>
The username of the user whose pack you are trying to retrieve
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.5em 0em'></div>

:::::
:::::{grid-item}
### Code Samples
:::{card} {bdg-primary}`GET` `/getUserPacks`
```js
const url = `https://api.smithed.dev/getUserPacks?username=smithed`
const resp = await fetch(url)
```
:::
### Response
:::{card} {bdg-success}`200` OK
```json
[
  {
    "display": {
      // Minimized
    },
    "id": "prevent-aggression",
    "versions": [
      {
        "name": "0.1.0",
        // Minimized
      }
    ]
  },
  // Truncated List
]
```
:::
:::::
::::::