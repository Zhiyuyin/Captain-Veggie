// Zhiyu Yin, 12/6/2023
// declarations of Captain class

#pragma once

#include "Creature.h"
#include "Veggie.h"
#include <memory>
#include <vector>

using std::vector;

class Captain : public Creature {
private:
    vector<Veggie *> veggiesVec;

public:
    Captain(int, int);

    void addVeggies(Veggie *);

    vector<Veggie *> getVeggies();
};