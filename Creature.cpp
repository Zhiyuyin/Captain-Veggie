// Zhiyu Yin, 12/6/2023
// implementations of Creature class

#include "Creature.h"
#include "FieldInhabitant.h"

Creature::Creature(int X_, int Y_, const string &Symbol_)
        : FieldInhabitant(Symbol_), x(X_), y(Y_) {};

int Creature::getX() const { return x; }

int Creature::getY() const { return y; }

void Creature::setX(int X_) { x = X_; }

void Creature::setY(int Y_) { y = Y_; }