#ifndef GRAYSCALEFILTER_H
#define GRAYSCALEFILTER_H
#include "filter.h"
class grayscalefilter : public filter
{
    public:
    grayscalefilter(); // constructor called filter condtructor
    void apply(image &img);// overide pure virtual
};
#endif
