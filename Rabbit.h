// Zhiyu Yin, 12/6/2023
// declarations of Rabbit class

#pragma once

#include "Creature.h"
#include <iostream>

class Rabbit : public Creature {
public:
    Rabbit(int, int);

    // used for testing rabbits' movements by printing their locations
    friend std::ostream &operator<<(std::ostream &, Rabbit &);
};