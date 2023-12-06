#pragma once

#include <string>

using std::string;

class FieldInhabitant {
protected:
  string symbol;

public:
  FieldInhabitant(const string &);
  virtual ~FieldInhabitant();

  const string &GetSymbol() const;
  void SetSymbol(const string &);
};