#pragma once
/* цвета для куба */
#include "cubeTexture.h"

cubeTexture::cubeTexture()
{
    color.r = 0;
    color.g = 0;
    color.b = 0;
};

cubeColor cubeTexture::Sky()
{
    color.r = 102;
    color.g = 204;
    color.b = 255;
    return color;
};

cubeColor cubeTexture::Grass()
{
    color.r = 153;
    color.g = 255;
    color.b = 153;
    return color;
};

cubeColor cubeTexture::Ground()
{
    color.r = 153;
    color.g = 102;
    color.b = 0;
    return color;
};

cubeColor cubeTexture::Lava()
{
    color.r = 204;
    color.g = 0;
    color.b = 0;
    return color;
};

cubeColor cubeTexture::Granite()
{
    color.r = 255;
    color.g = 153;
    color.b = 102;
    return color;
};