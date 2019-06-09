#ifndef IOPIPE_H
#define IOPIPE_H

#include "base.h"
#include "connector.h"

using namespace std;

class Base;

class IOPipe : public Connector {
public:
  IOPipe() { }
  IOPipe(Base *left, Base *right) : Connector(left, right) {

  }

  bool execute();
  string getCommand();
};

#endif
