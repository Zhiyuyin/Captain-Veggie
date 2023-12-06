// Zhiyu Yin, 12/6/2023
// implementations of FieldInhabitant member functions

#include "FieldInhabitant.h"

FieldInhabitant::FieldInhabitant(const string &Symbol) : symbol(Symbol){};

FieldInhabitant::~FieldInhabitant(){};

const string &FieldInhabitant::GetSymbol() const { return symbol; }

void FieldInhabitant::SetSymbol(const string &Symbol_) {
    symbol = Symbol_;
}