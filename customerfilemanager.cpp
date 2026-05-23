#include "customerfilemanager.h"
#include <iostream>
#include <fstream>                               // ← added, needed for ifstream ofstream
#include <sstream>
using namespace std;

// ─────────────────────────────────────────
// constructor
// ─────────────────────────────────────────
customerfilemanager::customerfilemanager()
{
    filepath    = "customers.txt";
    blockedpath = "blocked_cnics.txt";
}

// ─────────────────────────────────────────
// check if cnic already exists in file
// ─────────────────────────────────────────
bool customerfilemanager::isregistered(string cnic)
{
    ifstream file(filepath);
    string line;

    while (getline(file, line))
    {
        if (line.substr(0, 13) == cnic)
            return true;
    }
    return false;
}

// ─────────────────────────────────────────
// check if cnic is in blocked list
// ─────────────────────────────────────────
bool customerfilemanager::isblocked(string cnic)
{
    ifstream file(blockedpath);
    string line;

    while (getline(file, line))
    {
        if (line == cnic)
            return true;
    }
    return false;
}

// ─────────────────────────────────────────
// check cnic and password match in file
// ─────────────────────────────────────────
bool customerfilemanager::validatelogin(string cnic, string pass)
{
    ifstream file(filepath);
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string fcnic, fpass;

        getline(ss, fcnic, '|');       // read cnic part
        getline(ss, fpass, '|');       // read password part

        if (fcnic == cnic && fpass == pass)
            return true;
    }
    return false;
}

// ─────────────────────────────────────────
// savecustomer — was MISSING, caused your error
// ─────────────────────────────────────────
void customerfilemanager::savecustomer(string cnic, string pass,
                                        string name, char gender,
                                        string phone, string city)
{
    ofstream file(filepath, ios::app);  // ios::app = add to end of file
                                        // do NOT use without ios::app
                                        // or it will delete all existing data

    file << cnic    << "|"
         << pass    << "|"
         << name    << "|"
         << gender  << "|"
         << phone   << "|"
         << city    << "|"
         << "0"     << "\n";           // 0 = not blocked

    cout << "Customer saved!" << endl;
}

// ─────────────────────────────────────────
// blockcustomer
// ─────────────────────────────────────────
void customerfilemanager::blockcustomer(string cnic)
{
    // Step 1: read all lines, flip 0 to 1 for this cnic
    ifstream fin(filepath);
    string line, newcontent = "";

    while (getline(fin, line))
    {
        if (line.substr(0, 13) == cnic)
            line[line.size() - 1] = '1';   // last char is isblocked flag
        newcontent += line + "\n";
    }
    fin.close();

    // Step 2: rewrite entire file
    ofstream fout(filepath);
    fout << newcontent;

    // Step 3: add to blocked_cnics.txt
    ofstream blockedfile(blockedpath, ios::app);
    blockedfile << cnic << "\n";

    cout << "Customer blocked!" << endl;
}

// ─────────────────────────────────────────
// deletecustomer — was MISSING, caused your error
// ─────────────────────────────────────────
void customerfilemanager::deletecustomer(string cnic)
{
    ifstream fin(filepath);
    string line, newcontent = "";

    while (getline(fin, line))
    {
        if (line.substr(0, 13) != cnic)    // keep all lines EXCEPT this cnic
            newcontent += line + "\n";
    }
    fin.close();

    ofstream fout(filepath);               // rewrite file without deleted line
    fout << newcontent;

    cout << "Customer deleted!" << endl;
}

// ─────────────────────────────────────────
// displayall
// ─────────────────────────────────────────
void customerfilemanager::displayall()
{
    ifstream file(filepath);
    string line;

    cout << "CNIC          | Name           | Blocked" << endl;
    cout << "------------------------------------------------" << endl;

    while (getline(file, line))
    {
        stringstream ss(line);
        string cnic, pass, name, g, phone, city, blocked;

        getline(ss, cnic,    '|');
        getline(ss, pass,    '|');
        getline(ss, name,    '|');
        getline(ss, g,       '|');
        getline(ss, phone,   '|');
        getline(ss, city,    '|');
        getline(ss, blocked, '|');

        cout << cnic << " | " << name << " | " << blocked << endl;
    }
}