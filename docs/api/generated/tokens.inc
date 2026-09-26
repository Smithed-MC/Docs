## /tokens
### <span class="bdg bdg-success">POST</span>

This route allows the creation of a PAT



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">token</span> <label class="sd-text-secondary">string</label>
Specifically a Firebase ID Token, not another PAT

<span class="bdg bdg-dark">expires</span> <label class="sd-text-secondary">string</label>
How long should the token be valid for, in the form `<num><h|>

<span class="bdg bdg-dark">name</span> <label class="sd-text-secondary">string?</label>
Name of token shown in the UI

<span class="bdg bdg-dark">scopes</span> <label class="sd-text-secondary">PermissionScope[]? = []</label>
List of permissions for the token




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">{tokenDocId: string, tokenEntry: PAToken, token: string}</label>

<span class="bdg bdg-primary">SERVER_ERROR - 500</span> <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Get a 1 day token"
    ```ts
    fetch('https://api.smithed.dev/v2/tokens?token=<ID Token Here>&expires=1d', {mode: "POST"})
    ```

<br/>


### <span class="bdg bdg-success">GET</span>

This route gets all tokens owned by the user



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-dark">token</span> <label class="sd-text-secondary">string</label>
Specifically a Firebase ID Token, not another PAT




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

<span class="bdg bdg-primary">OK - 200</span> <label class="sd-text-secondary">{tokenDocId, tokenEntry: PAToken}[]</label>

<span class="bdg bdg-primary">SERVER_ERROR - 500</span> <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

!!! note "Get all tokens"
    ```ts
    fetch('https://api.smithed.dev/v2/tokens?token=<ID Token Here>')
    ```

<br/>


