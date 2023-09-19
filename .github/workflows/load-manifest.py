import json
import os
from pathlib import Path

import requests
import tomlkit as toml

pyproject = Path("pyproject.toml")
url = (
    "https://github.com/Smithed-MC/Libraries/blob/releases/"
    f"{os.environ['MC_VERSION']}/manifest.json?raw=true"
)

# Load manifest from github
print("Getting `manifest.json`")
manifest = json.loads(requests.get(url).content)

# Clean versioning
versions = {
    f"{key.split('smithed.').pop()}_version": version
    for key, version in manifest.items()
    if key.startswith("smithed.")
}

print(versions)

# Load into MyST subsitutions (usable inside docs)
print("Loading into `pyproject.toml`")
config = toml.loads(pyproject.read_text())
config["tool"]["mudkip"]["override"]["myst_substitutions"] |= versions
pyproject.write_text(toml.dumps(config))

print("Done!")
