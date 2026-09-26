# Contributing

Contributions are welcome! Make sure you open an issue to discuss changes or open a pull request if you have changes you want to make over at our [Github](https://github.com/Smithed-MC/Docs).

> We use [poetry](https://python-poetry.org/docs/) to manage our Python dependencies and [zensical](https://zensical.org) to build, preview, and deploy our docs.

## Setup

If you wish to build docs locally, follow our setup guide. You'll need to install [poetry](https://python-poetry.org/docs/) via the official instructions. Then, setup can proceed like so:

```bash
$ git clone https://github.com/Smithed-MC/Docs && cd Docs
$ poetry install
```

To actively develop your docs, you can use:
```bash
$ poetry run zensical serve
```
This will open a local web server (at `localhost:8000` by default) to access your locally built docs alongside watching any changes made within the `docs` directory so you can watch your changes build live.

You can also build the static site (output in the `site/` directory) with:
```bash
$ poetry run zensical build --clean
```

### Libraries

Additionally, parts of the `libraries` documentation are generated automatically by extracting api docstrings directly from the source code. We actually install the [`smithed-libraries`](https://github.com/Smithed-MC/Libraries/) package directly and run the documentation plugin within to extract the docs directly into the `docs/libraries/` directory. Files generated this way get committed to the repo, but should not be touched as they will immediately get overwritten by library updates.

If you need to manually update your library docs, you locally run the following commands in a dedicated environment (the library toolchain and `zensical` do not currently share a compatible dependency set):
```bash
$ pip install smithed-libraries
$ beet -p docs/libraries
```
The generated files are then included into the hand-written library pages via [snippets](#snippets).

## Style

The docs are written in normal `markdown` and built with [Zensical](https://zensical.org), which is a modern static site generator using the [Python Markdown](https://python-markdown.github.io/) and [PyMdown Extensions](https://facelessuser.github.io/pymdown-extensions/) syntax. This gives us access to a rich set of features:

  - [Admonitions](https://zensical.org/docs/authoring/admonitions/)
    - Callouts such as `!!! note` or collapsible `??? note` blocks used for side content.
  - [Grids](https://zensical.org/docs/authoring/grids/)
    - Cards and generic grids used to build the index pages.
  - [Content tabs](https://zensical.org/docs/authoring/content-tabs/)
    - `=== "Tab title"` blocks used to group alternative content.
  - [Icons and emojis](https://zensical.org/docs/authoring/icons-emojis/)
    - Shortcodes such as `:octicons-download-16:` or `:fontawesome-brands-github:`.
  - [Buttons](https://zensical.org/docs/authoring/buttons/)
    - `[Label](url){ .md-button }` links.
  - [Snippets](https://facelessuser.github.io/pymdown-extensions/extensions/snippets/)
    - `--8<-- "path/to/file.md"` includes another file into the current page.
  - [Macros](https://mkdocs-macros-plugin.readthedocs.io/)
    - Values wrapped in double curly braces (e.g. `actionbar_version`), defined under `[project.extra]` in `zensical.toml`.

We also use a small set of custom classes defined in `docs/stylesheets/extra.css`:

  - Badges are written as inline HTML: `<span class="bdg bdg-primary">OK - 200</span>`. Available variants are `bdg-primary`, `bdg-primary-line`, `bdg-success`, `bdg-success-line`, `bdg-dark`, and `bdg-info-line`.
  - The `sd-*` classes (`sd-bg-secondary`, `sd-text-secondary`) are kept for the generated API docs.

### Libraries

Much of the libraries source, especially API docs are written alongside the actual source. To keep consistency with how these docs are rendered within the main docs, we use the following system.
  - The documentation plugin's generation of files produce folders and files within the `libraries`.
    - These files should **not** be altered directly.
  - Instead, these files should be referenced via the `--8<--` snippet directive.
    - Please see the existing library files such as [actionbar](libraries/actionbar) source to see an example.
  - Within the library api docs, you should **not** use top level `# Header` lines.
    - Instead, use `##` or `###` and below for hierachy.
    - This ensures the sidebar doesn't get polluted with internal markings.

### `mcfunction` syntax

Instead of using raw, vanilla syntax, we bend the rules of the original syntax slightly for legibility:
  - Commands longer than 80 characters are often seperated into multiple lines
  - Multiple files (such as loot tables or functions) are represented in the same file

Here is an example of how that usually looks:
```mcfunction
execute as @a if score @s my_obj matches 10 if entity @s {Health: 20.0f} run function namespace:hello_world

# namespace:hello_world
scoreboard players set @s my_obj 10
tag @s remove self
tellraw @a [{"text": "Really long tellraw", "color": "blue"}, {"text": "like, really, really long", "color": "yellow"}, {"text": "like whoa"}]
```
*versus*
```mcfunction
execute
    as @a
    if score @s my_obj matches 10
    if entity @s {Health: 20.0f}
    run function namespace:hello_world:
        scoreboard players set @s my_obj 10
        tag @s remove self
        tellraw @a [
            {"text": "Really long tellraw", "color": "blue"},
            {"text": "like, really, really long", "color": "yellow"},
            {"text": "like whoa"}
        ]
```

The commands are highlighted by [pygments](https://github.com/pygments/pygments), a python-based syntax highlighter. You can explore how `mcfunction` gets highlighted by checking out the project and testing out the highlighter by itself!

In terms of how we control multi-line commands:
  - `execute` should stand on it's own lines with each sub-command on their own line
  - Long `json` components can be split as if it's an embedded `.json` file.
  - Other containers such as long selectors or nbt can be treated similar to `.json` files.
  - Embedded files such as loot tables and functions should be written in an indented fashion:

```mcfunction
loot_table minecraft:entity/zombie {"hello": "world"}
function namespace:other:
    command 1
    command 2
```

> All code examples across this documentation are actually based on the [bolt](https://github.com/mcbeet/bolt) format which means they can compile directly into normal commands!

## Endnote

The core of good documentation is based on well written text. While we use many fancy bells and whistles from Zensical, there's no need to overcomplicate the purpose of these docs and so don't let that dissuade you from making contributions!

We are always looking to improve our docs so please do not fret to make suggestions and refinements. We will work our best to integrate the best pieces of work so our docs can accurately describe the Smithed ecosystem to the best of our abilities.
