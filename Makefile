build:
	gcc -g -Wall -omain main.c

debug_build:
	gcc -ggdb -g3 -Wall -o ./debug/main main.c