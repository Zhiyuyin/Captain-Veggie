// Zhiyu Yin, 12/6/2023
// implementations of FieldInhabitant member functions

#include "FieldInhabitant.h"

#include <utility>

FieldInhabitant::FieldInhabitant(string Symbol) : symbol(std::move(Symbol)){};

FieldInhabitant::~FieldInhabitant()= default;

const string &FieldInhabitant::GetSymbol() const { return symbol; }

void FieldInhabitant::SetSymbol(const string &Symbol_) {
    symbol = Symbol_;
}