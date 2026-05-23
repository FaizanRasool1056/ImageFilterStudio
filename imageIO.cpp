#define STB_IMAGE_IMPLEMENTATION // to load image we need these libraries
#include "imageIO.h"
#include "image.h"
#include <string>
#include "stb_image.h" //// to load image we need these libraries
using namespace std; 
image* imageIO:: loadimage(string path)
{
    int w, h, ch; 
    unsigned char* data = stbi_load(path.c_str(), &w, &h, &ch, 3); 
    if (!data) { 
        cout << "Failed to load: " << path << endl; 
        return nullptr; 
    } 
    image* img = new image(w, h); 
    for (int i = 0; i < h; i++) { 
        for (int j = 0; j < w; j++) { 
            int idx = (i * w + j) * 3; 
            img->at(i, j) = pixel(data[idx], data[idx+1], data[idx+2]); 
        } 
    }
    stbi_image_free(data); 
cout << "Loaded: " << w << "x" << h << endl; 
return img; 

}
image* imageIO::generatetestpattern() { 
image* img = new image(80, 40); 
for (int i = 0; i < 40; i++) 
for (int j = 0; j < 80; j++) 
img->at(i, j) = pixel(j * 3, i * 6, 150); 
return img; 
} 