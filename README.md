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

## 学んだこと
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q13236332263  
c言語には名前空間がないので、名前が被らないように死ぬほど頑張る必要がある