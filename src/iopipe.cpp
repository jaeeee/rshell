#include "../header/iopipe.h"
// #include <iostream>
#include "../header/base.h"
#include "../header/connector.h"


#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
// #include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>

// #include <stat/stat.h>

using namespace std;

class Base;
class Connector;

bool IOPipe::execute() {
//TODO
// fds 0 stdin
// fds 1 stdout
// fds 2 stderr

int file_desc[2]; //two ends of pipes (WR and RD)
//file_desc[0] RD
//file_desc[1] WR
int status;
pid_t pid, pid_2;

int return_val = pipe(file_desc);
if (return_val < 0) {
  perror("pipe");
  exit(1);
  return false;
}
pid = fork();
if (pid < 0) {
  perror("fork");
  exit(1);
  return false;
}
if (pid == 0) {
  pid_2 = fork();
  if (pid_2 < 0) {
    perror("fork");
    exit(1);
    return false;
  } else if (pid_2 == 0) {
    if (dup2(file_desc[1], 1) < 0) {
      perror("dup2");
      exit(1);
      return false;
    }
    if (close(file_desc[0]) < 0) {
      perror("errno");
      exit(1);
      return false;
    }
    if (left->execute() == false) {
      exit(1);
      return false;
    }
    exit(0);
  } else {
    if (dup2(file_desc[0], 0) < 0) {
      perror("dup2");
      exit(1);
      return false;
    }
    if (close(file_desc[1]) < 0) {
      perror("errno");
      exit(1);
      return false;
    }
    if (left->execute() == false) {
      exit(1);
      return false;
    }
    exit(0);
  }
}
if (close(file_desc[0]) < 0) {
  perror("errno");
  exit(1);
  return false;
}
if (close(file_desc[1]) < 0) {
  perror("errno");
  exit(1);
  return false;
}
waitpid(pid, &status, 0);

while(!WIFEXITED(status)) {
  if (status > 0) {
    return false;
  } else if (WEXITSTATUS(status) == 0) {
    return true;
  } else if (WEXITSTATUS(status) == 0) {
    return false;
  }
}
return false;
// return false;
}

string IOPipe::getCommand() {
  return left->getCommand() + " | " + right->getCommand();
}
