// Zhiyu Yin, 12/6/2023
// declarations of Creature class

#pragma once

#include "FieldInhabitant.h"

class Creature : public FieldInhabitant {
protected:
    // coordinates
    int x;
    int y;

public:
    Creature(int, int, const string &);

    int getX() const;

    int getY() const;

    void setX(int);

    void setY(int);
};