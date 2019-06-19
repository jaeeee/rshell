/**
I am rewriting this function so I can demonstrate that I know what piping does.
Updated so that it checks command execution because it would be
redunant to check everything if the command doesn't even run.
Removed status variable because we can just return the the result (bool)
by error checking each phase.
We will continue using exit calls alongside returns because we would still
like to know the current status of the program. Unless I find another way for
the function to give the user a boolean result without influencing the actual
logic.
I have learned that exit(1) is for exiting due to a failure
On the contrary, exit(0) would be formally defined as an EXIT_SUCCESS
Below are the notes that I took from reading and watching online videos on how to do pipe.
If fork is called and it returns a negative value, that means the creation of the child process has failed.
Returns 0 to newly created child process
Make a file descriptor array of size 2 (fd[2])
Notes are continued in the PSUEDOCODE comments block starting 4 lines below.
**/

#include "../header/iopipe.h"
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

/**
Forward declaration of classes neccessary for the class to compile without errors or VTable error at runtime.
**/
class Base;
class Connector;

bool IOPipe::execute() {
  /**
  ORIGINAL PSEUDO CODE (INITIAL IDEA GOING INTO THE ASSIGNMENT)
  We are going to be utilizing the pipe function (inherent sys call) so that we can double check if anything goes wrong before even doing the piping process.
  check if the initial pipe has an error (< 0), before doing anything, waste of space
  pipe1 gets the initial pipe (we use this to see if there is any errors initially)
  If pipe1 passes, fork pid1
  Check for errors
  if == 0
  Basically means a success, so now we have to create another child process
  If < 0
  Error in fork
  after creating another fork while inside the pid1 we also need to error check
  If < 0 there’s an error in creating the child process
  But if successful, we need to copy the desc using the dup2 function, then check if it’s < 0 because then that would mean there are errors
  If left doesn’t work obviously return false (then check if right execution returns false)
  execute left and right accordingly after copying the file_desc into the array
  Check if they fail when they close
  While loop for WIFEXITED (to set the status values)
  waitpid (wait for process to end), pass through the pointer to the status int
  If status is 0 return true but if anything else return false because that would mean that it has failed (the piping command)
  necessary variables - file descriptor integer array
  initial pipe of file_desc (error checking only)
  Pid1 and pid2 (two children processes)
  singular integer for status (temp)
  **/

/**
Variable declarations here
**/
int file_desc[2];
pid_t pid1, pid2;

if (pipe(file_desc) < 0) {
  perror("pipe");
  exit(1);
  return false;
  /**
  NOTE: I read online that you should be checking the statuses of each of the child processes,
  but I feel like it is not complettely
  necessary if you are solely asked to implement a check whether or not the commands ran properly or not.
  **/
} else {
  //create first fork (child process), and again, check for errors
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
      dup2(file_desc[1], 1);
      close(file_desc[0]);
      if (left->execute() == false) {
        cout << "left execution failed" << endl;
        exit(1);
        return false;
      }
      exit(0); //success termination
    } else {
      //attempt right side piping
      dup2(file_desc[0], 0);
      close(file_desc[1]);
      if (right->execute() == false) {
        cout << "right execution failed" << endl;
        exit(1);
        return false;
      }
      exit(0); //success termination
    }
  }
}
//fixed infinite loop issue by ending the process here.
// cout << "we made it if we got to here." << endl;
/**
If we have reached this point, that MUST mean that the piping execution has been complete and ran without errors.
**/
exit(0);
return true;
}
    return false;
}

string IOPipe::getCommand() {
  return left->getCommand() + " | " + right->getCommand();
}
