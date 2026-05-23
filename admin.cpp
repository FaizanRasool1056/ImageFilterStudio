#include "admin.h"
#include "catalogfilemanager.h"
#include "customerfilemanager.h"
#include "sessionfilemanager.h"
#include <iostream> 
using namespace std; 
string admin::hardcodedpass = "Admin1234"; 
admin::admin() : user("admin", hardcodedpass) {}
bool admin::login()
 { 
string u, p; 
cout << "Admin Username: "; cin >> u; 
cout << "Admin Password: "; cin >> p; 
if (u == username && p == password)
 { 
cout << "Admin login successful!" << endl; 
return true;
}
cout << "Wrong credentials!" << endl; 
return false; 
} 
void admin::showmenu()
 { 
  int choice; 
    while (true) { 
        cout << "\n=== ADMIN PANEL ===" << endl; 
        cout << "1. Manage Filter Catalog" << endl; 
        cout << "2. Manage Customers" << endl; 
        cout << "3. View All Sessions" << endl; 
        cout << "4. Logout" << endl; 
        cout << "Choice: "; cin >> choice;
        if (choice == 1)
         {
    managefiltercatalog();
          }
else if (choice == 2) {
    managecustomers();
         }
else if (choice == 3) {
    viewallsessions();
        }
else if (choice == 4) {
    cout << "Logged out." << endl;
    break;
        }
        else
        cout<<"wrong entry try again"<<endl;
} 
 }
void admin::managefiltercatalog()
   {
     catalogfilemanager cfm;
cfm.displaycatalog();

cout << "enter filter id to toggle (0 to skip): ";
int id; cin >> id;

if (id != 0) cfm.togglefilter(id);
    } 
void admin::managecustomers()    
    {
            customerfilemanager cfm;
        cfm.displayall();

        cout << "1. block customer  2. delete customer  3. back" << endl;
        int c; cin >> c;

        if (c == 1) {
            string cnic; cout << "enter cnic: "; cin >> cnic;
            cfm.blockcustomer(cnic);
        }
        else if (c == 2) {
            string cnic; cout << "enter cnic: "; cin >> cnic;
            cfm.deletecustomer(cnic);
        }
    } 
void admin::viewallsessions()  
   {
     sessionfilemanager sfm; 
    sfm.displayall(); 
   }
   