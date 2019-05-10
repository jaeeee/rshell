#include "../header/base.h"
#include "../header/client.h"
#include "../header/command.h"
#include "../header/connector.h"

#include <iostream>
#include <string>

using namespace std;

class Base;

void Client::init() {
  root->execute();
}

void Client::parse() { //; && ||
  int begIndcommand = 0;
  int firstSpcIndx = command.find(' ');
  string temp = "";
  for (int i = begIndcommand; i <= firstSpcIndx; i++) {
    temp = temp + command.at(i);
  }

  Base * cmd1 = new Command(temp);

switch(command.at(firstSpcIndx + 1)) {
case '&':
cout << "found case &" << endl;
break;
case '|':
break;
default:
break;
}
}
/**
TODO PARSE
**/
