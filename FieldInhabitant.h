// Zhiyu Yin, 12/6/2023
// declarations of FieldInhabitant class

#pragma once

#include <string>

using std::string;

class FieldInhabitant {
protected:
  string symbol;

public:
  FieldInhabitant(string );
  virtual ~FieldInhabitant();

  const string &GetSymbol() const;
  void SetSymbol(const string &);
};