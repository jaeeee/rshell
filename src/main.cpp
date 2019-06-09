#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "../header/client.h"
#include "../header/connector.h"
#include "../header/and.h"
#include "../header/pipe.h"
#include "../header/semi.h"
#include "../header/iopipe.h"
#include "../header/input.h"

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
  //pid_t pid = fork();
  while (1) {
    initMenu();
    // char bruh;
    // cin >> bruh;
    // cout << bruh << endl;
    // char* args[2];
     string dummy;
     getline(cin, dummy);
    //
    if (dummy == "exit") {
      break;
    }

    // args[0] = (char*)dummy.c_str();
    // args[1] = NULL;
    //
    // if (fork() == 0) { //wait for child
    //   if (execvp (args[0],args) == -1) {
    //     perror("exec");
    //   }
    // }
    // else {
    //   wait(NULL);
    //}
    // Base * temp = new Command(dummy);
    // cout << temp->getCommand() << " is being executed!" << endl;
    // temp->execute();
    Client* user = new Client(dummy);
    user->parse();
    // user->init();

    // Base * parent = new Pipe_Connector(new Command("a"), new Command ("ls"));
    // Base * parent1 = new Pipe_Connector(new Command("echo hi"), parent);
    // Base * parent2 = new And_Connector(new Command("ls"), parent1);
    //
    // cout << parent2->getCommand() << endl;
    // parent2->execute();

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
