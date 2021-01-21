#include <memory>
#include "Wezel.h"

int main() {
    /*for(int i = 0; i < 10; i++) {
        std::cout << "Przed" << std::endl;
        std::unique_ptr<Wezel>(new Wezel());
        std::cout << "Po" << std::endl;
    }*/

    /*for(int i = 0; i < 10; i++) {
        std::cout << "Przed" << std::endl;
        std::shared_ptr<Wezel> w1 = std::make_shared<Wezel>();
        std::cout << "Po" << std::endl;
    }*/

    /*for(int i = 0; i < 10; i++) {
        std::shared_ptr<Wezel> w1 = std::make_shared<Wezel>();
        std::shared_ptr<Wezel> w2 = std::make_shared<Wezel>();
        w1->next = w2;
        w2->next = w1;
    }*/

    for(int i = 0; i < 10; i++) {
        std::shared_ptr<Wezel> w1 = std::make_shared<Wezel>();
        std::shared_ptr<Wezel> w2 = std::make_shared<Wezel>();
        std::weak_ptr<Wezel> wp1(w1);
        std::weak_ptr<Wezel> wp2(w2);
        w1->weakNext = wp1;
        w2->weakNext = wp2;
    }




    //std::cout << "Koniec" << std::endl;
    return 0;
}

/*
4.  Od razu po utworzeniu wskaźnika unikalnego obiekt jest usuwany. Dzieje się tak, poniewać wskaźnik nie jest przypisany do rzadnej zmiennej.
6.  Tak. Teraz obiekt jest usuwany dopiero pod koniec iteracji.
9.  W tym przypadku w ogóle nie jest uruchamiany destruktor. 
*/