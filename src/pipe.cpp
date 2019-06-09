#include "../header/pipe.h"
#include <iostream>
#include "../header/base.h"
#include "../header/connector.h"

using namespace std;

class Base;
class Connector;

bool Pipe_Connector::execute() {
  // cout << "left" << endl;
  // if(left->execute()) { //if left executed without errors
  //   cout << "no error" << endl;
  //   return true;
  // } else {
  //   right->execute();
  // }
  // if (right->execute()) { // if left executed with an error execute right
  //   return true;
  // }
  // return false;
   return (left->execute()) || (right->execute());
}

string Pipe_Connector::getCommand() {
  return left->getCommand() + " || " + right->getCommand();
}
