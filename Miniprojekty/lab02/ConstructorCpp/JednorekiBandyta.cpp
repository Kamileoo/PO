#include "JednorekiBandyta.h"

using namespace std;

JednorekiBandyta::JednorekiBandyta(){
    koszt_jednej_gry = nullptr;
    procent_do_puli = nullptr;
    prawdopodobienstwo_wygranej = nullptr;
    pula = nullptr;
    liczba_rozegranych_gier = nullptr;
    ostatna_wygrana = nullptr;

    gen = nullptr;
    dis = nullptr;
}

JednorekiBandyta::JednorekiBandyta(float nowy_koszt){
    koszt_jednej_gry = new float(nowy_koszt);
    procent_do_puli = nullptr;
    prawdopodobienstwo_wygranej = nullptr;
    pula = nullptr;
    liczba_rozegranych_gier = nullptr;
    ostatna_wygrana = nullptr;

    gen = nullptr;
    dis = nullptr;
}

JednorekiBandyta::JednorekiBandyta(const JednorekiBandyta &old){
    koszt_jednej_gry = old.koszt_jednej_gry ? new float(*old.koszt_jednej_gry) : nullptr;
    procent_do_puli = old.procent_do_puli ? new float(*old.procent_do_puli) : nullptr;
    prawdopodobienstwo_wygranej = old.prawdopodobienstwo_wygranej ? new float(*old.prawdopodobienstwo_wygranej) : nullptr;
    pula = old.pula ? new float(*old.pula) : nullptr;
    liczba_rozegranych_gier = old.liczba_rozegranych_gier ? new float(*old.liczba_rozegranych_gier) : nullptr;
    ostatna_wygrana = old.ostatna_wygrana ? new float(*old.ostatna_wygrana) : nullptr;

    gen = old.gen ? new mt19937_64(*old.gen) : nullptr;
    dis = old.dis ? new uniform_real_distribution<float>(*old.dis) : nullptr;
}

JednorekiBandyta::JednorekiBandyta(JednorekiBandyta &&old) {
    koszt_jednej_gry = old.koszt_jednej_gry;
    procent_do_puli = old.procent_do_puli;
    prawdopodobienstwo_wygranej = old.prawdopodobienstwo_wygranej;
    pula = old.pula;
    liczba_rozegranych_gier = old.liczba_rozegranych_gier;
    ostatna_wygrana = old.ostatna_wygrana;
    dis = old.dis;
    gen = old.gen;

    old.koszt_jednej_gry = nullptr;
    old.procent_do_puli = nullptr;
    old.prawdopodobienstwo_wygranej = nullptr;
    old.pula = nullptr;
    old.liczba_rozegranych_gier = nullptr;
    old.ostatna_wygrana = nullptr;
    old.dis = nullptr;
    old.gen = nullptr;
}

JednorekiBandyta::~JednorekiBandyta(){
    if(koszt_jednej_gry != nullptr) {
        delete koszt_jednej_gry;
    }
    if(procent_do_puli != nullptr) {
        delete procent_do_puli;
    }
    if(prawdopodobienstwo_wygranej != nullptr) {
        delete prawdopodobienstwo_wygranej;
    }
    if(pula != nullptr) {
        delete pula;
    }
    if(liczba_rozegranych_gier != nullptr) {
        delete liczba_rozegranych_gier;
    }
    if(ostatna_wygrana != nullptr) {
        delete ostatna_wygrana;
    }

    delete gen;
    delete dis;
}

bool JednorekiBandyta::zmiana_kosztu(float nowy){
    log("zmiana_kosztu");
    if(nowy>0){
        if(!koszt_jednej_gry){
            koszt_jednej_gry = new float;
        }
        *koszt_jednej_gry = nowy;
        return true;
    }
    return false;
}

float JednorekiBandyta::odczytanie_kosztu() const {
    log("odczytanie_kosztu");
    return *koszt_jednej_gry;
}

bool JednorekiBandyta::zmiana_procentu(float nowy){
    log("zmiana_procentu");
    if(nowy >= 1 && nowy <= 70){
        if(procent_do_puli == nullptr) {
            procent_do_puli = new float;
        }
        *procent_do_puli = nowy;
        stop();
        return true;
    }
    return false;
}

