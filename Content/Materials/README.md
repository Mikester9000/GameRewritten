# Materials Content

Hand-authored material descriptors and Creation-Engine–generated bundle manifests.

## Formats

- `*.material.json` — GameRewritten material descriptor (loaded by `AssetLoader::LoadMaterial`)
  ```json
  {
      "name":   "example",
      "shader": "Shaders/pbr_3d",
      "textures": {
          "albedo": "Textures/example_albedo.png",
          "normal": "Textures/example_normal.png"
      },
      "params": { "roughness": 0.5, "metallic": 0.0, "color": [1, 1, 1, 1] }
  }
  ```

## Note on OBJ/MTL files

`.mtl` files exported by the Creation Engine are placed in `Content/Models/`
alongside their companion `.obj` files.  This is required because the OBJ
format references the MTL by filename only (`mtllib name.mtl`), so the two
files must share a directory for the material to resolve at load time.

## To import after exporting

    python tools/import_assets.py --engine creation --src /path/to/creation_export

See `docs/ASSET_PIPELINE.md` for the full pipeline reference.
