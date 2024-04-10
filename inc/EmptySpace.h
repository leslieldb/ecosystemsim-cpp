//
// Created by phldb on 2023-12-13.
//

#ifndef EMPTYSPACE_H
#define EMPTYSPACE_H

#include "Organism.h"

class EmptySpace : public Organism
{
    int testValue;

public :
    EmptySpace();
    EmptySpace(City *city, int, int);
    virtual ~EmptySpace();

    void turn() override;
};

#endif //EMPTYSPACE_H
