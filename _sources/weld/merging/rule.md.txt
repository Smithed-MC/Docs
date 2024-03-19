# Rule

Rules define the actual logic of each operation your merging can perform. Each rule is defined by a `type` and then the general configuration of that rule. Rules can do all sorts of things, but generally they apply to a specific path in the file you are editing and then perform some operation on that path via your source.

```{important}
The `target` path field will target relative to the intended file you change. For example, when editing a loot table for zombie in the `minecraft` namespace (`minecraft:entities/zombie`), editing a path such as `pools[0]` will target the first pool in the vanilla table, **even if a previous pack has prepended a pool to the table**. This is because the target path is always relative to the vanilla file.

For welding non-vanilla files, this will be relative to the main namespace, defined by the pack w/o any weld rules set.
```

{bdg-info-line}`type` <code class="sd-text-secondary">"append" | "prepend" | "insert" | "merge" | "replace" | "remove"</code> -  
The type of rule to apply. A `weld:` can be prefixed on the rule type.

{bdg-info-line}`target` <code class="sd-text-secondary">str</code> - A specifed path to a field within the targeted json file.

{bdg-info-line}`conditions` <code class="sd-text-secondary">list[[Condition](/weld/merging/condition)] (*empty*)</code> - A list of conditions that must be met for this rule to activate.

{bdg-info-line}`priority` <code class="sd-text-secondary">[Priority](/weld/merging/priority) | None (copied from Main)</code> - A priority definition which specifies the ordering of when this rule should activate.

### `merge`, `append`, `prepend`, `insert`, `replace`
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-info-line}`source` <code class="sd-text-secondary">Source</code> - A source definition which specifies the data to append/prepend to the target.

### `append`/`prepend`
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

This rule appends/prepends the defined source to the target location.

```{important}
Requires the target to be a list.
```

### `insert`
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

{bdg-info-line}`index` <code class="sd-text-secondary">int</code> - The index of the target path.

```{important}
Requires the target to be a list.
```

### `merge`
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

This rule merges the defined source with the target location. It has three behaviors based on the type of the source and target:

- *Iff* both the source and target are lists, all of the source is appended to the target.
- *Iff* both the source and target are objects, the source is recursively merged into the target.
- Otherwise, the source replaces the target.

```{note}
Since `merge` performs a recursive merge, nested fields perform the same behaviors as the top-level fields.
```

### `replace`
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

This rule replaces the target location with the defined source.

### `remove`
<div class='sd-bg-secondary' style='width: 95%; height: 1px; margin: 0em 0em 0.1em 0em'></div>

This rule removes the target location.
