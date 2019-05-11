#include "../header/pipe.h"
#include <iostream>
#include "../header/base.h"
#include "../header/connector.h"

using namespace std;

class Base;
class Connector;

bool Pipe_Connector::execute() {
  left->execute();
  return right->execute();
}
