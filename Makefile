all:
	g++ -Wall -g main.cpp perlinNoise/* core/* cubeTexture.cpp -o main.o
	
run : 
	./main.o
