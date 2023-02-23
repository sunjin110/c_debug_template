b:
	cmake --build build

product_build:
	gcc -Wall -O3 -omain main.c

release_build:
	cmake --build release_build 

run:
	make b
	./build/main
