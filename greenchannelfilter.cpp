#include "greenchannelfilter.h"
#include "filter.h"
#include "pixel.h"
#include "image.h"
// deinition of child class constuctor using parent class constructor
greenchannelfilter::greenchannelfilter()
:filter (6, "Greenchannel Filter","Pixel Transform") {}
void greenchannelfilter::apply(image &img)
{
     for (int i=0;i<img.getheight();i++)
    {
        for (int j=0;j<img.getwidth();j++)
        {
           
           
            img.at(i,j).setR(0);
            img.at(i,j).setB(0); 
        }
    }
}