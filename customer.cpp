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
#include "contrastfilter.h"
#include "filtersession.h"
#include "user.h"
#include "admin.h"
#include "customer.h"
#include "catalogfilemanager.h"
#include "customerfilemanager.h"
#include "sessionfilemanager.h"
#include <iostream>
#include <string>
using namespace std;

customer::customer() : user("", "")
{
    cnic          = "";
    fullname      = "";
    gender        = ' ';
    phone         = "";
    city          = "";
    isblocked     = false;
    loginattempts = 0;
}

bool customer::login()
{
    customerfilemanager cfm;
    string inputcnic, inputpass;
    int attempts = 0;

    while (attempts < 3)
    {
        cout << "CNIC: ";
        cin  >> inputcnic;
        cout << "Password: ";
        cin  >> inputpass;

        if (cfm.isblocked(inputcnic))
        {
            cout << "This account is blocked!" << endl;
            return false;
        }

        if (cfm.validatelogin(inputcnic, inputpass))
        {
            cnic = inputcnic;
            cout << "Login successful! Welcome." << endl;
            return true;
        }

        attempts++;
        cout << "Wrong! Attempts left: " << (3 - attempts) << endl;
    }

    cout << "Too many failed attempts." << endl;
    return false;
}

void customer::showmenu()
{
    image* currentimage = nullptr;
    filtersession* session = new filtersession(cnic);
    int choice;

    while (true)
    {
        cout << "\n=== CUSTOMER PANEL ===" << endl;
        cout << "1. Load Image" << endl;
        cout << "2. Generate Test Pattern" << endl;
        cout << "3. Build and Apply Pipeline" << endl;
        cout << "4. View My History" << endl;
        cout << "5. Logout" << endl;
        cout << "Choice: ";
        cin  >> choice;

        if (choice == 1)
        {
            string path;
            cout << "Enter image path (example: photo.jpg): ";
            cin  >> path;

            currentimage = imageIO::loadimage(path);

            if (currentimage)
            {
                session->setimage(currentimage);
                cout << "Image loaded!" << endl;
                cout << "Size: " << currentimage->getwidth()
                     << "x" << currentimage->getheight() << endl;
                currentimage->displayASCII();
            }
            else
            {
                cout << "Failed to load image!" << endl;
                cout << "Check file is in same folder as program." << endl;
            }
        }
        else if (choice == 2)
        {
            currentimage = imageIO::generatetestpattern();
            session->setimage(currentimage);
            cout << "Test pattern generated!" << endl;
            currentimage->displayASCII();
        }
        else if (choice == 3)
        {
            if (!currentimage)
            {
                cout << "Load an image first!" << endl;
                continue;
            }

            catalogfilemanager cfm;
            cfm.displaycatalog();

            session->clearpipeline();

            int fid;
            while (true)
            {
                cout << "Add filter ID (0 to finish): ";
                cin  >> fid;

                if (fid == 0) break;

                filter* f = nullptr;

                if (fid == 1)
                {
                    f = new grayscalefilter();
                }
                else if (fid == 2)
                {
                    f = new invertfilter();
                }
                else if (fid == 3)
                {
                    int amount;
                    cout << "Enter brightness (-100 to +100): ";
                    cin  >> amount;
                    f = new brightnessfilter(amount);
                }
                else if (fid == 4)
                {
                    f = new contrastfilter();
                }
                else if (fid == 5)
                {
                    f = new redchannelfilter();
                }
                else if (fid == 6)
                {
                    f = new greenchannelfilter();
                }
                else if (fid == 7)
                {
                    f = new bluechannelfilter();
                }
                // else if (fid == 8)
                // {
                //     f = new boxblurfilter();
                // }
                else if (fid == 9)
                {
                    f = new fliphorizontalfilter();
                }
                else if (fid == 10)
                {
                    f = new flipverticalfilter();
                }
                else
                {
                    cout << "Invalid ID! Try again." << endl;
                    continue;
                }

                if (f)
                {
                    session->addfilter(f);
                    cout << "Filter added!" << endl;
                }
            }

            cout << "Applying filters..." << endl;
            session->applypipeline();

            string outfile = cnic + "_output.png";
            session->saveresult(outfile);

            sessionfilemanager sfm;
            sfm.appendsession(cnic, "now",
                              session->getpipelinestr(), outfile);

            cout << "Done! Saved as: " << outfile << endl;
            cout << "Open it in your folder to see result!" << endl;
        }
        else if (choice == 4)
        {
            viewhistory();
        }
        else if (choice == 5)
        {
            cout << "Logged out." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice! Enter 1 to 5." << endl;
        }
    }

    delete session;
    if (currentimage)
    {
        delete currentimage;
    }
}

void customer::registercustomer()
{
    customerfilemanager cfm;
    string ncnic, npass, npass2, nname, nphone, ncity;
    char ngender;

    cout << "Enter CNIC (13 digits): ";
    cin  >> ncnic;

    if (ncnic.length() != 13)
    {
        cout << "CNIC must be exactly 13 digits!" << endl;
        return;
    }

    if (cfm.isregistered(ncnic))
    {
        cout << "CNIC already registered!" << endl;
        return;
    }

    if (cfm.isblocked(ncnic))
    {
        cout << "This CNIC is banned!" << endl;
        return;
    }

    cout << "Password (9 chars, 1 uppercase, 1 digit): ";
    cin  >> npass;

    if (npass.length() != 9)
    {
        cout << "Password must be 9 characters!" << endl;
        return;
    }

    cout << "Confirm Password: ";
    cin  >> npass2;

    if (npass != npass2)
    {
        cout << "Passwords do not match!" << endl;
        return;
    }

    cout << "Full Name: ";
    cin.ignore();
    getline(cin, nname);

    cout << "Gender (M/F/O): ";
    cin  >> ngender;

    cout << "Phone: ";
    cin  >> nphone;

    cout << "City: ";
    cin  >> ncity;

    cfm.savecustomer(ncnic, npass, nname, ngender, nphone, ncity);
    cout << "Registration successful!" << endl;
}

void customer::viewhistory()
{
    sessionfilemanager sfm;
    sfm.displayforcnic(cnic);
}