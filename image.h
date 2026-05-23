#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <string>
#include "pixel.h" // because we have to make member variable that points to pixel
#include "Saveable.h"// add saveable interface to save images
using namespace std;
class image : public Saveable // implementation of saveable interface
{
private :
pixel **pixels;
int width;// that give columns
int height;// that give rows
public:
// constructor
image(int w,int h);
// destructor
~image();
//getter
int getwidth() const;
int getheight() const;
// to modify pixel directly
pixel& at(int ,int);
// copy constructor to deep copies it
image (const image & other);
// display ascii before in pixel we define the asccii character on the basis of brightnrss
void displayASCII() const;  // const so that while displaying no value changes
void save(string path); // that function full fill saveable contract
};
#endif 