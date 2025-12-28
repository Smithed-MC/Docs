# Weld

> Merge multiple packs together into a single, tidy zip!

Weld is a tool that makes it easy to combine multiple packs into a singular zip, for both data and resource packs. It implements the same merging policies that vanilla performs when loaded into the game. On top of this, it includes a set of custom merging tools and other quality of life inclusions to enchance compatibility amongst packs.

## Usage

Weld is mainly available as a web-app [here](https://weld.smithed.dev).

### Local Usage

Weld is also a command-line tool that requires Python 3.10+ or higher to run. We recommend [`pipx`](https://pypa.github.io/pipx/) as the preferred way to install `weld`.

```bash
pipx install smithed
```

Once installed, you can run `weld` from the command line.

```bash
weld --help
weld *.zip  # weld all zip files in the current directory
```

```{seealso}
:class: dropdown toggle

# alternatively
python -m pip install weld
```

## Merging

Weld implements all of the vanilla merging rules:
- `tag` files merge the contents of the `values` array ignoring duplicates
  - Ordering of `values` is based on load order
- `model` files merge the overrides with `custom_model_data` defined
  - `custom_model_data` are properly ordered to correctly display them
- `language` files merge the contents of keys
- `font` files extend the `providers` field
- `atlas` files extend the `sources` field ignoring duplicates
- All `json` files supports the custom `__smithed__` weld rules
  - Generally used for `loot_tables`

---

To learn more about the custom merging rules, continue to the next page!

```{toctree}
:hidden: true

merging/index
```