bool JednorekiBandyta::zmiana_prawdopodobienstwa_wygranej(float nowy){
    log("zmiana_prawdopodobienstwa_wygranej");
    if(nowy >= 0.1 && nowy <= 0.2){
        if(prawdopodobienstwo_wygranej == nullptr) {
            prawdopodobienstwo_wygranej = new float;
        }
        *prawdopodobienstwo_wygranej = nowy;
        return true;
    }
    return false;
}

float JednorekiBandyta::odczytanie_procentu_do_puli() const {
    log("odczytanie_procentu_do_puli");
    return *procent_do_puli;
}

float JednorekiBandyta::odczytanie_puli() const {
    log("odczytanie_puli");
    return *pula;
}

float JednorekiBandyta::odczytanie_liczby_rozegranych_gier() const {
    log("odczytanie_liczby_rozegranych_gier");
    return *liczba_rozegranych_gier;
}

float JednorekiBandyta::odczytanie_ostatniej_wygranej() const {
    log("odczytanie_ostatniej_wygranej");
    return *ostatna_wygrana;
}

bool JednorekiBandyta::zmiana_ostatniej_wygranej(float nowy){
    log("zmiana_ostatniej_wygranej");
    if(nowy >=0){
        if(ostatna_wygrana == nullptr) {
            ostatna_wygrana = new float;
        }
        *ostatna_wygrana = nowy;
        return true;
    }
    return false;
}

bool JednorekiBandyta::zmiana_puli(float nowy){
    log("zmiana_puli");
    if(nowy>=0){
        if(pula == nullptr){
            pula = new float;
        }
        *pula = nowy;
        return true;
    }
    return false;
}

bool JednorekiBandyta::zmiana_liczby_gier(float nowy){
    log("zmiana_liczby_gier");
    if(nowy>=0){
        if(liczba_rozegranych_gier == nullptr){
            liczba_rozegranych_gier = new float;
        }
        *liczba_rozegranych_gier = nowy;
        return true;
    }
    return false;
}

pair<bool, float> JednorekiBandyta::play(){
    log("play");
    *pula += *koszt_jednej_gry * (*procent_do_puli/100);
    (*liczba_rozegranych_gier)++;

    if(!gen) { gen = new mt19937_64 { (long long unsigned int)chrono::high_resolution_clock::now().time_since_epoch().count() }; }
    if(!dis) { dis = new uniform_real_distribution<float>(0, 1); }
    float rand = (*dis)(*gen);

    if(rand <= *prawdopodobienstwo_wygranej){
        *ostatna_wygrana = *pula;
        float tmp_pula = *pula;
        *pula = 0;
        return make_pair(true, tmp_pula);
    }
    return make_pair(false, 0);
}

void JednorekiBandyta::zmiana_debug(bool debug) {
    this->debug = debug;
}

void odczyt_puli(JednorekiBandyta obiekt) {
    cout << "Obecna pula wynosi: " << obiekt.odczytanie_puli() << " zl" << endl;
}

void odczyt_kosztu(JednorekiBandyta obiekt) {
    cout << "Obecny koszt wynosi: " << obiekt.odczytanie_kosztu() << " zl" << endl;
}

void ilosc_gier(const JednorekiBandyta &obiekt) {
    cout << "Odczyt ilosci gier: " << obiekt.odczytanie_liczby_rozegranych_gier() << endl;
}

void odczyt_kosztu2(const JednorekiBandyta &obiekt) {
    cout << "Obecny koszt wynosi: " << obiekt.odczytanie_kosztu() << " zl" << endl;
}

void odczyt_kosztu3(JednorekiBandyta &obiekt) {
    cout << "Obecny koszt wynosi: " << obiekt.odczytanie_kosztu() << " zl" << endl;
}

void odczyt_kosztu4(JednorekiBandyta &&obiekt) {
    cout << "Obecny koszt wynosi: " << obiekt.odczytanie_kosztu() << " zl" << endl;
}