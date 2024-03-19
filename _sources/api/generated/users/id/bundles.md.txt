## /users/:id/bundles
### {bdg-success}`GET`

Retrieve a specific users owned and contributed packs


#### URL Parameters
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

**id**:
The user's UID or plaintext username. Using UID is more performant as it is a direct lookup.




#### Possible Responses
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-primary}`OK - 200` <label class="sd-text-secondary">string[]</label>

{bdg-primary}`NOT_FOUND - 404` <label class="sd-text-secondary">ApiError</label>



#### Examples
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

::::{admonition} Fetch a user's bundles
    :class: note        
```ts
fetch('https://api.smithed.dev/v2/users/TheNuclearNexus/bundles')
```
::::

<br/>


