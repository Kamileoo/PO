#include <iostream>
#include <string>

int main(){
    std::string fellow = "world";
    std::cout << "Hello " << fellow << std::endl;
    while (fellow != "exit") {
        std::cout << "Introduce yourself: ";
        std::cout.flush();
        std::getline(std::cin, fellow);
        if(fellow == "exit"){break;}
        std::cout << "Hello " << fellow << std::endl;
    }
}


/*
Program na początku definiuje zmienną fellow i wypisuje "Hello world".
Po tym pyta nas o nazwę i ją od razu wypisuje. Kiedy pojawi się zmienna exit program najpierw wypisuje tą zmienną, a dopiero później kończy program.
*/