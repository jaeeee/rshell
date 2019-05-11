#include "../header/pipe.h"
#include <iostream>
#include "../header/base.h"
#include "../header/connector.h"

using namespace std;

class Base;
class Connector;

bool Pipe_Connector::execute() {
  if(left->execute()) {
    return false;
  }
  return right->execute();
}

string Pipe_Connector::getCommand() {
  return left->getCommand() + " || " + right->getCommand();
}
