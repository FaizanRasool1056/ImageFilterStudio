#include "bluechannelfilter.h"
#include "filter.h"
#include "pixel.h"
#include "image.h"
// deinition of child class constuctor using parent class constructor
bluechannelfilter::bluechannelfilter()
:filter (7, "BLuechannel Filter","Pixel Transform") {}
void bluechannelfilter::apply(image &img)
{
     for (int i=0;i<img.getheight();i++)
    {
        for (int j=0;j<img.getwidth();j++)
        {
           
           
            img.at(i,j).setR(0);
            img.at(i,j).setG(0); 
        }
    }
}