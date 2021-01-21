#include "FabrykaPracownikow.h"

Osoba* FabrykaPracownikow::utworz() {
    return new Pracownik();
}