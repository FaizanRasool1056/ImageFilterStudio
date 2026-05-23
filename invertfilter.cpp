#include "invertfilter.h"
#include "filter.h"
#include "pixel.h"
#include "image.h"
// deinition of child class constuctor using parent class constructor
invertfilter::invertfilter()
:filter (2, " Invert Filter","Pixel Transform") {}
void invertfilter::apply(image &img)
{
     for (int i=0;i<img.getheight();i++)
    {
        for (int j=0;j<img.getwidth();j++)
        {
          
            int newR = 255 - img.at(i,j).getR();   
            int newG = 255 - img.at(i,j).getG();
            int newB = 255 - img.at(i,j).getB();

                img.at(i,j).setR(newR);               
                img.at(i,j).setG(newG);
                img.at(i,j).setB(newB);
        }
    }
}