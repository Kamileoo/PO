#ifndef FS_H
#define FS_H

#include "Osoba.h"
#include "FabrykaOsob.h"
#include "Student.h"

class FabrykaStudentow : public FabrykaOsob  {
public:
    Osoba* utworz();
};

#endif /* !FS_H */