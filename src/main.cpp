#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

void initMenu() {
  static int initilization = 1;
  if (initilization) {
    write(STDOUT_FILENO, " \e[1;1H\e[2J",12);
    initilization = 0;
    // system("clear")
  }
  printf("root@rshell: ~$ "); //prompt
}

void processCommand(char cmd[], char *par[]) {
}

int main()
{
  // char *envp[] = { (char*) "PATH=/bin", 0 };
  while (1) {
    initMenu();
    // char bruh;
    // cin >> bruh;
    // cout << bruh << endl;
    char* args[2];
    string dummy;
    cin >> dummy;
    args[0] = (char*)dummy.c_str();
    args[1] = NULL;
    if (execvp (args[0],args) == -1) {
      perror("exec");
    }
    // break;
  }
// }
  /**
  FORK AND WAIT TESTING COMMANDS
  **/
// pid_t pid = fork();
// if (pid == -1) {
//   perror("fork");
// }
// if (pid == 0) {
//   //child
//   cout << "child: " << pid << endl;
// }
// if (pid > 0 ) {
//   //parent
//   if (wait(0) == -1) {
//     perror("wait");
//   }
//   cout << "parent: " << pid << endl;
//   // while(1);
// }

/**
"LS" CODE
**/
// char* args[2];
// string ls = "ls";
//
// args[0] = (char*)ls.c_str();
// args[1] = NULL;
// if (execvp (args[0],args) == -1) {
//   perror("exec");
// }


return 0;
}