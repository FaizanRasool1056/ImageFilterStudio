#ifndef FLIPHORIZONTALFILTER_H
#define FLIPHORIZONTALFILTER_H
#include "filter.h"
class fliphorizontalfilter : public filter
{
    public:
    fliphorizontalfilter(); // constructor called filter condtructor
    void apply(image &img);// overide pure virtual
};
#endif
