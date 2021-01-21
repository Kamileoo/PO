#ifndef ADRES_H
#define ADRES_H

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

class Adres{
public:
    Adres();
    Adres(const Adres &a);
    Adres(Adres &&a);
    Adres(std::string ulica, int nr, std::string kod, std::string miejscowosc, std::string kraj);
    ~Adres();

    void setAdress(std::string nulica, int nnr, std::string nkod, std::string nmiejscowosc, std::string nkraj);
    std::tuple<std::string, int, std::string, std::string, std::string> getAdress();

    std::string getUlica();
    int getNr();
    std::string getKod();
    std::string getMiejscowosc();
    std::string getKraj();

protected:
    std::string *ulica;
    int *nr;
    std::string *kod;
    std::string *miejscowosc;
    std::string *kraj;
};

#endif /* !ADRES_H */