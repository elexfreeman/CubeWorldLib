/* цвета для куба */
#define c_red 0
#define c_green 1
#define c_blue 0

struct cubeColor
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

class cubeTexture
{
   

public:
    cubeTexture();

     /* rgb */
    cubeColor color;

    cubeColor Sky();
    cubeColor Grass();
    cubeColor Ground();
    cubeColor Lava();
    cubeColor Granite();

private:
};
