#ifndef AND_H
#define AND_H

#include "base.h"
#include "connector.h"

using namespace std;

class Base;

class And_Connector : public Connector {
public:
  And_Connector() {

  }
  And_Connector(Base *left, Base *right) : Connector(left, right) {

  }

  bool execute() {return false;};
  string getCommand() {return "a"; }
};

#endif
