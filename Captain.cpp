// Zhiyu Yin, 12/6/2023
// implementations of Captain class

#include "Captain.h"
#include "Creature.h"
#include "Veggie.h"

Captain::Captain(int x_, int y_) : Creature(x_, y_, "V") {};

void Captain::addVeggies(Veggie *thisVeggie) {
    veggiesVec.push_back(thisVeggie);
}

vector<Veggie *> Captain::getVeggies() {
    return veggiesVec;
}