#include <conio.h>
#include <iostream>
#include "JednorekiBandyta.h"
#include "Logger.h"

using namespace std;

int main() {
    /*JednorekiBandyta x;
    JednorekiBandyta g =  move(x);
    g.start();
    g.zmiana_kosztu(500);
    g.stop();

    g.start();
    g.zmiana_ostatniej_wygranej(0);
    g.stop();

    g.start();
    g.zmiana_prawdopodobienstwa_wygranej(0.1);
    g.stop();
    
    g.start();
    g.zmiana_procentu(50);
    g.stop();
    
    g.start();
    g.zmiana_puli(0);
    g.stop();
    
    g.start();
    g.zmiana_liczby_gier(0);
    g.stop();
    
    for(int i = 0; i < 10; i++){
        g.start();
        auto [wygrana, kwota] = g.play();
        g.stop();

        if(wygrana) {
            printf("Wygrana, %.2f zl\n", kwota);
        } else {
            printf("Przegrana\n");
        }

    }*/

    JednorekiBandyta g;
    for(int i = 0; i < 10; i++) {
        g.start();
        g.zmiana_kosztu(500);
        g.stop();
        g.display();

        g.start();
        g.zmiana_ostatniej_wygranej(0);
        g.stop();
        g.display();

        g.start();
        g.zmiana_prawdopodobienstwa_wygranej(0.1);
        g.stop();
        g.display();
        
        g.start();
        g.zmiana_procentu(50);
        g.stop();
        g.display();
        
        g.start();
        g.zmiana_puli(0);
        g.stop();
        g.display();
        
        g.start();
        g.zmiana_liczby_gier(0);
        g.stop();
        g.display();
        
        for(int i = 0; i < 10; i++){
            g.start();
            auto [wygrana, kwota] = g.play();
            g.stop();
            g.display();

            if(wygrana) {
                printf("Wygrana, %.2f zl\n", kwota);
            } else {
                printf("Przegrana\n");
            }

        }
    }
    //odczyt_kosztu(5);

    //ilosc_gier(g);
    //ilosc_gier(move(g));
    //odczyt_kosztu2(5);

    //odczyt_kosztu3(g);
    //odczyt_kosztu3(move(g));
    //odczyt_kosztu3(5);

    //odczyt_kosztu4(g);
    //odczyt_kosztu4(move(g));
    //odczyt_kosztu4(5);
    //JednorekiBandyta l;
    //l.log("test");
    return 0;
}


/*
19. W punkcie 15 nie został wykonany konstruktor kopiujący, ponieważ przekazaliśmy obiekt przez referencję. W 16 nie został wykonany konstruktor move,
    ponieważ move(g) przekazał referencję do g. W podpunkcie 17 wykonał się konstruktor z innego obiektu, ponieważ nie istniał żaden inny obiekt.

21. Podpunkt 15 nie wykonuje się konstruktor kopiujący. W 16 i 17 nie może przekazać move(g) oraz 5 jako parametrów, gdyż ta funkcja oczkuje od nas referencji.

23. Dla podpunktu 15 nie da się przekazać obiektu g, ponieważ program oczekuje od nas zmiennej tymczasowej, rvalue. Dla 16 nie wykona się konstruktor move.
    Dla 17 wykonał się konstruktor z innego obiektu.

    JednorekiBandyta &obiekt oczekuje od nas referencji, lvalue.
    JednorekiBandyta &&obiekt oczekuje od nas zmiennych tymczasowych, rvalue.
    const JednorekiBandyta &obiekt przyjmuje natomiast i lvalue jak i rvalue.
26. Nie można z poziomu implementowanej klasy wywołać funkcji log. Wynika to z sposobu dziedziczenia. W C++ istnieją 3 rodzaje dziedziczenia:
    - public: zmienne klasy bazowej są dziedziczone jako takie same zmienne w klasie dziedzicznej
        public -> public
        protected -> protected
        private -> brak dostępu w klasie dziedzicznej
    - protected: zmienne public oraz protected klasy bazowej są dziedziczone jako protected
        public -> protected
        protected -> protected
        private -> brak dostępu w klasie dziedzicznej
    - private:  zmienne public oraz protected klasy bazowej są dziedziczone jako private
        public -> private
        protected -> private
        private -> brak dostępu w klasie dziedzicznej
    
    Domyśle w C++ jeżeli nie poda się sposobu dziedziczenia domyślnie jest to private.
    Dlatego nie można z poziomu obiektu JednorekiBandyta wywołać funkcji publicznej log() klasy Logger.
29. Klasa Logger nie posiada konstruktora domyślnego. Można to zmienić poprzez dodanie domyslej wartości zmiennej debug w kontruktorze Logger.
32. Wielodziedziczenie może spowodować zbytnie skomplikowanie kodu. Każda zmiana kodu może powodować wiele błędów.
    Może to również doprowadzić do tego, że dwie klasy będą posiadały wspólną nadklasę i wspólną podklasę, co może spowodować komplikacje.
    W Javie nie ma wielokrotnego dziedziczenia. Problem ten jest rozwiązany poprzez interfejsy. Każda klasa może posiadać wiele interfejsów.
*/