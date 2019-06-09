#include "../header/base.h"
#include "../header/connector.h"
#include "../header/input.h"

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

bool Input::execute() {
string nFile = this->right->getCommand();
cout << "nFile: " << nFile << endl;
int file_desc = open(nFile.c_str(), O_RDONLY);
int savestdin, restore;
if (file_desc < 0) {
  perror("open");
  exit(1);
  return false;
}
savestdin = dup(0); //stdin from terminal duplicate from fd slot (0) into next slot
restore = dup2(file_desc, 0); //restore dup(0)
if (restore < 0) {
  perror("dup2");
  exit(1);
  return false;
}
left->execute();
dup2(savestdin, 0);
switch(close(savestdin)) { //converted to switch statement just in case there are any other cases we need
  //take into account
  case -1:
  perror("errno");
  exit(1);
  return false;
  break;
  case 0:
  close(savestdin);
  return true;
  break;
}
// if (close(savestdin) == -1) {
//   perror("errno");
//   exit(1);
//   return false;
// } else if (close(savestdin) == 0) {
//     close(savestdin);
//     return true;
// }
return true;
}
//
string Input::getCommand() {
  return left->getCommand() + " < " + right->getCommand();
}
