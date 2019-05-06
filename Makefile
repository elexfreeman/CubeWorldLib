all:
	g++ -Wall -g main.cpp perlinNoise/* core/* -o main.o
	
run : 
	./main.o
