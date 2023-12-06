// Zhiyu Yin, 12/6/2023
// declarations of Veggie class

#pragma once

#include "FieldInhabitant.h"
#include <iostream>
#include <ostream>
#include <string>

class Veggie : public FieldInhabitant {
private:
    string veggieName;
    int veggiePoint;

public:
    Veggie(const string &, string , int);

    void setVeggieName(const string &);

    void setVeggiePoint(int);

    const string &getVeggieName() const;

    int getVeggiePoint() const;

    // helper function for checking out current vegetables
    friend std::ostream &operator<<(std::ostream &, const Veggie &);
};