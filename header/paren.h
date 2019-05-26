#include "base.h"
#include <iostream>
using namespace std;

class Paren : public Base {
private:
  Base * temp;

public:
  Paren(Base * a);
  bool execute();
  string getCommand();
};
