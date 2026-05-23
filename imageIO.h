#ifndef IMAGEIO_H
#define IMAGEIO_H
#include "image.h"
#include <string>
class imageIO
{
    public:
    static image* loadimage(string path); // make static so that cal wihoit object
    static image* generatetestpattern();

};
#endif