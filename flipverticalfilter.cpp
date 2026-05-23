#include "flipverticalfilter.h"
#include "filter.h"
#include "pixel.h"
#include "image.h"
// deinition of child class constuctor using parent class constructor
flipverticalfilter::flipverticalfilter()
:filter (10, "Flip Vertical Filter","Geomatric") {}
void flipverticalfilter::apply(image &img)
{
     int height = img.getheight();
    int width  = img.getwidth();

    for (int i = 0; i < height/2; i++) {
        for (int j = 0; j < width ; j++) {

            // swap top and bottom pixels
            pixel temp = img.at(i, j);
            img.at(i, j) = img.at(height - 1 - i, j);
            img.at(height - 1 - i, j) = temp;
        }
    }
}