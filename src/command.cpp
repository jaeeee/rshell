#include "../header/command.h"

#include <iostream>
#include <sstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string>
#include <cstring>

#include "../header/base.h"
#include "../header/client.h"

using namespace std;

class Client;
class Command;
class Connector;
class Base;

bool TestCommand::execute() {
  // struct stat
  cout << "WE ARE EXECUTING A TEST COMMAND" << endl;
  string c2, nFile;
  size_t index_e = cmd.find("-e");
  size_t index_f = cmd.find("-f");
  size_t index_d = cmd.find("-d");
  size_t index_test_str = cmd.find("test");
  size_t index_dash = cmd.find("-");
  struct stat stat_f_comparator;

  if (index_dash != -1) {
    if (index_e == -1 && index_f == -1 && index_d == -1) {
      cout << "(False)" << endl;
      cout << "invalid input! no parameter specified" << endl;
      return false;
    }
    // if (command.at(index_dash ))
  }

  if (index_e == -1 && index_f == -1 && index_d == -1) { //none found
    //so use the "-e" by default
    c2 = cmd.substr(0, cmd.size() - 2);
    stringstream ss(c2);
    ss >> nFile;
    c2 = nFile;
    if (stat(c2.c_str(), &stat_f_comparator) == 0) {
      cout << "(True)" << endl;
      return true;
    } else {
      cout << "(False)" << endl;
      return false;
    }
  }
  return true;
}

bool Command::execute() {
  if (cmd == "exit" || cmd == "exit ") {
    exit(2);
    // cout << "yup that's exit " << endl;
    return false;
  }
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
