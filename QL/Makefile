
CFLAGS=-Wc++11-extensions -lncurses -std=gnu++11  -stdlib=libc++

all:
	g++ $(CFLAGS) -c main.cpp
	g++ $(CFLAGS) -c Screen.cpp
	g++ $(CFLAGS) -c MObject.cpp
	g++ $(CFLAGS) -c World.cpp
	g++ $(CFLAGS) -c conf.cpp
	g++ $(CFLAGS) main.o Screen.o MObject.o World.o conf.o -o ql.run
	make clean
	./ql.run


clean:
	rm -rf *.o ql