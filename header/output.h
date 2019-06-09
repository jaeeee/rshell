#ifndef OUTPUT_H
#define OUTPUT_H

#include "base.h"
#include "connector.h"

using namespace std;

class Base;

class Output : public Connector {
public:
  Output() {};
  Output(Base* a, Base* b) {
    left = a;
    right = b;
  };
  bool execute();
  string getCommand();
};

#endif
