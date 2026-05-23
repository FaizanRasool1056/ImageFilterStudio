#include "catalogfilemanager.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

catalogfilemanager::catalogfilemanager()
{
    filepath = "catalog.txt";
}

void catalogfilemanager::displaycatalog()
{
    ifstream file(filepath);
    string line;

    cout << "ID | Name              | Category       | Status"  << endl;
    cout << "---------------------------------------------------" << endl;

    while (getline(file, line))
    {
        stringstream ss(line);
        string id, name, cat, enabled;

        getline(ss, id,      '|');
        getline(ss, name,    '|');
        getline(ss, cat,     '|');
        getline(ss, enabled, '|');

        cout << id << "  | " << name << " | " << cat << " | "
             << (enabled == "1" ? "Enabled" : "Disabled") << endl;
    }
}

// ── togglefilter ─────────────────────────────
// reads catalog.txt, flips 1 to 0 or 0 to 1
// for the filter with matching id
// ─────────────────────────────────────────────
void catalogfilemanager::togglefilter(int id)
{
    ifstream fin(filepath);
    string line, newcontent = "";

    while (getline(fin, line))
    {
        stringstream ss(line);
        string fid, name, cat, enabled;

        getline(ss, fid,     '|');
        getline(ss, name,    '|');
        getline(ss, cat,     '|');
        getline(ss, enabled, '|');

        if (stoi(fid) == id)           // stoi converts string "01" to int 1
        {
            enabled = (enabled == "1") ? "0" : "1";  // flip the value
            cout << name << " is now "
                 << (enabled == "1" ? "Enabled" : "Disabled") << endl;
        }

        newcontent += fid + "|" + name + "|" + cat + "|" + enabled + "\n";
    }
    fin.close();

    ofstream fout(filepath);           // rewrite entire file
    fout << newcontent;
}

// ── isenabled ────────────────────────────────
bool catalogfilemanager::isenabled(int id)
{
    ifstream file(filepath);
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string fid, name, cat, enabled;

        getline(ss, fid,     '|');
        getline(ss, name,    '|');
        getline(ss, cat,     '|');
        getline(ss, enabled, '|');

        if (stoi(fid) == id)
            return (enabled == "1");
    }
    return false;
}