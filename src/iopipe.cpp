#include "../header/iopipe.h"
// #include <iostream>
#include "../header/base.h"
#include "../header/connector.h"


#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>

using namespace std;

class Base;
class Connector;

bool IOPipe::execute() {
    int file_desc[2];
    pid_t pid1;
    pid_t pid2;
    int temp;

   if (pipe(file_desc) < 0) {
     return false;
   }
    pid1 = fork();
    if (pid1 < 0) {
      return false;
    } else if (pid1 == 0) {
      pid2 = fork();
      switch(true) {
        case (pid2 == 0):
        if (dup2(file_desc[1], 1) < 0 || close(file_desc[0]) < 0 || left->execute() == false) {
          return false;
        }
                exit(0);
        break;
        case (pid2 < 0):
        cout << "error in forking" << endl;
        return false;
        break;
        default:
        if (dup2(file_desc[0], 0) < 0 || close(file_desc[1]) < 0 || right->execute() == false) {
          return false;
        }
          exit(0);
          break;
      }
    }
    if (close(file_desc[0]) < 0 || close(file_desc[1]) < 0) {
      perror("errno");
      exit(1);
      return false;
    }
    waitpid(pid1, &temp, 0);
    while (!WIFEXITED(temp)) {
    }
    waitpid(pid1, &temp, 0);
    if (temp > 0) {
      return false;
    }
    switch(WEXITSTATUS(temp)) {
      case 0:
      return true;
      break;
      case 1:
      return false;
      break;
    }
    return false;
}

string IOPipe::getCommand() {
  return left->getCommand() + " | " + right->getCommand();
}
