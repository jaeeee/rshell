#include "../header/base.h"
#include "../header/connector.h"
#include "../header/output.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>

using namespace std;

class Base;
class Connector;

bool Output::execute() {
  int file_desc, return_val, savedstdout;
  string nFile = right->getCommand();
  file_desc = open(nFile.c_str(), O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
  if (file_desc < 0) {
    perror("open");
    exit(1);
    return false;
  }
  savedstdout = dup(1);
  return_val = dup2(file_desc, 1);

  if (return_val < 0) {
    perror("dup2");
    exit(1);
    return false;
  }
  left->execute();
  dup2(savedstdout, 1);
  // if (close)
  switch(close(savedstdout)) {
    case -1:
    perror("errno");
    exit(1);
    return false;
    case 0:
    close(savedstdout);
    return true;
  }
  return true;
// return true;
}
//
string Output::getCommand() {
  return left->getCommand() + " > " + right->getCommand();
}
