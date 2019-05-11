#ifndef Semi_H
#define Semi_H

#include "base.h"
#include "connector.h"

using namespace std;

class Base;

class Semi_Connector : public Connector {
public:
  Semi_Connector() {

  }
  Semi_Connector(Base *left, Base *right) : Connector(left, right) {

  }

  bool execute();
  // string getCommand() {return "a"; }
};

#endif
