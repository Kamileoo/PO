#include <iostream>
#include <random>
#include <conio.h>
#include <chrono>

using namespace std;

class JednorekiBandyta{
public:
    JednorekiBandyta(){
        koszt_jednej_gry = 500;
        procent_do_puli = 50;
        prawdopodobienstwo_wygranej = 0.1;
        pula = 0;
        liczba_rozegranych_gier = 0;
        ostatna_wygrana = 0;

        gen = mt19937_64 { (long long unsigned int)chrono::high_resolution_clock::now().time_since_epoch().count() };
        dis = uniform_real_distribution<float>(0, 1);
    }

    bool zmiana_kosztu(float nowy){
        if(nowy>0){
            koszt_jednej_gry = nowy;
            return true;
        }
        return false;
    }

    float odczytanie_kosztu(){
        return koszt_jednej_gry;
    }

    bool zmiana_procentu(float nowy){
        if(nowy >= 1 && nowy <= 70){
            procent_do_puli = nowy;
            return true;
        }
        return false;
    }

    bool zmiana_prawdopodobienstwa_wygranej(float nowy){
        if(nowy >= 0.1 && nowy <= 0.2){
            prawdopodobienstwo_wygranej = nowy;
            return true;
        }
        return false;
    }

    float odczytanie_procentu_do_puli(){
        return procent_do_puli;
    }

    float odczytanie_puli(){
        return pula;
    }

    float odczytanie_liczby_rozegranych_gier(){
        return liczba_rozegranych_gier;
    }

    float odczytanie_ostatniej_wygranej(){
        return ostatna_wygrana;
    }

    bool zmiana_ostatniej_wygranej(float nowy){
        if(nowy >=0){
            ostatna_wygrana = nowy;
            return true;
        }
        return false;
    }
    
    pair<bool, float> play(){
        pula += koszt_jednej_gry * (procent_do_puli/100);
        liczba_rozegranych_gier++;

        float rand = dis(gen);

        if(rand <= prawdopodobienstwo_wygranej){
            ostatna_wygrana = pula;
            float tmp_pula = pula;
            pula = 0;
            return make_pair(true, tmp_pula);
        }
        return make_pair(false, 0);
    }

private:
    float koszt_jednej_gry;
    float procent_do_puli;
    float prawdopodobienstwo_wygranej;
    float pula;
    float liczba_rozegranych_gier;
    float ostatna_wygrana;

    mt19937_64 gen;
    uniform_real_distribution<float> dis;
};

int main(){
    JednorekiBandyta g;
    for(int i = 0; i < 100; i++){

        auto [wygrana, kwota] = g.play();

        if(wygrana) {
            printf("Wygrana, %.2f zl\n", kwota);
        } else {
            printf("Przegrana\n");
        }

    }
    return 0;
}