# Contributing

Contributions are welcome! Make sure you open an issue to discuss changes or open a pull request if you have changes you want to make over at our [Github](https://github.com/Smithed-MC/Docs).

> We use [poetry](https://python-poetry.org/docs/) to manage our dependencies and [mudkip](https://github.com/vberlier/mudkip) to build, deploy, and maintain our docs.

## Setup

If you wish to build docs locally, follow our setup guide. You'll need to install [poetry](https://python-poetry.org/docs/) via the official instructions. Then, setup can proceed like so:

```bash
$ git clone https://github.com/Smithed-MC/Docs && cd Docs
$ poetry install
```

To actively develop your docs, you can use:
```bash
$ poetry run mudkip develop
```
This will open a local web server at `localhost:5000` to access your locally built docs alongside watching any changes made within the `docs` directory so you can watch your changes build live.

### Libraries

Additionally, parts of the `libraries` documentation are generated automatically by extracting api docstrings directly from the source code. We actually install the [`smithed-libraries`](https://github.com/Smithed-MC/Libraries/) package directly and run the documentation plugin within to extract the docs directly into the `docs/libraries/` directory. Files generated this way get committed to the repo, but should not be touched as they will immediately get overwritten by library updates.

If you need to manually update your library docs, you locally run the following commands:
```bash
$ poetry run beet -p docs/libraries
$ poetry run mudkip develop
```

## Style

Mudkip is a tool to make building [sphinx](https://www.sphinx-doc.org/en/master/) based documentation much easier to work with. Mudkip bundles several sphinx plugins to make documentation easier to write, with the [MyST](https://myst-parser.readthedocs.io) plugin being the most useful as it enables us to write in normal `markdown`.

Additionally, we also use the follow extensions:
  - [Sphinx Design](https://sphinx-design.readthedocs.io/)
    - This extension adds several useful cards, grids, icons, and dropdowns to make the documentation look nicer.
  - Colon Fences
    - Makes using ":::" and "::::" instead of pure "\`\`\`" and "\`\`\`\`" which is nicer to use within `markdown` files.
    - We prefer using "::::" for grids and groupings while "\`\`\`" for simple cards and dropdowns.
  - Substitution
    - Allows the use of simple Jinja2 substitutions within YAML frontmatter.

### Libraries

Much of the libraries source, especially API docs are written alongside the actual source. To keep consistency with how these docs are rendered within the main docs, we use the following system.
  - The documentation plugin's generation of files produce folders and files within the `libraries`.
    - These files should **not** be altered directly.
  - Instead, these files should be referenced via the `{include}` directive.
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
    run function namespace:hello_world
        scoreboard players set @s my_obj 10
        tag @s remove self
        tellraw @a [
            {"text": "Really long tellraw", "color": "blue"},
            {"text": "like, really, really long", "color": "yellow"},
            {"text": "like whoa"}
        ]
```

The commands in sphinx are handled by [pygments](https://github.com/pygments/pygments), a python-based syntax highlighter. You can explore how `mcfunction` gets highlighted by checking out the project and testing out the highlighter by itself!

In terms of how we control multi-line commands:
  - `execute` should stand on it's own lines with each sub-command on their own line
  - Long `json` components can be split as if it's an embedded `.json` file.
  - Other containers such as long selectors or nbt can be treated similar to `.json` files.
  - Embedded files such as loot tables and functions should be written in an indented fashion:

```{code-block} mcfunction
:force:
loot_table minecraft:entity/zombie {"hello": "world"}
function namespace:other:
    command 1
    command 2
```

> All code examples across this documentation are actually based on the [bolt](https://github.com/mcbeet/bolt) format which means they can compile directly into normal commands!

## Endnote

The core of good documentation is based on well written text. While we use use many fancy bells and whistles from Sphinx, there's no need to overcomplicate the purpose of these docs and so don't let that dissuade you from making contributions!

We are always looking to improve our docs so please do not fret to make suggestions and refinements. We will work our best to integrate the best pieces of work so our docs can accurately describe the Smithed ecosystem to the best of our abilities.
