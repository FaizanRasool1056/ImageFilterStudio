#ifndef BLUECHANNELFILTER_H
#define BLUECHANNELFILTER_H
#include "filter.h"
class bluechannelfilter : public filter
{
    public:
    bluechannelfilter(); // constructor called filter condtructor
    void apply(image &img);// overide pure virtual
};
#endif
