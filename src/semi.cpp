#include "../header/semi.h"
#include <iostream>
#include "../header/base.h"
#include "../header/connector.h"

using namespace std;

class Base;
class Connector;

bool Semi_Connector::execute() {
  left->execute();
  return right->execute();
}

string Semi_Connector::getCommand() {
  return left->getCommand() + "; " + right->getCommand();
}
