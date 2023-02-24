b:
	# ↓CMakeLists.txtが、新しいファイルを見つけることができるようにする
	touch CMakeLists.txt
	cmake --build build

product_build:
	gcc -Wall -O3 -omain main.c

release_build:
	cmake --build release_build 

run:
	make b
	./build/main

clean:
	cmake --build build --target clean
	