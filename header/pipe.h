#ifndef PIPE_H
#define PIPE_H

#include "base.h"
#include "connector.h"

using namespace std;

class Base;

class Pipe_Connector : public Connector {
public:
  Pipe_Connector() {

  }
  Pipe_Connector(Base *left, Base *right) : Connector(left, right) {

  }

  bool execute();
  // string getCommand() {return "a"; }
};

#endif
