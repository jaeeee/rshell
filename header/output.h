#ifndef OUTPUT_H
#define OUTPUT_H

#include "base.h"
#include "connector.h"

using namespace std;

class Base;

class Output : public Connector {
public:
  bool flag = false;
  Output() {};
  Output(Base* a, Base* b, bool c) {
    left = a;
    right = b;
    flag = c;
  };
  bool execute();
  string getCommand();
};

#endif
