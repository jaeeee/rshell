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


bool TestCommand::execute() {
  // struct stat
  // cout << "EXECUTING [" << cmd << "]" << endl;
  string c2, tempString;
  size_t index_e = cmd.find("-e");
  size_t index_f = cmd.find("-f");
  size_t index_d = cmd.find("-d");
  size_t index_test_str = cmd.find("test");
  size_t index_dash = cmd.find("-");
  struct stat stat_f_comparator;

  if (index_dash != -1) {
    if (index_e == -1 && index_f == -1 && index_d == -1) {
      cout << "(False)" << endl;
      // cout << "invalid input! no parameter specified" << endl;
      return false;
    }
    // if (command.at(index_dash ))
  }

  if (index_e == -1 && index_f == -1 && index_d == -1) { //none found
    //so use the "-e" by default
    if (cmd.at(0) == '[' && cmd.at(cmd.size() - 1) == ']') { //check bounds
    c2 = cmd.substr(1, cmd.size() - 2);
    stringstream ss(c2);
    ss >> tempString;
    c2 = tempString;
    cout << "IF: (" << c2 << ")" << endl;
  } else {
    c2 = cmd.substr(5);
    cout << c2 << endl;
  }
    if (stat(c2.c_str(), &stat_f_comparator) == 0) {
      cout << "(True)" << endl;
      return true;
    } else {
      cout << "(False)" << endl;
      return false;
    }
  }

  /**
  HANDLE -e HERE
  **/
  if (index_e != -1) {
    if (cmd.at(0) == '[' && cmd.at(cmd.size() -1 == ']')) {
      // [tester]
      c2 = cmd.substr(index_e + 3, cmd.size() - 2);
      stringstream ss(c2);
      ss >> tempString;
      c2 = tempString;
      // cout << "FOUND BRACKETS AND -E NOW: (" <<  c2 << ")" << endl;
    } else {
    //assuming there's no brackets
    c2 = cmd.substr(index_e + 3);
  }
    if (stat(c2.c_str(), &stat_f_comparator) == 0) {
      cout << "(True)" << endl;
      return true;
    } else {
      cout << "(False)" << endl;
      return false;
    }
  }

  /**
  HANDLE -f HERE
  **/
  if (index_f != -1) {
    if (cmd.at(0) == '[' && cmd.at(cmd.size() -1 == ']')) {
      // [tester]
      c2 = cmd.substr(index_f + 3, cmd.size() - 2);
      stringstream ss(c2);
      ss >> tempString;
      c2 = tempString;
      // cout << "FOUND BRACKETS AND -f NOW: (" <<  c2 << ")" << endl;
    } else {
    //assuming there's no brackets
    c2 = cmd.substr(index_f + 3);
  }
    if (stat(c2.c_str(), &stat_f_comparator) == 0) {
      if (S_ISREG(stat_f_comparator.st_mode)) {
        cout << "(True)" << endl;
        return true;
      } else {
        cout << ("False") << endl;
        return false;
      }
    // }
      // cout << "(True)" << endl;
      // return true;
    } else {
      cout << "(False)" << endl;
      return false;
    }
  }

  /**
  HANDLE -d HERE
  **/
  if (index_d != -1) {
    if (cmd.at(0) == '[' && cmd.at(cmd.size() -1 == ']')) {
      // [tester]
      c2 = cmd.substr(index_d + 3, cmd.size() - 2);
      stringstream ss(c2);
      ss >> tempString;
      c2 = tempString;
      cout << "FOUND BRACKETS AND -d NOW: (" <<  c2 << ")" << endl;
    } else {
    //assuming there's no brackets
    c2 = cmd.substr(index_d + 3);
  }
    if (stat(c2.c_str(), &stat_f_comparator) == 0) {
      if (S_ISDIR(stat_f_comparator.st_mode)) {
        cout << "(True)" << endl;
        return true;
      } else {
        cout << ("False") << endl;
        return false;
      }
    // }
      // cout << "(True)" << endl;
      // return true;
    } else {
      cout << "(False)" << endl;
      return false;
    }
  }
  return false;
}
