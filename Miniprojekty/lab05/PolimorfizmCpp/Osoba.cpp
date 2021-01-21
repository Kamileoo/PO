#include "Osoba.h"

Osoba::Osoba() {
    imie = nullptr;
    nazwisko = nullptr;
    birthdate = nullptr;
    adres = nullptr;
}

Osoba::Osoba(std::string imie, std::string nazwisko) {
    *this->imie = imie;
    *this->nazwisko = nazwisko;
    birthdate = nullptr;
    adres = nullptr;
}

Osoba::Osoba(const Osoba &o) {
    imie = o.imie ? new std::string((*o.imie)) : nullptr;
    nazwisko = o.nazwisko ? new std::string((*o.nazwisko)) : nullptr;
    if(o.birthdate) {
        birthdate = new int[3];
        birthdate[0] = o.birthdate[0];
        birthdate[1] = o.birthdate[1];
        birthdate[2] = o.birthdate[2];
    }
    else { birthdate = nullptr; }
    adres = o.adres ? new Adres(*o.adres) : nullptr;
}

Osoba::Osoba(Osoba &&old) {
    imie = old.imie;
    nazwisko = old.nazwisko;
    birthdate = old.birthdate;
    adres = old.adres;

    old.imie = nullptr;
    old.nazwisko = nullptr;
    old.birthdate = nullptr;
    old.adres = nullptr;
}

Osoba::~Osoba() {
    delete imie;
    delete nazwisko;
    delete birthdate;
    delete adres;
}


void Osoba::setName(std::string nimie, std::string nnazwisko) {
    if(!imie){
            imie = new std::string;
    }
    if(!nazwisko){
            nazwisko = new std::string;
    }
    *this->imie = nimie;
    *this->nazwisko = nnazwisko;
}

std::string Osoba::getName() {
    if(!imie) { return "Brak"; }
    else { return *imie; }
}

std::string Osoba::getLastName() {
    if(!nazwisko) { return "Brak"; }
    else { return *nazwisko; }
}

void Osoba::setBirthdate(int d, int m, int y) {
    if(!birthdate) {
        birthdate = new int[3]{0};
    }
    if (d >= 1 && d <= 31) {
        if (m >= 1 && m <= 12) {
            birthdate[0] = d;
            birthdate[1] = m;
            birthdate[2] = y;
        }
        else {std::cout << "Niepoprawny miesiac!"<<std::endl;}
    }
    else {std::cout << "Niepoprawny dzien!"<<std::endl;}
}

std::tuple<int, int, int> Osoba::getBirthdate() {
    if(!birthdate) { return std::make_tuple(0, 0, 0); }
    else { return std::make_tuple(birthdate[0], birthdate[1], birthdate[2]); }
}

void Osoba::setAdress(std::string ulica, int nr, std::string kod, std::string miejscowosc, std::string kraj) {
    if(!adres) {
        adres = new Adres;
    }
    adres->setAdress(ulica, nr, kod, miejscowosc, kraj);
}

std::tuple<std::string, int, std::string, std::string, std::string> Osoba::getAdress() {
    if(!adres) { return std::make_tuple("-", 0, "-", "-", "-"); }
    else { return adres->getAdress(); }
}

void Osoba::przedstaw() {
    std::cout << "Imie: " << getName() << std::endl;
    std::cout << "Nazwisko: " << getLastName() << std::endl;
    std::cout << "Data urodzenia: " << std::get<0>(getBirthdate()) << "." << std::get<1>(getBirthdate()) << "." << std::get<2>(getBirthdate()) << std::endl;
    std::cout << "Adres: ul. " << std::get<0>(getAdress()) << " " << std::get<1>(getAdress())
    << ", " << std::get<2>(getAdress()) << " " << std::get<3>(getAdress())
    << ", " << std::get<4>(getAdress())
    << std::endl;
}

void przedstaw1(Osoba &os) {
    os.przedstaw();
}

void przedstaw2(Osoba *os) {
    os->przedstaw();
}