#include "../header/command.h"

#include <iostream>
#include <sstream>
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
  vector<char *> extractedWords;
  char *truncated_string = strtok((char * ) this->cmd.c_str(), " ");
  while (truncated_string != NULL) {
    extractedWords.push_back(truncated_string);
    truncated_string = strtok(NULL, " "); //find next token
  }
  char **args = new char *[extractedWords.size() + 1]; //instantiate the args array
  for (int i = 0; i < extractedWords.size(); i++) {
    args[i] = extractedWords[i];
  }
  args[extractedWords.size()] = NULL;
//   int count = 0;
//
//   for (int i = 0; i < cmd.size(); i++) {
//     if (cmd.at(i) == ' ') {
//       count++;
//     }
//   }
//
// char* args[2 + count];
//
// args[0] = (char*)cmd.c_str();
// cout << args[0] << endl;
// args[1 + count] = NULL;
// cout << "found " << count << "spaces" << endl;
// while (count > 0) {
//   args[count] = (char*)cmd.substr(0, cmd.find(' ')).c_str();
//     cmd = cmd.substr(cmd.find(' ') + 1, cmd.size());
// }
// for (int i = 0; i < count; i++) {
//   cout << "arg[" << i << "]: " << args[i] << endl;
// }
// cout << "REEEEEE" << endl;
  // char* args[2 + count];

  // args[0] = (char*)cmd.c_str();
  // for (int j = 1; j < count + 1; j++) {
  //   args[j] = (char*)cmd.substr(0, cmd.find(' ')).c_str();
  //   cmd = cmd.substr(cmd.find(' ') + 1, cmd.size());
  // }
  // args[1 + count] = NULL;

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
