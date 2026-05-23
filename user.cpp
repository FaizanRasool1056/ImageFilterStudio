#include "user.h"
#include <iostream> 
using namespace std; 
user::user()
{
    username = "";
    password = "";
}
user::user(string u, string p) { 
username = u; 
password = p; 
cout << "User created: " << username << endl; 
} 
user::~user() { 
cout << "User destroyed: " << username << endl; 
} 
string user::getusername() const { return username; }
