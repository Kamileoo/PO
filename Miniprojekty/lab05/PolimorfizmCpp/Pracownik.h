#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Osoba.h"

using namespace std;

class Pracownik : public Osoba  {
public:
    Pracownik();
    Pracownik(vector<string> v);
    Pracownik(const Pracownik &p);
    Pracownik(Pracownik &&p);
    ~Pracownik();

    void dodanie_przedmiotu(string przedmiot);
    void usuniecie_przedmiotu(string przemiot);
    bool czy_prowadzi(string przedmiot);
    void listaPrzedmiotow();
    void przedstaw();
protected:
    vector<string> *lista;
};

#endif /* !PRACOWNIK_H */