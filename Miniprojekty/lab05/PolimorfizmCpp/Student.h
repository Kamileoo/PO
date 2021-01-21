#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "Osoba.h"

using namespace std;

class Student : public Osoba  {
public:
    Student();
    Student(string nazwa, float ocena);
    ~Student();
    Student(const Student &s);
    Student(Student &&s);

    void dodanieOceny(string prz, float ocena);
    float odczytanie_oceny(string prz);
    void odczytanie_listy();
    void przedstaw();
protected:
    unordered_map<string, vector<float>> *lista;
};

#endif /* !STUDENT_H */