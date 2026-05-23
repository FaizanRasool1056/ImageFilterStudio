#ifndef CATALOGFILEMANAGER_H
#define CATALOGFILEMANAGER_H

#include <string>
using namespace std;

class catalogfilemanager
{
private:
    string filepath;

public:
    catalogfilemanager();
    void displaycatalog();
    void togglefilter(int id);      // ← add this
    bool isenabled(int id);         // ← add this
};

#endif
