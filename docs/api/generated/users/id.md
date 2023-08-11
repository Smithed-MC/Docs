## /users/:id
### {bdg-success}`GET`

Retrieve a specific users information


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The user's UID or plaintext username. Using UID is more performant as it is a direct lookup.




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">{uid: string, cleanName: string, displayName: string, role: string}</label>

{bdg-primary}`NOT_FOUND - 404` <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Fetch a user's data
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/users/TheNuclearNexus')
```
::::

<br/>


### {bdg-success}`PATCH/PUT`

Set a specific users information


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The pack's UID or plaintext id. Using UID is more performant as it is a direct lookup.


#### Query Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`token` <label class="sd-text-secondary">string</label>
Either Firebase Id Token or a valid PAT



#### Body Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-dark}`data` <label class="sd-text-secondary">Omit<UserData, ['cleanName', 'creationTime', 'uid]></label>



#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">string</label>

{bdg-primary}`NOT_FOUND - 404` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`UNAUTHORIZED - 401` <label class="sd-text-secondary">ApiError</label>

{bdg-primary}`FORBIDDEN - 403` <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Set a user's data
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/users/TheNuclearNexus?token=NOT_TODAY_HAHA', {
  method:'PATCH',
  body: {data: <User Data>},
  headers: {'Content-Type': 'application/json'}
})
```
::::

<br/>


