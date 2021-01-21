#include "Osoba.h"
#include "Adres.h"
#include "Student.h"
#include "Pracownik.h"
#include "FabrykaOsob.h"
#include "FabrykaStudentow.h"
#include "FabrykaPracownikow.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
   /* Osoba k;
    k.setName("Kamil", "Ambrozy");
    k.setBirthdate(5, 6, 2000);
    k.setAdress("Pogodna", 52, "62-069", "Paledzie", "Polska");
    //k.przedstaw();
    przedstaw1(k);
    przedstaw2(&k);*/

    /*Student p;

    p.setName("Kamil", "Ambrozy");
    p.setBirthdate(5, 6, 2000);
    p.setAdress("Pogodna", 52, "62-069", "Paledzie", "Polska");

    p.dodanieOceny("Biologia",5);
    p.dodanieOceny("Matma",1);
    p.dodanieOceny("Infa",2);

    p.odczytanie_listy();
    p.przedstaw();

    przedstaw1(p);
    przedstaw2(&p);

    Student ns = p;

    przedstaw1(ns);*/

    /*Pracownik l;
    l.setName("Kamil", "Ambrozy");
    l.setBirthdate(5, 6, 2000);
    l.setAdress("Pogodna", 52, "62-069", "Paledzie", "Polska");

    l.dodanie_przedmiotu("Biologia");
    l.dodanie_przedmiotu("Matma");
    l.dodanie_przedmiotu("Infa");
    l.dodanie_przedmiotu("Fizyka");

    //cout << "Czy prowadzi: " << l.czy_prowadzi("Biologia") << endl;
    //l.przedstaw();

    przedstaw1(l);
    //przedstaw2(&l);

    Pracownik np = l;

    przedstaw1(np);

    Pracownik np2 = move(np);

    przedstaw1(np2);*/

    /*Pracownik *p1 = new Pracownik;
    Osoba *o1 = static_cast<Osoba *>(p1);
    Osoba *o2 = static_cast<Pracownik *>(o1);

    //delete p1;
    //delete o1;
    delete o2;

    Osoba *o3 = new Osoba;
    Pracownik *p2 = static_cast<Pracownik *>(o3);

    delete o3;
    //delete p2;

    Pracownik *p3 = new Pracownik;
    Osoba *o4 = dynamic_cast<Osoba *>(p3);
    //Pracownik *p4 = dynamic_cast<Osoba *>(o4);

    //delete p3;
    delete o4;

    Osoba *o5 = new Osoba;
    Pracownik *p5 = dynamic_cast<Pracownik *>(o5);
    if (p5 == nullptr) std::cout << "Blad rzutowania!" << std::endl;
    else p5->listaPrzedmiotow();

    delete o5;
    delete p5;

    FabrykaStudentow fs;
    Student* s = fs.utworz();

    FabrykaPracownikow fp;
    Pracownik* p = fp.utworz();*/

    std::map<std::string,FabrykaOsob*> m;
    m["pracownik"] = new FabrykaPracownikow();
    m["student"] = new FabrykaStudentow();

    std::vector<Osoba*> tablicaOsob;

    std::string choose = "standard";

    while(choose != "wyjscie") {
        std::cin >> choose;
        if(choose == "pracownik" || choose == "student") {
            tablicaOsob.push_back(m[choose]->utworz());
        }
        else if(choose == "wyswietl") {
            for(auto it : tablicaOsob) {
                it->przedstaw();
                std::cout << endl;
            }
        }
    }

    return 0;
}

/*
12. Program we wszystkich podpunktach wywołał funkcję przedstaw klasy Osoba.
    Klasy Student oraz Pracownik są podklasami klasy Osoba, a więc posiadają wspólne obiekty oraz dziedziczą metody.
    Funkcja przyjmuje obiekt klasy Osoba, i też jej metodę wywoła.
14. Program wywołał metody odpowiadające odpowiednim obiektom. Metoda wirtualna sprawiła, że funkcja wywołała metodę odpowiadającą faktycznej klasie.
15. W: 
    Pracownik *p1 = new Pracownik;
    Osoba *o1 = static_cast<Osoba *>(p1);
    Osoba *o2 = static_cast<Pracownik *>(o1);
    tworzymy pracownika, po czym zamieniamy go na osobę, po czym ponownie zamieniamy go na pracownika, ale przypisując go do wskaźnika typu Osoba, co jest niepoprawne.
    o2 pomimo static_cast na typ Pracownika dalej pozostaje Osobą.

    W:
    Osoba *o3 = new Osoba;
    Pracownik *p2 = static_cast<Pracownik *>(o3);
    zmieniamy osobę na pracownika, co jest poprawne.
16. Osoba *o4 = dynamic_cast<Osoba *>(p3);
    zmienia Pracownika w Osobę, ale metoda wirtualna przedstaw() uruchamia metodę Pracownika.
    Pracownik *p4 = dynamic_cast<Osoba *>(o4);
    Ta zamiana jest niemozliwa, ponieważ próbujemy przekonwertować Osobę na Osobę i przypisać ją do wskaźnika Pracownika.
17. dynamic_cast może dokonać niewłaściwej konwersji, który nie da nullptr jako wyniku.
19.	Nie można skompilować projektu, ponieważ Osoba stała się funkcją czysto wirtualną.
18. Nie można skompilować projektu. Klasa Osoba stała się klasą abstrakcyjną, ponieważ przedstaw() stało się czystą funkcją wirtualną.
19. Klasa Osoba stała się klasą abstrakcyjną. Oznacza to, że nie można utworzyć bezpośrednio obiektu klasy Osoba.
22. Podczas wywołania funkcji delete zostanie wywołany destruktor klasy wskaźnika, do którego został skastowany obiekt. Powoduje to błedy oraz niecałkowite zwolnienie pamięci.
23. Poprzez dodanie virtual zostaje wywołany destruktor odpowiadający klasie obiektu, a nie klasie wskaźnika, np.:
    Osoba *o2 = static_cast<Pracownik *>(o1);
    delet o2;
    Pomimo tego, że wskaźnik mówi, że jest to osoba, to zostanie wyowołany destruktor klasy Pracownik, czyli klasa na jaką obiekt o1 został skastowany.
30. map posiada 2 wartości: key oraz value. w kwadratowych nawiasach podajemy key, a po = podajemy jakie value chcemy do niego przypisać.
    Czyli przypisujemy do danego klucza odpowiednią wartość.
33. Program tworzy odpowiednie obiekty klas: Osoba oraz Pracownik. Po wywołaniu metody przedstaw wywoływana jest odpowiednia metoda przypisana do danej klasy.
    Wynika to z tego powodu, że chociaż obiekt jest przypisany do wskaźnika Osoby,
    dzięki dopiskowi virtual w klasie Obiekt przedstaw oraz w klasie FabrykaOsob utworz wywoływany jest odpowiednia metoda odpowiadająca prawidłowej klasie.
*/