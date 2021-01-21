#include "Adres.h"

Adres::Adres() {
    this->ulica = nullptr;
    this->nr = nullptr;
    this->kod = nullptr;
    this->miejscowosc = nullptr;
    this->kraj = nullptr;
}

Adres::~Adres() {
    delete ulica;
    delete nr;
    delete kod;
    delete miejscowosc;
    delete kraj;
}

Adres::Adres(const Adres &a) {
    ulica = a.ulica ? new std::string((*a.ulica)) : nullptr;
    nr = a.nr ? new int((*a.nr)) : nullptr;
    kod = a.kod ? new std::string((*a.kod)) : nullptr;
    miejscowosc = a.miejscowosc ? new std::string((*a.miejscowosc)) : nullptr;
    kraj = a.kraj ? new std::string((*a.kraj)) : nullptr;
}

Adres::Adres(Adres &&a) {
    ulica = a.ulica;
    nr = a.nr;
    kod = a.kod;
    miejscowosc = a.miejscowosc;
    kraj = a.kraj;

    a.ulica = nullptr;
    a.nr = nullptr;
    a.kod = nullptr;
    a.miejscowosc = nullptr;
    a.kraj = nullptr;
}

Adres::Adres(std::string ulica, int nr, std::string kod, std::string miejscowosc, std::string kraj) {
    this->ulica = new std::string{ulica};
    this->nr = new int{nr};
    this->kod = new std::string{kod};
    this->miejscowosc = new std::string{miejscowosc};
    this->kraj = new std::string{kraj};
}

void Adres::setAdress(std::string nulica, int nnr, std::string nkod, std::string nmiejscowosc, std::string nkraj) {
    if(!this->ulica) { ulica = new std::string; }
    if(!this->nr) { this->nr = new int; }
    if(!this->kod) { this->kod = new std::string; }
    if(!this->miejscowosc) { this->miejscowosc = new std::string; }
    if(!this->kraj) { this->kraj = new std::string; }
    *this->ulica = nulica;
    *this->nr = nnr;
    *this->kod = nkod;
    *this->miejscowosc = nmiejscowosc;
    *this->kraj = nkraj;
}

std::string Adres::getUlica() {
    if(!ulica) { return "-"; }
    else { return *ulica; }
}

int Adres::getNr() {
    if(!nr) { return 0; }
    else { return *nr; }
}

std::string Adres::getKod() {
    if(!kod) { return "-"; }
    else { return *kod; }
}

std::string Adres::getMiejscowosc() {
    if(!miejscowosc) { 
        return "-"; 
    }
    else { return *miejscowosc; }
}

std::string Adres::getKraj() {
    if(!kraj) { 
        return "-";
    }
    else { return *kraj; }
}

std::tuple<std::string, int, std::string, std::string, std::string> Adres::getAdress() {
    return std::make_tuple(getUlica(), getNr(), getKod(), getMiejscowosc(), getKraj());
}