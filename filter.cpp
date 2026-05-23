#include "filter.h"
#include <iostream>
#include <string>
using namespace std;
// definition of filter constructor
filter ::filter (int idx, string n,string c)
{
  this->id=idx;
  this ->name=n;
  this ->category=c;
  this ->enabled=true;
}
//definition of fiter destructor
 filter ::~filter()
 {
    cout<<name<<" filter destroyed"<<endl;
 }
 string filter::getname() const
 {
    return name;
 }
 int filter::getid() const
 {
    return id;
 }
 bool filter::isenabled() const
 {
    return enabled;
 }
 void filter::setenabled(bool v) 
 {
    enabled = v;
 }