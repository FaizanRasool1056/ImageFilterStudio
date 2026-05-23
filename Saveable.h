#ifndef SAVEABLE_H
#define SAVEABLE_H
#include <string>
using namespace std; 
class Saveable { 
public: 
virtual void save(string path) = 0; // pure virtual means it must implement by child and we can not makr its objectg it must override by child class
virtual ~Saveable() {} 
}; 
#endif 
