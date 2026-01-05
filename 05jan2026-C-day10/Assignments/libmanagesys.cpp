/*
Purpose : Create a binary file–based library management system to
          add, issue, return and delete book records.
Author  : Harshinie M
Date    : 05/01/2026
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Library {
public:
    int id;
    char name[30];
    char author[30];
    bool issued;
};

int main() {
    Library b;
    fstream file("library.dat", ios::binary | ios::out | ios::app);

    b.id = 10;
    strcpy(b.name, "DSA");
    strcpy(b.author, "Mark");
    b.issued = false;

    file.write((char*)&b, sizeof(b));
    file.close();

    ifstream fin("library.dat", ios::binary);
    while (fin.read((char*)&b, sizeof(b)))
        cout << b.id << " " << b.name << " " << b.author
             << " " << (b.issued ? "Issued" : "Available") << endl;
    fin.close();

    return 0;
}

