## /sanitize
### <span class="bdg bdg-success">GET</span>

Sanitize a value to a consistent format (Alphanumeric + `-` & `_`)



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">value</span> <label class="sd-text-secondary">string</label>
The value too properly sanitize




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">string</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Sanitize a username"
    ```ts
    fetch('https://api.smithed.dev/v2/sanitize?value=Jachro') // Returns "jachro"
    ```

<br/>


