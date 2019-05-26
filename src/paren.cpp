#include "../header/paren.h"
#include <iostream>

using namespace std;

Paren::Paren(Base * a) {
  temp = a;
}
bool Paren::execute() {
  return temp->execute();
}
string Paren::getCommand() {
  return "(" + temp->getCommand() +")";
}
