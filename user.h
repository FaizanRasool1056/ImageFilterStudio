#ifndef USER_H 
#define USER_H 
#include <string> 
using namespace std; 
class user
{
  protected: // so that admin and customer can access it
  string username;
  string password;
  public:
    user(); 
    user(string u, string p); 
    virtual ~user(); 
    virtual bool login()    = 0;  // pure virtual 
    virtual void showmenu() = 0;  // pure virtual 
    string getusername() const; 
}; 
#endif 


