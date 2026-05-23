#ifndef CUSTOMER_H 
#define CUSTOMER_H 
#include "user.h" 
class customer : public user
 { private: 
    string cnic; 
    string fullname; 
    char   gender; 
    string phone; 
    string city; 
    bool   isblocked; 
    int    loginattempts;
  public: 
     customer(); 
    customer(string cnic, string name, string pass, char gender,  string phone, string city); 
    bool   login(); 
    void   showmenu(); 
    void   registercustomer(); 
    void   viewhistory(); 
    string getcnic() const; 
    bool   getisblocked() const; 
    }; 
#endif
