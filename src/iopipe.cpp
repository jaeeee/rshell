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
return false;
}

string IOPipe::getCommand() {
  return left->getCommand() + " | " + right->getCommand();
}
