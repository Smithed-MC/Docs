## /validate-download
### {bdg-success}`GET`

This route is used to ensure that a download url is valid and reachable by the Smithed servers.



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`url` <label class="sd-text-secondary">string</label>
The download url




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">{valid: boolean}</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Validate a github url
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/validate-download?url=' + encodeURIComponent(
  'https://github.com/TheNuclearNexus/CallOfChaos/releases/download/0.0.5/Call.of.Chaos.0.0.5.zip'
))
```
::::

<br/>


