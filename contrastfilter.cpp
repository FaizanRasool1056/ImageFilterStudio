#include "contrastfilter.h"
#include "pixel.h"   // for Pixel::clamp()

contrastfilter::contrastfilter()
    : filter(4, "Contrast Stretch", "Pixel Transform") {}
void contrastfilter::apply(image& img) { 
//  find min and max brightness across all pixels 
    int minVal = 255, maxVal = 0; 
    for (int i = 0; i < img.getheight(); i++) { 
        for (int j = 0; j < img.getwidth(); j++) { 
            int r = img.at(i,j).getR(); 
            int g = img.at(i,j).getG(); 
            int b = img.at(i,j).getB(); 
            if (r < minVal) minVal = r; 
            if (g < minVal) minVal = g;
                   if (b < minVal) minVal = b; 
            if (r > maxVal) maxVal = r; 
            if (g > maxVal) maxVal = g; 
            if (b > maxVal) maxVal = b; 
        } 
    } 
    if (maxVal == minVal) return;  // avoid divide by zero 
 
    // Step 2: stretch all values 
    for (int i = 0; i < img.getheight(); i++) 
    { 
        for (int j = 0; j < img.getwidth(); j++)
        { 
            int r = (img.at(i,j).getR() - minVal) * 255 / (maxVal - minVal); 
            int g = (img.at(i,j).getG() - minVal) * 255 / (maxVal - minVal); 
            int b = (img.at(i,j).getB() - minVal) * 255 / (maxVal - minVal); 
            img.at(i,j).setR(r); 
            img.at(i,j).setG(g); 
            img.at(i,j).setB(b);
        }
    }
}