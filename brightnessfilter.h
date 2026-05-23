#ifndef BRIGHTNESSFILTER_H
#define BRIGHTMESSFILTER_H
#include "filter.h"
#include "image.h"
class brightnessfilter : public filter
{ 
    private:
    int amount ;
    
    public:
    brightnessfilter(int amo); // constructor called filter condtructor
    void apply(image &img);// overide pure virtual
};
#endif
