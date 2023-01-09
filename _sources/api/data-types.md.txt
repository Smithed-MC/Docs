# Data Types
Reference for structures

## Pack Data
```ts
{
    id: string,              // [REQUIRED] Pack ID
    display: {
        name: string,        // [REQUIRED] Shown name
        description: string, // [REQUIRED] Short description of pack
        webPage: string,     // [OPTIONAL] URL to ReadMe / Markdown
        icon: string,        // [OPTIONAL] URL to image
    },
    categories: string[]     // [OPTIONAL] List of categories 
    versions: Version[]      // [REQUIRED] List of Pack Versions
}
```

## Pack Version Data
```ts
{
    name: string,                // [REQUIRED] Semver ID
    downloads: {
        datapack: string,        // [REQUIRED] URL to datapack download
        resourcepack: string,    // [OPTIONAL] URL to resourcepack download
    },
    dependencies: Dependency[],  // [OPTIONAL] List of dependencies
    supports: string[]           // [REQUIRED] List of supported Minecraft Versions
}
```

## Pack Dependcy Data
```ts
{
    id: string,       // [REQUIRED] Pack specifier in the format <ownerID>:<packID> 
    version: string   // [REQUIRED] Version number
}
```