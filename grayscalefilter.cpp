#include "grayscalefilter.h"
#include "filter.h"
#include "pixel.h"
#include "image.h"
// deinition of child class constuctor using parent class constructor
grayscalefilter::grayscalefilter()
:filter (1, "Grayscale","Pixel Transform") {}
void grayscalefilter::apply(image &img)
{
     for (int i=0;i<img.getheight();i++)
    {
        for (int j=0;j<img.getwidth();j++)
        {
            int avg=(img.at(i,j).getR() + img.at(i,j).getG() + img.at(i,j).getB())/3;
            img.at(i,j).setR(avg);
            img.at(i,j).setG(avg);
            img.at(i,j).setB(avg); 
        }
    }
}