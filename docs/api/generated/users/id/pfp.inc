## /users/:id/pfp
### <span class="bdg bdg-success">GET</span>

Retrieve a specific user's pfp


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The user's UID or plain text username. Using UID is more performant as it is a direct lookup.




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">ArrayBuffer</label>

<span class="bdg bdg-primary">NOT_FOUND - 404</span> <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Fetch a user's pfp"
    ```ts
    fetch('https://api.smithed.dev/v2/users/TheNuclearNexus/pfp')
    ```

<br/>


