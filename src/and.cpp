#include "../header/and.h"
#include <iostream>
#include "../header/base.h"
#include "../header/connector.h"

using namespace std;

class Base;
class Connector;

bool And_Connector::execute() {
  return (left->execute()) && (right->execute());
}

string And_Connector::getCommand() {
  //impliment
return "";
}
