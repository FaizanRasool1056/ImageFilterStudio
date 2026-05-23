#include "pixel.h"

// constructor definations
pixel :: pixel()
{
    r=0;
    g=0;
    b=0;
}
pixel :: pixel(int a,int d,int c)
{ 
    this->r=a;
    this->g=d;
    this->b=c;
}
//  getters defination
int pixel :: getR() const
{
    return r;
}
int pixel :: getG() const
{
    return g;
}
int pixel :: getB() const
{
    return b;
}
// setter definations
void pixel :: setR(int v)
{
    r=v;
}
void pixel :: setG(int v)
{
    g=v;
}
void pixel :: setB(int v)
{
    b=v;
}
// static definitions
int pixel :: clamp(int v)
{
    if (v<0)
    return 0;
    if (v>255)
    return 255;

    return v;
}
// definition of Ascci function
char pixel :: toASCII() const
{
    int brightness=( r+g+b)/3;
    if(brightness == 0)
    return ' ';
    if(brightness < 32)
    return '.';
    if(brightness < 64)
    return ':';
    if(brightness < 96)
    return '.';
    if(brightness < 128)
    return '-';
    if(brightness < 160)
    return '=';
    if(brightness < 192)
    return '+';
    if(brightness < 224)
    return '*';
    if(brightness < 240)
    return '#';
    if(brightness > 224 && brightness < 256 )
    return '@';
    
}
// definition of and operator
pixel pixel::operator+(const pixel &p) const 
{
    return pixel(clamp(r+p.r),
       clamp(g+p.g),
    clamp(b+p.b)
     );
}
// definition of <<opertor
ostream& operator<<(ostream& out, const pixel& p)
{
    out << p.toASCII();   
    return out;           
}
