# Priority

Priority allows you to specify *when* a pack activates. This allows you to customize if your pack rules must apply before or after other packs. Stage lets you specify a general time when you want your rules to activate.

<span class="bdg bdg-info-line">stage</span> <code class="sd-text-secondary">"early" | "standard" | "late"</code> - The stage in which the rule should activate.

<span class="bdg bdg-info-line">before</span> <code class="sd-text-secondary">str | list[str]</code> - A set of pack id(s). The rules from these packs should be applied **before** the current rule(s).

<span class="bdg bdg-info-line">after</span> <code class="sd-text-secondary">str | list[str]</code> - A set of pack id(s). The rules from these packs should be applied **after** the current rule(s).
