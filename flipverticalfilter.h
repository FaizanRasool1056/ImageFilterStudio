#ifndef FLIPVERTICALFILTER_H
#define FLIPVERTICALFILTER_H
#include "filter.h"
class flipverticalfilter : public filter
{
    public:
    flipverticalfilter(); // constructor called filter condtructor
    void apply(image &img);// overide pure virtual
};
#endif
