#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <string>
#include "perlinNoise/PerlinNoise.h"
#include "perlinNoise/ppm.h"
#include "cubeTexture.h"
#include <time.h> 
#include "core/WorldArray.h"

#define PI 3.14159265

#define SCALE 100
#define SCALE_S 0.1
#define SCALE_D 2
using namespace std;


int main()
{

	// Define the size of the image
	unsigned int width = 2048, height = 2048;
	unsigned int kk;

	// Create a PerlinNoise object with the reference permutation vector
	PerlinNoise pn;
	// Create an empty PPM image
	ppm image(width, height);

	string sOut;

	cubeTexture color;


	clock_t start = clock();
	

	for (int jj = 1; jj <= 1; jj++)
	{
		kk = 0;
		for (unsigned int i = 0; i < height; ++i)
		{ // y
			for (unsigned int j = 0; j < width; ++j)
			{ // x
				double x = (double)j / ((double)width);
				double y = (double)i / ((double)height);

				// Typical Perlin noise
				double n = SCALE_D * pn.noise(SCALE_S * width * x / SCALE, SCALE_S * height * y / SCALE, sin(jj * PI / 180));
				//double n = 10*pn.noise(x, y, sin(jj * PI / 180));

				// Wood like structure
				//n = 20 * pn.noise(x, y, 0.8);
				n = n - floor(n);

				if (floor(255 * n) < 100)
				{
					sOut += " ";
					color.Sky();
				}
				else if (floor(255 * n) < 110)
				{
					sOut += "-";
					color.Grass();
				}
				else if (floor(255 * n) < 151)
				{
					sOut += "+";
					color.Ground();
				}

				else if (floor(255 * n) < 200)
				{
					sOut += "L";
					color.Granite();
				}
				else
				{

					sOut += "H";
					color.Lava();
				}

				// Map the values to the [0, 255] interval, for simplicity we use
				// tones of grey
				/* image.r[kk] = floor(255 * n);
				image.g[kk] = floor(255 * n);
				image.b[kk] = floor(255 * n); */
				image.r[kk] = color.color.r;
				image.g[kk] = color.color.g;
				image.b[kk] = color.color.b;

				kk++;
			} //x
			//std::cout << i << "\r\n";
			sOut = "";
			// Save the image in a binary PPM file

		} //y
		
	} //jj
	image.write("figure_8_R.ppm");
	clock_t end = clock();
	double sec = (double)((end - start) / (CLOCKS_PER_SEC)) * 1000;
	printf("The time: %f ms\n", sec);
	//std::cin.get();
	return 0;
}