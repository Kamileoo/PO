#ifndef JB_H
#define JB_H

#include <iostream>
#include <random>
#include <conio.h>
#include <chrono>
#include "Logger.h"
#include "Stopper.h"

using namespace std;

class JednorekiBandyta : Logger, public Stopper {
public:
    JednorekiBandyta();
    JednorekiBandyta(float nowy_koszt);
    JednorekiBandyta(const JednorekiBandyta &old);
    JednorekiBandyta(JednorekiBandyta &&old);
    ~JednorekiBandyta();

    bool zmiana_kosztu(float nowy);

    float odczytanie_kosztu() const;

    bool zmiana_procentu(float nowy);

    bool zmiana_prawdopodobienstwa_wygranej(float nowy);

    float odczytanie_procentu_do_puli() const;

    float odczytanie_puli() const;

    float odczytanie_liczby_rozegranych_gier() const;

    float odczytanie_ostatniej_wygranej() const;

    bool zmiana_ostatniej_wygranej(float nowy);

    bool zmiana_puli(float nowy);

    bool zmiana_liczby_gier(float nowy);
    
    pair<bool, float> play();

    void zmiana_debug(bool debug);

private:
    float *koszt_jednej_gry;
    float *procent_do_puli;
    float *prawdopodobienstwo_wygranej;
    float *pula;
    float *liczba_rozegranych_gier;
    float *ostatna_wygrana;

    mt19937_64 *gen;
    uniform_real_distribution<float> *dis;
};

void odczyt_puli(JednorekiBandyta obiekt);
void odczyt_kosztu(JednorekiBandyta obiekt);
void ilosc_gier(const JednorekiBandyta &obiekt);
void odczyt_kosztu2(const JednorekiBandyta &obiekt);
void odczyt_kosztu3(JednorekiBandyta &obiekt);
void odczyt_kosztu4(JednorekiBandyta &&obiekt);

#endif /* !JB_H */