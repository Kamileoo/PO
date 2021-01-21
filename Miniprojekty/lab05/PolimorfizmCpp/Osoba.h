#ifndef OSOBA_H
#define OSOBA_H

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#include "Adres.h"

class Osoba{
public:
    Osoba();
    Osoba(std::string imie, std::string nazwisko);
    Osoba(const Osoba &o);
    Osoba(Osoba &&old);
    virtual ~Osoba();

    void setName(std::string nimie, std::string nnazwisko);
    
    std::string getName();
    std::string getLastName();

    void setBirthdate(int d, int m, int y);
    std::tuple<int, int, int> getBirthdate();

    void setAdress(std::string ulica, int nr, std::string kod, std::string miejscowosc, std::string kraj);
    std::tuple<std::string, int, std::string, std::string, std::string> getAdress();

    virtual void przedstaw();

protected:
    std::string *imie;
    std::string *nazwisko;
    int *birthdate;
    Adres *adres;

};

void przedstaw1(Osoba &os);
void przedstaw2(Osoba *os);

#endif /* !OSOBA_H */