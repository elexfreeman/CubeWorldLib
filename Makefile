all:
	g++ -Wall -g main.cpp perlinNoise/* core/* -o main.o

ql:
	g++ -lncurses -std=gnu++11  -stdlib=libc++ -Wall -g ql.cpp -o ql.o

qlrun:
	g++ -lncurses -std=gnu++11  -stdlib=libc++ -Wall -g ql.cpp -o ql.o && ./ql.o

run : 
	./main.o
