// Zhiyu Yin, 12/6/2023
// implementation of Veggie class

#include "Veggie.h"
#include "FieldInhabitant.h"

Veggie::Veggie(const string &Symbol_, const string &Name_, const int Point_)
        : FieldInhabitant(Symbol_), veggieName(Name_), veggiePoint(Point_) {};

void Veggie::setVeggieName(const string &name) { veggieName = name; }

void Veggie::setVeggiePoint(const int Point) { veggiePoint = Point; }

const string &Veggie::getVeggieName() const { return veggieName; }

int Veggie::getVeggiePoint() const { return veggiePoint; }

std::ostream &operator<<(std::ostream &os, const Veggie &thisVeggie) {
    os << thisVeggie.symbol << ": " << thisVeggie.veggieName << " "
       << thisVeggie.veggiePoint << " points\n";
    return os;
}