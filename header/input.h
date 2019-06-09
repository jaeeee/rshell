#ifndef INPUT_H
#define INPUT_H

#include "base.h"
#include "connector.h"

using namespace std;

class Base;

class Input : public Connector {
public:
  Input() {};
  Input(Base* left, Base* right) {};
  bool execute();
  // bool getCommand();
};

#endif
