#ifndef CUSTOMERFILEMANAGER_H 
#define CUSTOMERFILEMANAGER_H 
#include <string> 
#include <fstream> 
using namespace std; 
class customerfilemanager
 {
    private: 
    string filepath; 
    string blockedpath; 
    public: 
    customerfilemanager(); 
    bool isregistered(string cnic); 
    bool isblocked(string cnic); 
    bool validatelogin(string cnic, string pass); 
    void savecustomer(string cnic, string pass, string name, char gender, string phone, string city); 
    void blockcustomer(string cnic); 
    void deletecustomer(string cnic); 
    void displayall(); 
    }; 
    #endif
