#include "fliphorizontalfilter.h"
#include "filter.h"
#include "pixel.h"
#include "image.h"
// deinition of child class constuctor using parent class constructor
fliphorizontalfilter::fliphorizontalfilter()
:filter (9, "Flip horizontal Filter","Geomatric") {}
void fliphorizontalfilter::apply(image &img)
{
     int height = img.getheight();
    int width  = img.getwidth();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {

            // swap left and right pixels
            pixel temp = img.at(i, j);
            img.at(i, j) = img.at(i, width - 1 - j);
            img.at(i, width - 1 - j) = temp;
        }
    }
}