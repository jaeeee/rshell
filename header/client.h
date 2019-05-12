#ifndef CLIENT_H
#define CLIENT_H
#include "../header/command.h"
#include "../header/base.h"
#include "../header/client.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Base;
class Command;
class Client {
protected:
  Base *root;
  string command;
  vector <string> argV;

public:
  Client() {
    root = 0;
  }

  Client(Base * root) {
    this->root = root;
  }

  Client(string& commandInput) {
    command = commandInput;
  }

  // void init();

  void parse();
  //   if (command.at(firstSpcIndx + 1) == ' ')
  //
  // }
};


#endif
