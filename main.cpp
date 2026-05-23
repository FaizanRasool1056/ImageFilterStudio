#include <iostream>
#include "pixel.h"
#include "image.h"
#include "imageIO.h"
#include "filter.h"
#include "grayscalefilter.h"
#include "redchannelfilter.h"
#include "greenchannelfilter.h"
#include "bluechannelfilter.h"
#include "invertfilter.h"
#include "fliphorizontalfilter.h"
#include "flipverticalfilter.h"
#include "brightnessfilter.h"
#include "filtersession.h"
#include "user.h"
#include "admin.h"
#include "customer.h"
#include "customerfilemanager.h"
#include "catalogfilemanager.h"
#include "sessionfilemanager.h"

using namespace std;
int main()
{
 
int choice; 
while (true) { 
cout << "\n================================" << endl; 
cout << "    IMAGE FILTER STUDIO" << endl; 
cout << "================================" << endl;
 cout << "1. Admin Login" << endl; 
        cout << "2. Customer Login" << endl; 
        cout << "3. Register as Customer" << endl; 
        cout << "4. Exit" << endl; 
        cout << "Your choice: "; cin >> choice; 
 
        if (choice == 1) { 
            admin adm; 
            if (adm.login()) 
                adm.showmenu();     
                  } 
        else if (choice == 2) { 
            customer cust; 
            if (cust.login()) 
                cust.showmenu();     
        } 
        else if (choice == 3) { 
            customer cust; 
            cust.registercustomer(); 
        } 
        else if (choice == 4) { 
            cout << "Goodbye!" << endl; 
            break;
              } 
              else
              cout<<"wrong entry try again"<<endl;
    } 
    return 0; 
} 
