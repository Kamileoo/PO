#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class Samochod{
public:
    Samochod(){
        pojemnosc_baku = 0.0;
        poziom_paliwa = 0.0;
        liczba_kilometrow = 0;
        model = "";
    }
    Samochod(float _pojemnosc_baku, string _model){
        pojemnosc_baku = _pojemnosc_baku;
        poziom_paliwa = 0.0;
        liczba_kilometrow = 0;
        model = _model;
    }

    float odczytaj_pojemnosc_baku() const{
        return pojemnosc_baku;
    }

    unsigned int odczytaj_liczba_kilometrow(){
        return liczba_kilometrow;
    }
    void zwieksz_kilometry(unsigned int q){
        this->liczba_kilometrow += q;
    }

    operator bool () const {
        if(this->model != "" && this->pojemnosc_baku > 0){
            return 1;
        }
        else{
            return 0;
        }
    }

    bool operator !() const{
        if(this->model != "" && this->pojemnosc_baku > 0){
            return 1;
        }
        else{
            return 0;
        }
    }

    friend ostream & operator << (ostream &os, const Samochod &samochod){
        os << samochod.model << " " << samochod.poziom_paliwa << "\n";
        return os;
        //friend aby uzyskać dostęp do prywatnych składowych
    }

    bool operator < (const Samochod &samochod) const{
        return this->model < samochod.model;
        // użyto const aby ukazać, że ta funkcja jest tylko do odczytu, nie może modyfikować żadnej zmiennej
    }

    Samochod operator ++ (int){
        Samochod tmp = *this;
        tmp.liczba_kilometrow+=1;
        return tmp;
    }

    Samochod operator |= (const Samochod &samochod){
        Samochod tmp = *this;
        tmp.liczba_kilometrow = tmp.liczba_kilometrow | samochod.liczba_kilometrow;
        return tmp;
    }

    float operator , (const Samochod &samochod){
        return this->liczba_kilometrow + samochod.liczba_kilometrow;
    }

private:
    float pojemnosc_baku;
    float poziom_paliwa;
    unsigned int liczba_kilometrow;
    string model;
};

struct cmp{
  bool operator() (const Samochod &a, const Samochod &b) const{
      return a.odczytaj_pojemnosc_baku() < b.odczytaj_pojemnosc_baku();
  }  
};

int main(){
    Samochod s1(123,"audi");
    Samochod s2(0,"bmw");
    Samochod s3(200,"");

    if(s3){
        cout << "Poprawne";
    }

    if(!s3){
        cout << "Niepoprawne";
    }

    vector<Samochod> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    sort(v.begin(), v.end());
    for(auto it=v.begin(); it!=v.end(); ++it){
        cout<<*it<<endl;
    }

    set<Samochod, cmp> s;
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);
    for(auto it=s.begin(); it!=s.end(); ++it){
        cout<<*it<<endl;
    }
}