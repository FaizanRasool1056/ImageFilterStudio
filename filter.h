#ifndef FILTER_H
#define FILTER_H
#include "image.h"
#include <string>
using  namespace std;
class filter
{
    protected:// not private so that child classes can access whilr outer not
    int id;
    string name;
    string category;
    bool enabled;
    public:
    filter (int idx, string n,string c); // default and paramitized constructor
    virtual ~filter();
    virtual void apply(image &img)=0;// pure virtual
    string getname() const;
    int getid() const;
    bool isenabled() const;
    void setenabled(bool v); // by this we can enable and disbale the filter
    
};
#endif