#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <string>
#include "base.h"
using namespace std;

class Base;

class Command : public Base {
protected:
  string cmd;
public:
  Command() { }
  Command(string input) {
    cmd = input;
  }
  virtual bool execute();
  string getCommand() {
    return cmd;
  }
};

class TestCommand : public Command {
// protected:
  // string cmd;
public:
  TestCommand() { }
  TestCommand(string input) {
    cmd = input;
  }
  virtual bool execute();
  // string getCommand() {
    // return cmd;
  // }
};


#endif
