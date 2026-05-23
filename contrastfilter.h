#ifndef CONTRASTFILTER_H
#define CONTRASTFILTER_H
#include "filter.h"
class contrastfilter : public filter
{
    public:
    contrastfilter(); // constructor called filter condtructor
    void apply(image &img);// overide pure virtual
};
#endif
