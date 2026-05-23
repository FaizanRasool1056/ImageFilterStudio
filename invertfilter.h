#ifndef INVERTFILTER_H
#define INVERTFILTER_H
#include "filter.h"
class invertfilter : public filter
{
    public:
    invertfilter(); // constructor called filter condtructor
    void apply(image &img);// overide pure virtual
};
#endif
