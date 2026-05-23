#include "sessionfilemanager.h"
#include <iostream>
#include <fstream>
using namespace std;
sessionfilemanager::sessionfilemanager()
{
    filepath = "sessions.txt";        // all sessions stored here
}
// Append new session to file
void sessionfilemanager::appendsession(string cnic, string timestamp,string filters,string outputfile)
{
    ofstream file("sessions.txt", ios::app);

    if (!file) {
        cout << "Error: cannot open sessions.txt" << endl;
        return;
    }

    file << cnic << "|" << timestamp << "|"
         << filters << "|" << outputfile << "\n";

    file.close();
}

// Display sessions for a specific CNIC
void sessionfilemanager::displayforcnic(string cnic)
{
    ifstream file("sessions.txt");

    if (!file) {
        cout << "Error: sessions.txt not found!" << endl;
        return;
    }

    string line;
    bool found = false;

    cout << "=== Your Session History ===" << endl;

    while (getline(file, line)) {
        // check if CNIC matches first 13 characters
        if (line.substr(0, 13) == cnic) {
            cout << line << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No sessions found." << endl;

    file.close();
}
void sessionfilemanager::displayall()
{
    ifstream file(filepath);
    string line;

    cout << "=== All Sessions ===" << endl;

    if (file.peek() == EOF)          // check if file is empty
    {
        cout << "No sessions recorded yet." << endl;
        return;
    }

    while (getline(file, line))
        cout << line << endl;
}