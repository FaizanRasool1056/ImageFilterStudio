#include "redchannelfilter.h"
#include "filter.h"
#include "pixel.h"
#include "image.h"
// deinition of child class constuctor using parent class constructor
redchannelfilter::redchannelfilter()
:filter (5, "Redchannel Filter","Pixel Transform") {}
void redchannelfilter::apply(image &img)
{
     for (int i=0;i<img.getheight();i++)
    {
        for (int j=0;j<img.getwidth();j++)
        {
           
           
            img.at(i,j).setG(0);
            img.at(i,j).setB(0); 
        }
    }
}