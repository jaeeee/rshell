#include "../header/pipe.h"
#include <iostream>
#include "../header/base.h"
#include "../header/connector.h"

using namespace std;

class Base;
class Connector;

bool Pipe_Connector::execute() {
  if(left->execute()) { //if left executed without errors
    return true;
  }
  if (right->execute()) { // if left executed with an error execute right
    return true;
  }
  return false;
}

string Pipe_Connector::getCommand() {
  return left->getCommand() + " || " + right->getCommand();
}
