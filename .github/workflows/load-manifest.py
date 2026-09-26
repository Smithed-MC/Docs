import json
import os
from pathlib import Path

import requests
import tomlkit as toml

config_path = Path("zensical.toml")
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

# Load into the Zensical `extra` variables (usable inside docs as `{{ name }}`)
print("Loading into `zensical.toml`")
config = toml.loads(config_path.read_text())
extra = config["project"]["extra"]
for key, version in versions.items():
    extra[key] = version
config_path.write_text(toml.dumps(config))

print("Done!")
