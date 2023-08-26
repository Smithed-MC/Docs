### PackReference
```ts
{
  id: string
  version: string
}
```
### PackCategory
```ts
'Extensive' | 'Lightweight' | 'QoL' | 'Vanilla+' | 'Tech' | 'Magic' | 'Library' | 'Exploration' | 'World Overhaul' | 'No Resource Pack'
```
### MinecraftVersion
```ts
'1.17' | '1.17.1' | '1.18' | '1.18.1' | '1.18.2' | '1.19' | '1.19.4' | '1.20' | '1.20.1'
```
### PackVersion
```ts
{
  name: string
  downloads: {
    datapack: string?
    resourcepack: string?
  }
  supports: MinecraftVersion[]
  dependencies: PackReference[]
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
    downloads: {
      total: number
      today: number
    }
  }
  owner: string
  contributors: string[]
}
```
### PackBundle
```ts
{
  owner: string
  name: string
  version: MinecraftVersion
  packs: PackReference[]
  public: boolean
  uid: string?
}
```
### UserData
```ts
{
  displayName: string
  cleanName: string
  creationTime: number
  uid: string
  pfp: string?
}
```
### SortOptions
```ts
'trending' | 'downloads' | 'alphabetically' | 'newest'
```