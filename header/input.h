#ifndef INPUT_H
#define INPUT_H

#include "base.h"
#include "connector.h"

using namespace std;

class Base;

class Input : public Connector {
public:
  Input() {};
  Input(Base* a, Base* b) {
    left = a;
    right = b;
  };
  bool execute();
  string getCommand();
};

#endif
