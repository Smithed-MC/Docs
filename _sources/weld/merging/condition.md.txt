# Condition

Conditions allow you to specify if a rule activates or not. All conditions **must** be met for the rule to activate.

{bdg-info-line}`type` <code class="sd-text-secondary">"pack_check" | "inverted"</code> - The type of condition to apply. `weld:` can be prefixed on the condition types.

### `pack_check`
<div class='sd-bg-secondary' style='width: 75%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-info-line}`id` <code class="sd-text-secondary">str</code> - A pack id that should exist before this rule can activate.

### `inverted`
<div class='sd-bg-secondary' style='width: 75%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-info-line}`condition` <code class="sd-text-secondary">[Condition](/weld/merging/condition)</code> - A condition that should be inverted.
