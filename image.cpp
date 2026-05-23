#include "image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION 
#include "stb_image_write.h"
#include <iostream>
#include <string>
using namespace std;
// definiton of default constructor
image :: image (int w, int h)
{
    width=w;
    height=h;
    pixels = new pixel*[height];
    for (int i=0;i<height;i++)// DMA allocation to 2-D grid
    {
     pixels[i]=new pixel[width];

    }
    cout<<"image creted with width"<<width<<"and the height"<<height<<endl;
}
// definition of getter
int image::getwidth() const
{
    return width;
}
int image :: getheight() const
{
    return height;
}
pixel& image :: at(int r,int c)
{
    return pixels[r][c];
}
// definition of destructor
image :: ~image(){
    for (int i=0;i<height;i++)// DMA De-allocation to 2-D grid
    {
     delete[] pixels[i];

    }
    delete[] pixels;
    
}
// definitin of copy construtor
image :: image (const image &other)
{
  width =other.width;
  height= other.height;
  pixels = new pixel*[height]; // allocat new mwmory here deep copy made
    for (int i=0;i<height;i++)// new DMA allocation to 2-D gri
    {
     pixels[i]=new pixel[width];

    for (int j=0;j<width;j++)
    {
        pixels [i][j]= other.pixels[i][j]; // copy value 

    }
    }
}
      void image::displayASCII() const
      {
    cout << "=== Preview (" << width << "x" << height << ") ===" << endl;
    for ( int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            cout<<pixels [i][j];
        }
         cout<<endl;// give new row
    }
      }
   void image::save(string path)
   {
    unsigned char* data = new unsigned char[width * height * 3]; 
    for (int i = 0; i < height; i++) { 
        for (int j = 0; j < width; j++) { 
            int idx = (i * width + j) * 3; 
            data[idx]     = pixels[i][j].getR(); 
            data[idx + 1] = pixels[i][j].getG(); 
            data[idx + 2] = pixels[i][j].getB();
             } 
    } 
    stbi_write_png(path.c_str(), width, height, 3, data, width * 3); 
    delete[] data; 
    cout << "Saved: " << path << endl; 
} 
   
















