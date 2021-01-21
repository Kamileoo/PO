#include <conio.h>
#include <iostream>
#include <vector>
#include <exception>

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
    cout << message << ", rozmiar stosu: " << getMax() << ", element: " << getEl() << endl;
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
        cout << message << endl;
    }
};

class Stack {
private:
    int maxStackSize;
    vector<int> dfs;
    int top;
public:
    Stack();
    Stack(int max);
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
    foo(s);
    cout << "End" << endl;

    try{
        for(int i = 0; i < 8; i++) {
            cin >> n;
            s.push(n);
        }
        for(int i = 0; i < 8; i++) {
            cout << "Ostatnia liczba ze stosu: " << s.pop() << endl;
        }
    }
    catch(StackException &e) {
        e.what();
    }
    catch(exception &e ) {
        e.what();
    }

    return 0;
}

/*
3.  Funkcja używa noexcept, co oznacz, że nie będzie wyrzucała żadnych wyjątków. Używamy jej ponieważ jesteśmy pewni, że nie może zajść żaden błąd.
    Zastosowanie ovverride uniemożliwia skompilowanie kodu, w którym klasa pochodna nie będzie posiadała takiej samej metody wirtualnej co klasa bazowa.
    Override w Javie informuje o tym, że metoda podklasy nadpisuje metodę nadklasy.
*/