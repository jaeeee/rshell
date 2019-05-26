#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main()
{
  char* args[2];
  string ls = "ls";
  args[0] = (char*)ls.c_str();
  args[1] = NULL;

  pid_t pid = fork();

  if (pid == 0) {
    cout << "child: " << pid << endl;
    if (execvp (args[0], args) == -1) {
      perror ("exec");
    }
  }
  if (pid > 0) {
    if (wait(0) == -1) {
      perror("wait");
    }
    cout << "parent: " << pid << endl;
  }
}
