#ifndef GREENCHANNELFILTER_H
#define GREENCHANNELFILTER_H
#include "filter.h"
class greenchannelfilter : public filter
{
    public:
    greenchannelfilter(); // constructor called filter condtructor
    void apply(image &img);// overide pure virtual
};
#endif
