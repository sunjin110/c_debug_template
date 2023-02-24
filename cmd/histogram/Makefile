init:
	cmake -S . -B build

b:
	touch CmakeLists.txt
	cmake --build build

run:
	make b
	./build/histogram

test:
	make b
	./build/histogram ./test.txt