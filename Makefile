all:
	g++ -Wall -g main.cpp perlinNoise/* core/* -o main.o

ql:
	g++ -lncurses -std=gnu++11  -stdlib=libc++ -Wall -g ql.cpp -o ql.o

qlrun:
	g++ -lncurses -std=gnu++11  -stdlib=libc++ -Wall -g ql.cpp QL/Screen.h -o ql.o && ./ql.o

qlrun1:
	g++ -lncurses -std=gnu++11  -stdlib=libc++ -Wall -E ./QL/main.cpp ./QL/Screen.cpp ./QL/MObject.cpp > ql.cpp
	g++ -lncurses -std=gnu++11  -stdlib=libc++ -g ql.cpp -o ql.o && ./ql.o

keysrun:
	g++ -lncurses -std=gnu++11  -stdlib=libc++ -Wall -g keys.cpp -o keys.o && ./keys.o

run : 
	./main.o
