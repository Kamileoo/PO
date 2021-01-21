#include "Pracownik.h"

Pracownik::Pracownik(){
    lista = nullptr;
}

Pracownik::Pracownik(vector<string> v){
    lista = new vector<string>(v);
}

Pracownik::~Pracownik(){
    std::cout << "Destroyed!" << std::endl;
    if(lista){
        lista->clear();
        vector<string>().swap(*lista);
        lista = nullptr;
    }
}

Pracownik::Pracownik(const Pracownik &p) : Osoba(p) {
    if(p.lista){ lista = new vector<string>((*p.lista)); }
    else { lista = nullptr; }
}

Pracownik::Pracownik(Pracownik &&p) : Osoba(move(p)){
    lista = p.lista;
    p.lista = nullptr;
}

void Pracownik::dodanie_przedmiotu(string przedmiot) {
    if(!lista) { lista = new vector<string>; }
    if( find((*lista).begin(), (*lista).end(), przedmiot) == (*lista).end() ) { (*lista).push_back(przedmiot); }
}

void Pracownik::usuniecie_przedmiotu(string przedmiot) {
    if(lista) {
        auto it = find((*lista).begin(), (*lista).end(), przedmiot);
        if( it != (*lista).end() ) {
            (*lista).erase(it);
        }
    }
}

bool Pracownik::czy_prowadzi(string przedmiot) {
    if(!lista) { return false; }
    else if( find((*lista).begin(), (*lista).end(), przedmiot) != (*lista).end() ) { return true; }
    else { return false; }
}

void Pracownik::listaPrzedmiotow() {
    cout << "Lista przedmiotow: ";
    if(!lista) { cout << "Brak"; }
    else {
        for(auto& el : (*lista)) {
            if(el == (*lista).back() ) { cout << el << endl; }
            else { cout << el << ", "; }
        }
    }
}

void Pracownik::przedstaw() {
    //Osoba::przedstaw();
    std::cout << "Imie: " << getName() << std::endl;
    std::cout << "Nazwisko: " << getLastName() << std::endl;
    std::cout << "Data urodzenia: " << std::get<0>(getBirthdate()) << "." << std::get<1>(getBirthdate()) << "." << std::get<2>(getBirthdate()) << std::endl;
    std::cout << "Adres: ul. " << std::get<0>(getAdress()) << " " << std::get<1>(getAdress())
    << ", " << std::get<2>(getAdress()) << " " << std::get<3>(getAdress())
    << ", " << std::get<4>(getAdress())
    << std::endl;
    cout << "Status: pracownik" << endl;
    listaPrzedmiotow();
}