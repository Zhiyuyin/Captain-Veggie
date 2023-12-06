#include "FieldInhabitant.h"
#include <string>

FieldInhabitant::FieldInhabitant(const string &Symbol) : symbol(Symbol){};

FieldInhabitant::~FieldInhabitant(){};

const string &FieldInhabitant::GetSymbol() const { return symbol; }

void FieldInhabitant::SetSymbol(const string &Symbol_) {
    symbol = Symbol_;
}