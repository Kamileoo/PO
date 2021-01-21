#include "Student.h"

Student::Student(){
    lista = nullptr;
}

Student::Student(string nazwa, float ocena) {
    lista = new unordered_map<string, vector<float>>;
    (*lista)[nazwa].push_back(ocena);
}

Student::~Student(){
    if(lista) {
        for ( auto &it: (*lista) ) {
            it.second.clear();
            vector<float>().swap(it.second);
        }
        lista->clear();
        unordered_map<string, vector<float>>().swap(*lista);
        lista = nullptr;
    }
}

Student::Student(const Student &s) : Osoba(s) {
    if(s.lista) {
        lista = new unordered_map<string, vector<float>>;
        for(auto const &[key, value] : *s.lista) {
            for(int i = 0; i < value.size(); i++) {
                (*lista)[key].push_back((*s.lista)[key][i]);
            }
        }
    }
}

Student::Student(Student &&s) : Osoba(move(s)) {
    lista = s.lista;
    s.lista = nullptr;
}

void Student::dodanieOceny(string prz, float ocena) {
    if(ocena < 1 || ocena > 5) { cout << "Zla ocena!" << endl; }
    else {
        if(!lista) { lista = new unordered_map<string, vector<float>>; }
        if((*lista)[prz].empty()) { (*lista)[prz].push_back(ocena); }
        else { (*lista)[prz][0] = ocena; }
    }
    //return find_if(lista_ocen.begin(), lista_ocen.end(), [prz](const przedmiot& p) { return p.nazwa == prz; }) != lista_ocen.end();
}

float Student::odczytanie_oceny(string prz) {
    if(!lista) { return 0; }
    else if((*lista)[prz].empty()) { return 0; }
    else { return (*lista)[prz][0]; }
}

void Student::odczytanie_listy() {
    cout << "Lista ocen: " << endl;
    if(!lista) { cout << "Brak"; }
    else {
        for(auto& el : *lista) {
            cout << "-> " << el.first << ": ";
            if(el.second.empty()) { cout << "Brak oceny" << endl; }
            else { cout << el.second[0] << endl; }
        }
    }
}

void Student::przedstaw() {
    //Osoba::przedstaw();
    std::cout << "Imie: " << getName() << std::endl;
    std::cout << "Nazwisko: " << getLastName() << std::endl;
    std::cout << "Data urodzenia: " << std::get<0>(getBirthdate()) << "." << std::get<1>(getBirthdate()) << "." << std::get<2>(getBirthdate()) << std::endl;
    std::cout << "Adres: ul. " << std::get<0>(getAdress()) << " " << std::get<1>(getAdress())
    << ", " << std::get<2>(getAdress()) << " " << std::get<3>(getAdress())
    << ", " << std::get<4>(getAdress())
    << std::endl;
    cout << "Status: student" << endl;
    odczytanie_listy();
}