all: ql

CFLAGS=-Wc++11-extensions -lncurses -std=gnu++11  -stdlib=libc++

ql: main.o Screen.o MObject.o
	g++ $(CFLAGS) main.o Screen.o MObject.o config.o World.o -o ql.o
	./ql.o

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

Screen.o: Screen.cpp
	g++ $(CFLAGS) -c Screen.cpp

MObject.o: MObject.cpp
	g++ $(CFLAGS) -c MObject.cpp

config.o: config.h
	g++ $(CFLAGS) -c config.h

World.o: World.cpp
	g++ $(CFLAGS) -c World.cpp


clean:
	rm -rf *.o ql