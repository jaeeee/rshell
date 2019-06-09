#include "../header/iopipe.h"
#include <iostream>
#include "../header/base.h"
#include "../header/connector.h"

using namespace std;

class Base;
class Connector;

bool IOPipe::execute() {
//TODO
return false;
}

string IOPipe::getCommand() {
  return left->getCommand() + " | " + right->getCommand();
}
