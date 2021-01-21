#ifndef FP_H
#define FP_H

#include "Osoba.h"
#include "FabrykaOsob.h"
#include "Pracownik.h"

class FabrykaPracownikow : public FabrykaOsob  {
public:
    Osoba* utworz();
};

#endif /* !FP_H */