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
  /**
  Works in some cases, some cases not working fully.
  **/
    int file_desc[2];
    pid_t pid1; // child process 1
    pid_t pid2; // child process 2
    int temp; // status variable
// use pipe function to check initially for any errors
if (pipe(file_desc) < 0) {
  perror("pipe");
  exit(1);
  return false;
} else {
  //create first fork
  pid1 = fork();
  if (pid1 < 0) {
    perror("fork");
    exit(1);
    return false;
  } else {
  if (pid1 == 0) {
    // cout << "good job" << endl;
    //if success, call fork again
    pid2 = fork();
    if (pid2 < 0) {
      perror("fork");
      exit(1);
      return false;
    }
    if (pid2 == 0) {
      //attempt left side piping
      int try_left = dup2(file_desc[1], 1);
      if (try_left < 0 || (close(file_desc[0]) < 0)) {
        // exit(1);
        return false;
      }
      if (left->execute() == false) {
        cout << "left execution failed" << endl;
        // exit(1);
        return false;
      }
      exit(0); //success termination
    } else {
      //attempt right side piping
      int try_right = dup2(file_desc[0], 0);
      if (try_right < 0 || (close(file_desc[1]) < 0)) {
        exit(1);
        return false;
      }
      if (right->execute() == false) {
        cout << "right execution failed" << endl;
        exit(1);
        return false;
      }
      exit(0); //success termination
    }
  }
}
//fixed infinite loop issue
cout << "we made it if we got to here." << endl;
exit(0);
return true;
}
// if (close(file_desc[1]) < 0 || close(file_desc[0] < 0)) {
//   perror("errno");
//   exit(1);
//   return false;
// }
//     waitpid(pid1, &temp, 0);
//     while (!WIFEXITED(temp)) {
//       cout << "changing status here" << endl;
//     }
//     waitpid(pid1, &temp, 0);
//     if (temp > 0 || WEXITSTATUS(temp) == 0) {
//       return false;
//     } else {
//       cout << "everything should be fine here" << endl;
//         return true;
//     }
    return false;
}



string IOPipe::getCommand() {
  return left->getCommand() + " | " + right->getCommand();
}
