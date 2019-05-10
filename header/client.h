#indef CLIENT_H
#define CLIENT_H

#include <string>

using namespace std;

class Client {
protected:
  Base *root;
  string command;

public:
  Client() {
    root = 0;
  };

  Client(string& commandInput) {
    command = commandInput;
  };

  void init();
};


#endif
