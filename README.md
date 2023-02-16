## c debug vscode template

debugが楽にできるように、# c_debug_template

VSCodeで、`CodeLLDB`の拡張をinstallする必要がある


## cmake

# debug build
```sh
cmake -S . -B build
cmake --build build
```

## release build
```sh
$ cmake -S . -B release_build -DCMAKE_BUILD_TYPE=Release
$ cmake --build release_build
```