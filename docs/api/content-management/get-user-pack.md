<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.5em 0em'></div>

{octicon}`info` No authentication needed

::::::{grid} 1 1 2 2
:padding: 0 0 0 0
:margin: 0 0 0 0

:::::{grid-item} 

Returns the JSON structure for a user's pack. 
```{admonition} Directory Information
:class: info
In order to retrieve the directory information you must use another endpoint <!--TODO: Add reference to endpoint-->
```
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

{bdg-dark}`pack` <label class="sd-text-secondary">string</label> <label class="sd-text-warning">Required</label><br/>
The ID of the pack you're trying to retrieve
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.5em 0em'></div>

:::::
:::::{grid-item}
### Code Samples
:::{card} {bdg-primary}`GET` `/getUserPack`
```js
const url = `https://api.smithed.dev/getUserPack?username=smithed&pack=actionbar`
const resp = await fetch(url)
```
:::
### Response
:::{card} {bdg-success}`200` OK
```json
{
  "categories": [
    "Library"
  ],
  "display": {
    "description": "Compatible actionbars for all!",
    "hidden": false,
    "icon": "...",
    "name": "[SMD] Actionbar",
    "webPage": "..."
  },
  "id": "actionbar",
  "versions": [
    {
      "breaking": true,
      "downloads": {
        "datapack": "..."
      },
      "name": "0.1.0",
      "supports": [
        "1.19"
      ]
    }
  ]
}
```
:::
:::::
::::::