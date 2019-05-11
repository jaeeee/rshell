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
  if (command.find(' ') == -1) {
    cout << "THIS COMMAND HAS NO SPACES BRO" << endl;
    /**
    execute command directly
    **/
    return;
  }
  int begIndcommand = 0;
  int firstSpcIndx = command.find(' ');
  string temp = "";
  for (int i = begIndcommand; i <= firstSpcIndx; i++) {
    temp = temp + command.at(i);
  }
//let's try splitting the string
// cout << "bro size: " << command.size() << endl;
string theCommand = command.substr(firstSpcIndx + 1, command.size() - 1);
// cout << "temp: " << temp << endl;
temp = theCommand;
// cout << "substringed: " << temp << endl;
  Base * cmd1 = new Command(theCommand);
// switch(command.at(firstSpcIndx + 1)) {
switch (temp.at(0)) {
case '&':
// cout << "found case &" << endl;
if (temp.at(1) == '&') {
  // cout << "HEHE &&" << endl;
  // cout << "yup that's a &&" << endl;
  string cutTheStringBro = temp.substr(3, command.size());
  temp = cutTheStringBro;
  // cout << temp << endl;
  Base* cmd2 = new Command(temp);
  Base* addC = new And_Connector(cmd1, cmd2);
}
// if ()
break;
case '|':
cout << "found case | lmfao" << endl;
break;
default: //cases for non operators

break;
}
}
/**
TODO PARSE
**/
