#ifndef PIXEL_H
#define PIXEL_H
#include <iostream>
using namespace std;
class pixel
{
    private:// store pixel color
    int r;
    int g;
    int b;

    public:
    // constructor
    pixel();
    pixel(int a,int d,int c);
    // getter
    int getR() const;
    int getG() const;
    int getB() const;
    // setter
    void setR(int v);
    void setG(int v);
    void setB(int v);
    // static clamp
    static int clamp(int v);// make values in between 0 and 255
    //  convert each pixel in ascci representation
    char toASCII() const;
    // add opertor
    pixel operator+(const pixel&p) const;
    // offstream function
    friend ostream& operator<<(ostream & out, const pixel &p);
































};
#endif