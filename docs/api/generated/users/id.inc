## /users/:id
### <span class="bdg bdg-success">GET</span>

Retrieve a specific users information


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The user's UID or plaintext username. Using UID is more performant as it is a direct lookup.




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">{uid: string, cleanName: string, displayName: string, role: string}</label>

<span class="bdg bdg-primary">NOT_FOUND - 404</span> <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Fetch a user's data"
    ```ts
    fetch('https://api.smithed.dev/v2/users/TheNuclearNexus')
    ```

<br/>


### <span class="bdg bdg-success">PATCH/PUT</span>

Set a specific users information


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.


#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">token</span> <label class="sd-text-secondary">string</label>
Either Firebase Id Token or a valid PAT



#### Body Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">data</span> <label class="sd-text-secondary">Omit<UserData, ['cleanName', 'creationTime', 'uid]></label>



#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">string</label>

<span class="bdg bdg-primary">NOT_FOUND - 404</span> <label class="sd-text-secondary">ApiError</label>

<span class="bdg bdg-primary">UNAUTHORIZED - 401</span> <label class="sd-text-secondary">ApiError</label>

<span class="bdg bdg-primary">FORBIDDEN - 403</span> <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Set a user's data"
    ```ts
    fetch('https://api.smithed.dev/v2/users/TheNuclearNexus?token=NOT_TODAY_HAHA', {
      method:'PATCH',
      body: {data: <User Data>},
      headers: {'Content-Type': 'application/json'}
    })
    ```

<br/>


