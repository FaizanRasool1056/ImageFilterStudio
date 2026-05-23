#ifndef ADMIN_H 
#define ADMIN_H 
#include "user.h" 
class admin : public user { 
private: 
static string hardcodedpass;
public: 
admin(); 
bool login(); 
void showmenu(); 
void managefiltercatalog(); 
void managecustomers(); 
void viewallsessions();
};
#endif