#include <iostream>
using namespace std;
 
 
class Osoba{
public:	
	void ustawImie(string imie){
		this->imie = imie;
	}
	virtual string przedstaw(){
		return this->imie;
	}
	//virtual void funkcja() = 0;   //  metoda czysto wirtualna,
protected:
	string imie;
};
 
class Student: public Osoba{
public:
	 string przedstaw(){
		return this->imie + " student";
	}
	void funkcja(){
 
	}
};
 
 
int main(){
	Osoba a;
	Student b;
}