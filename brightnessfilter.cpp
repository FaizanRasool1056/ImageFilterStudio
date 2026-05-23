#include "brightnessfilter.h"
#include "pixel.h"   // for Pixel::clamp()

brightnessfilter::brightnessfilter(int amo)
    : filter(3, "Brightness Adjust", "Pixel Transform")
{
    amount = amo;
}

void brightnessfilter::apply(image &img) {
    int height = img.getheight();
    int width  = img.getwidth();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            int r = img.at(i,j).getR();
            int g = img.at(i,j).getG();
            int b = img.at(i,j).getB();

            // adjust brightness + clamp
            r = pixel::clamp(r + amount);
            g = pixel::clamp(g + amount);
            b = pixel::clamp(b + amount);

            img.at(i,j).setR(r);
            img.at(i,j).setG(g);
            img.at(i,j).setB(b);
        }
    }
}