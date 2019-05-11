#include "../header/command.h"

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "../header/base.h"
#include "../header/client.h"

using namespace std;

class Client;
class Command;
class Connector;
class Base;

bool Command::execute() {
  int count = 0;

  for (int i = 0; i < cmd.size(); i++) {
    if (cmd.at(i) == ' ') {
      count++;
    }
  }

  char* args[2 + count];

  args[0] = (char*)cmd.c_str();
  for (int j = 1; j < count + 1; j++) {
    args[j] = (char*)cmd.substr(0, cmd.find(' ')).c_str();
    cmd = cmd.substr(cmd.find(' ') + 1, cmd.size());
  }
  args[1 + count] = NULL;

  if (fork() == 0) { //wait for child
    if (execvp (args[0],args) == -1) {
      perror("exec");
      return false;
    }
  }
  else {
    wait(NULL);
  }
  return true;
}
