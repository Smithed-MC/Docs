## /validate-download
### <span class="bdg bdg-success">GET</span>

This route is used to ensure that a download url is valid and reachable by the Smithed servers.



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">url</span> <label class="sd-text-secondary">string</label>
The download url




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">{valid: boolean}</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Validate a github url"
    ```ts
    fetch('https://api.smithed.dev/v2/validate-download?url=' + encodeURIComponent(
      'https://github.com/TheNuclearNexus/CallOfChaos/releases/download/0.0.5/Call.of.Chaos.0.0.5.zip'
    ))
    ```

<br/>


