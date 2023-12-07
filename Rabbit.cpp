// Zhiyu Yin, 12/6/2023
// implementations of Rabbit class

#include "Rabbit.h"
#include "Creature.h"

Rabbit::Rabbit(int x_, int y_) : Creature(x_, y_, "R") {};

std::ostream &operator<<(std::ostream &os, Rabbit &thisRabbit) {
    os << "location: " << thisRabbit.x << "\t" << thisRabbit.y << "\n";
    return os;
}

