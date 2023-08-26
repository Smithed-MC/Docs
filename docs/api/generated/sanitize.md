## /sanitize
### {bdg-success}`GET`

Sanitize a value to a consistent format (Alphanumeric + `-` & `_`)



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`value` <label class="sd-text-secondary">string</label>
The value too properly sanitize




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">string</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Sanitize a username
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/sanitize?value=Jachro') // Returns "jachro"
```
::::

<br/>


