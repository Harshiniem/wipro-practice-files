/*
Purpose : Create a binary file–based program to manage student records
          with operations to add, display, update marks using roll
          number and delete a student record.
Author  : Harshinie M
Date    : 05/01/2026
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student {
public:
    int roll;
    char name[30];
    float marks;
};

int main() {
    Student s;
    fstream file("student.dat", ios::in | ios::out | ios::binary | ios::app);

    // ADD STUDENT
    s.roll = 101;
    strcpy(s.name, "Anu");
    s.marks = 85;
    file.write((char*)&s, sizeof(s));

    file.close();

    // READ ALL STUDENTS
    ifstream fin("student.dat", ios::binary);
    while (fin.read((char*)&s, sizeof(s)))
        cout << s.roll << " " << s.name << " " << s.marks << endl;
    fin.close();

    return 0;
}

