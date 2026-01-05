/*
Purpose : Maintain a binary file of books and perform create and
          read operations on book records.
Author  : Harshinie M
Date    : 05/01/2026
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Book {
public:
    int id;
    char title[30];
    float price;
};

int main() {
    Book b;
    ofstream fout("books.dat", ios::binary | ios::app);

    b.id = 1;
    strcpy(b.title, "C++ Basics");
    b.price = 450;
    fout.write((char*)&b, sizeof(b));
    fout.close();

    ifstream fin("books.dat", ios::binary);
    while (fin.read((char*)&b, sizeof(b)))
        cout << b.id << " " << b.title << " " << b.price << endl;
    fin.close();

    return 0;
}

