### PackReference
```ts
{
  id: string
  version: string
}
```
### PackCategory
```ts
'Extensive' | 'Lightweight' | 'QoL' | 'Vanilla+' | 'Tech' | 'Magic' | 'Exploration' | 'World Overhaul' | 'Library' | 'No Resource Pack'
```
### MinecraftVersion
```ts
'1.21.5' | '1.21.5-rc-2' | '1.21.5-rc-1' | '1.21.5-pre-3' | '1.21.5-pre-2' | '1.21.5-pre-1' | '1.21.5-25w10a' | '1.21.5-25w09b' | '1.21.5-25w09a' | '1.21.5-25w08a' | '1.21.5-25w07a' | '1.21.5-25w06a' | '1.21.5-25w05a' | '1.21.5-25w04a' | '1.21.5-25w03a' | '1.21.5-25w02a' | '1.21.4' | '1.21.4-rc3' | '1.21.4-rc2' | '1.21.4-rc1' | '1.21.4-pre3' | '1.21.4-pre2' | '1.21.4-pre1' | '1.21.4-24w46a' | '1.21.4-24w45a' | '1.21.4-24w44a' | '1.21.3' | '1.21.2' | '1.21.2-rc2' | '1.21.2-rc1' | '1.21.2-pre5' | '1.21.2-pre4' | '1.21.2-pre3' | '1.21.2-pre2' | '1.21.2-pre1' | '1.21.2-24w40a' | '1.21.2-24w39a' | '1.21.2-24w38a' | '1.21.2-24w37a' | '1.21.2-24w36a' | '1.21.2-24w35a' | '1.21.2-24w34a' | '1.21.2-24w33a' | '1.21.1' | '1.21' | '1.21-rc1' | '1.21-pre4' | '1.21-pre3' | '1.21-pre2' | '1.21-pre1' | '1.21-24w21a' | '1.21-24w20a' | '1.21-24w19b' | '1.21-24w19a' | '1.21-24w18a' | '1.20.6' | '1.20.5' | '1.20.5-rc3' | '1.20.5-rc2' | '1.20.5-rc1' | '1.20.5-pre4' | '1.20.5-pre3' | '1.20.5-pre2' | '1.20.5-pre1' | '1.20.5-24w14a' | '1.20.5-24w13a' | '1.20.5-24w12a' | '1.20.5-24w10a' | '1.20.5-24w09a' | '1.20.5-23w51b' | '1.20.4' | '1.20.4-rc1' | '1.20.3' | '1.20.3-rc1' | '1.20.3-pre4' | '1.20.2' | '1.20.1' | '1.20' | '1.19.4' | '1.19' | '1.18.2' | '1.18.1' | '1.18' | '1.17.1' | '1.17'
```
### PackVersion
```ts
{
  downloads: {
    datapack: string?
    resourcepack: string?
  }
  dependencies: PackReference[]
  name: string
  supports: MinecraftVersion[]
}
```
### PackData
```ts
{
  id: string
  display: {
    name: string
    description: string
    icon: string
    hidden: boolean
    webPage: string?
    urls: {
      discord: string?
      source: string?
      homepage: string?
    }?
    gallery: {
      type: 'bucket'
      uid: string
      content: string?
    } | {
      type: 'file'
      uid: string
      content: string?
    } | string[]?
  }
  versions: PackVersion[]
  categories: PackCategory[]
}
```
### PackMetaData
```ts
{
  docId: string
  rawId: string
  stats: {
    updated: number?
    added: number
    score: number // Used to calculate which pack is trending
    downloads: {
      total: number
      today: number
      pastWeek: number
    }
  }
  owner: string
  contributors: string[]
}
```
### PackBundle
```ts
{
  schemaVersion: null
  owner: string
  name: string
  version: MinecraftVersion
  packs: PackReference[]
  public: boolean
  uid: string?
} | {
  schemaVersion: 'v2'
  id: string
  uid: string?
  owner: string
  display: {
    name: string
    description: string
    icon: string
    webPage: string?
    urls: {
      discord: string?
      source: string?
      homepage: string?
    }?
  }
  visibility: 'public' | 'unlisted' | 'private'
  versions: {
    patches: {
      datapack: string?
      resourcepack: string?
    }[]
    packs: PackReference[]
    name: string
    supports: MinecraftVersion[]
  }[]
  categories: 'Extensive' | 'Lightweight' | 'QoL' | 'Vanilla+' | 'Tech' | 'Magic' | 'Exploration' | 'World Overhaul' | 'Quest Driven' | 'Multiplayer Focus'[]
}
```
### UserData
```ts
{
  displayName: string
  cleanName: string
  creationTime: number
  uid: string
  pfp: {
    type: 'bucket'
    uid: string
    content: string?
  } | {
    type: 'file'
    uid: string
    content: string?
  } | string?
  banner: {
    type: 'bucket'
    uid: string
    content: string?
  } | {
    type: 'file'
    uid: string
    content: string?
  } | string?
  biography: string?
  role: 'member' | 'admin'
}
```
### SortOptions
```ts
'trending' | 'downloads' | 'alphabetically' | 'newest'
```
### PAToken
```ts
{
  owner: string
  createdAt: number
  expiration: number
  scopes: 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9[]
  tokenUid: string
  name: string
}
```