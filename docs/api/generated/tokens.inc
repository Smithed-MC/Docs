## /tokens
### {bdg-success}`POST`

This route allows the creation of a PAT



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`token` <label class="sd-text-secondary">string</label>
Specifically a Firebase ID Token, not another PAT

{bdg-dark}`expires` <label class="sd-text-secondary">string</label>
How long should the token be valid for, in the form `<num><h|>

{bdg-dark}`name` <label class="sd-text-secondary">string?</label>
Name of token shown in the UI

{bdg-dark}`scopes` <label class="sd-text-secondary">PermissionScope[]? = []</label>
List of permissions for the token




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">{tokenDocId: string, tokenEntry: PAToken, token: string}</label>

{bdg-primary}`SERVER_ERROR - 500` <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Get a 1 day token
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/tokens?token=<ID Token Here>&expires=1d', {mode: "POST"})
```
::::

<br/>


### {bdg-success}`GET`

This route gets all tokens owned by the user



#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`token` <label class="sd-text-secondary">string</label>
Specifically a Firebase ID Token, not another PAT




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">{tokenDocId, tokenEntry: PAToken}[]</label>

{bdg-primary}`SERVER_ERROR - 500` <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Get all tokens
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/tokens?token=<ID Token Here>')
```
::::

<br/>


