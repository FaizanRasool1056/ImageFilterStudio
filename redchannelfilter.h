#ifndef REDCHANNELFILTER_H
#define REDCHANNELFILTER_H
#include "filter.h"
class redchannelfilter : public filter
{
    public:
    redchannelfilter(); // constructor called filter condtructor
    void apply(image &img);// overide pure virtual
};
#endif
