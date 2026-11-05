# Source

Source definitions are used to specify the data to be used in a rule. You can either define the data directly or reference a path in the current json file.

```{tip}
Using `reference` allows you to supply a loot table that is valid when weld isn't used and reuse the same data for when weld *is* used.

Using `value` allows you to customize behavior if and only if weld is used.
```

{bdg-info-line}`type` <code class="sd-text-secondary">"reference" | "value"</code> - The type of source definition to apply. A `weld:` can be prefixed on the rule type.

### `value`
<div class='sd-bg-secondary' style='width: 75%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-info-line}`value` <code class="sd-text-secondary">Any</code> - The data that will be used as the source for rule application.

### `reference`
<div class='sd-bg-secondary' style='width: 75%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-info-line}`path` <code class="sd-text-secondary">str</code> - A specifed path to a field within the current json file. The data at this path will be used as the source for rule application.

```{note}
Reference sources are converted to value sources as apart of a pre-processing step before pack merging is computed.
```