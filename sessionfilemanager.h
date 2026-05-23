#ifndef SESSIONFILEMANAGER_H
#define SESSIONFILEMANAGER_H

#include <string>
#include <fstream>
using namespace std;

class sessionfilemanager
{
private:
    string filepath;

public:
    sessionfilemanager();
    void appendsession(string cnic, string timestamp,
                       string filters, string outputfile);
    void displayforcnic(string cnic);
    void displayall();               // ← must be here
};

#endif