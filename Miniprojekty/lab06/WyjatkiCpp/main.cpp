#include <conio.h>
#include <iostream>
#include <vector>
#include <exception>
#include <string>

using namespace std;

class StackException : public exception{
public:
    StackException() {}
    virtual const char* what() const noexcept override {
        return "Bledna operacja na stosie!";
    }
};

class StackFullException : public StackException {
    int element = 0 ;
    int maxStackSize = 0 ;
    string message;
public :
    StackFullException() {}
    StackFullException(string p, int e, int s) {
        this->element = e;
        this->maxStackSize = s;
        this->message = p;
    }
    int getMax() const {
        return this->maxStackSize;
    }
    int getEl() const {
        return this->element;
    }
    virtual const char* what() const noexcept override {
        string s = message + ", rozmiar stosu: " + to_string(maxStackSize) + ", element: " + to_string(element);
        return s.c_str();
    }
};

class StackEmptyException : public StackException {
    string message;
public :
    StackEmptyException() {}
    StackEmptyException(string p) {
        this->message = p;
    }
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class Stack {
private:
    int maxStackSize;
    vector<int> dfs;
    int top;
public:
    Stack() {}
    Stack(int max) {
        this->maxStackSize = max;
        top = 0;
    }
    void push(int n) {
        if(dfs.size() == maxStackSize) {
            throw StackFullException("Full Stack", n, maxStackSize);
        }
        else {
            dfs.push_back(n);
            top = n;
        }
    }
    int pop() {
        if(dfs.size() == 0) {
            throw StackEmptyException("Stack is empty!");
        }
        else{
            int tmp = dfs.back();
            dfs.pop_back();
            return tmp;
        }
    }
    int maxSize() {
        return maxStackSize;
    }
};

void foo(Stack &s) {
    try{
        for(int i = 0; i < s.maxSize()+2; i++) {
            s.push(i);
        }
    }
    catch (StackException e) {
        cout << e.what() << endl;
    }
};

void bar(Stack &s) {
    try{
        for(int i = 0; i < s.maxSize()+2; i++) {
            s.push(i);
        }
    }
    catch (StackException &e) {
        cout << e.what() << endl;
    }
};



int main() {
    Stack s(5);
    int n = 0;
    //foo(s);
    //bar(s);
    cout << "End" << endl;

    try{
        for(int i = 0; i < 5; i++) {
            cin >> n;
            s.push(n);
        }
        for(int i = 0; i < 8; i++) {
            cout << "Ostatnia liczba ze stosu: " << s.pop() << endl;
        }
    }
    catch(StackException &e) {
        cout << e.what() << endl;
    }
    catch(exception &e ) {
        cout << e.what() << endl;
    }

    return 0;
}

/*
3.  Funkcja używa noexcept, co oznacz, że nie będzie wyrzucała żadnych wyjątków. Używamy jej ponieważ jesteśmy pewni, że nie może zajść żaden błąd.
    Zastosowanie ovverride uniemożliwia skompilowanie kodu, w którym klasa pochodna nie będzie posiadała takiej samej metody wirtualnej co klasa bazowa.
    Override w Javie informuje o tym, że metoda podklasy nadpisuje metodę nadklasy.
5. Zostaje wypisany wyjątek rodzica. Catch otrzymując wyjątek uznaje go za StackException i dla tej klasy wypisuje what().
6. Zostaje wypisany wyjatek dziecka, prawidłowy. Tutaj catch poprawnie rozpoznaje odpowiednią klasę.

*/