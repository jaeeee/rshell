#include "../header/base.h"
#include "../header/client.h"
#include "../header/command.h"
#include "../header/connector.h"
#include "../header/and.h"
#include "../header/semi.h"
#include "../header/pipe.h"
#include "../header/input.h"
#include "../header/iopipe.h"
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class Base;

void Client::parse() {
  string c1str;
  string c2str;
  stack<Base*> tree;
  queue<string> parentheses;
  if (command.find('#') != -1) { //found #
    int indexOfPound = command.find('#');
    string substringedCommand = command.substr(0, indexOfPound);
    Base* cmdPound = new Command(substringedCommand);
    tree.push(cmdPound);
  }
  if (command.at(0) == '[' || command.substr(0,4) == "test") {
    root = new TestCommand(command);
  }
  else {
    if ((command.find('(') != -1) && (command.find(')') != -1)) { // if there are parentheses
      while ((command.find('(') != -1) && (command.find(')') != -1)) {
        int a = command.find('(') + 1;
        int b = command.find(')') - 1;
        string insideP = command.substr(a, b - a + 1);
        parentheses.push(insideP);
        command = command.substr(0,command.find('(')) + command.substr(command.find(')'), command.size() - command.find(')') - 1);
      }
      while (!parentheses.empty()) {
        Client * temp = new Client(parentheses.front());
        temp->parse();
        parentheses.pop();
      }
      if (command == "") {
        return;
      }
    }
    if (command.size() > 2) {
      if (command.at(0) == ')') { // if there is a prantheses
        cout <<"as;dflkj" << endl;
      //if (command.find('(') && command.find(')')) {
        if (command.at(1) == '&' || command.at(1) == '|') {
          command = command.substr(4);
        }
        else if(command.at(1) == ';') {
          command = command.substr(2);
        }
      }
    if (command.at(command.size() - 2) == ';' ) {
      command = command.substr(0, command.size() - 2);
    }
    else if (command.at(command.size() - 3) == '|' || command.at(command.size() - 3) == '&' ) {
      command = command.substr(0, command.size() - 4);
    }
  }
    if (command.find(' ') == -1) { //no spaces found
      Base* cmd0 = new Command(command);
      // root = cmd0;
      tree.push(cmd0);
      // cout << "no spaces, therefore command is: " << command << endl;
    }
    else if (command.find(' ') != -1){
      // cout << "o fuhk spaces found, here we go boys" << endl;
      bool whileCond = true;
      bool first = true;
      while (whileCond == true) { //while there are spaces...
        int indexOfSpace = command.find(' ');
        int numSpacesXD = 0;
        for (int i = 0; i < command.size(); i++) {
          if (command.at(i) == ' ') {
            numSpacesXD++;
          }
        }
        if (first == false) {
          if (numSpacesXD == 0) {
            tree.push(new Command(command));
            whileCond = false;
            break;
          }
          string commandCopy = command.substr(command.find(' '), command.size() - 1);
          indexOfSpace = commandCopy.find(' ');
        }
        if (command.at(indexOfSpace + 1) != '&' &&
        command.at(indexOfSpace + 1) != '|' &&
        command.at(indexOfSpace + 1) != ';') {
          if (command.find('&') != -1) {
          int indxOfAnd = command.find('&');
          Base* c1 = new Command(command.substr(0, indxOfAnd - 1));
          Base* c2 = new Command(command.substr(indxOfAnd + 3, command.size() - 1));
          Base* addCon = new And_Connector(c1, c2);
          tree.push(addCon);
          command = c2->getCommand();
          first = false;
          }
          if (command.find('|') != -1) {
          int indxOfPipe = command.find('|');
          Base* c1 = new Command(command.substr(0, indxOfPipe -1));
          Base* c2 = new Command(command.substr(indxOfPipe +3, command.size() - 1));
          Base* pipeCon = new Pipe_Connector(c1, c2);
          tree.push(pipeCon);
          command = c2->getCommand();
          first = false;
          }
          if (command.find(';') != -1 ) {
          int indxOfSemi = command.find(';');
          Base* c1 = new Command(command.substr(0, indxOfSemi));
          Base* c2 = new Command(command.substr(indxOfSemi + 2, command.size() - 1));
          Base* semiCon = new Semi_Connector(c1, c2);
          tree.push(semiCon);
          command = c2->getCommand();
          first = false;
        }
        /**
        BEGIN PROCESSING OPERATIONS
        **/
        /**
        IO REDIRECTION
        **/
        if (command.find('<') != -1) {
          // cout << "input redirection detected" << endl;
          int indxOfOpen = command.find('<');
          Command* c1 = new Command(command.substr(0, indxOfOpen - 1));
          // cout << "[" << c1->getCommand() << "]" << endl;
          Command* c2 = new Command(command.substr(indxOfOpen + 2, command.size() - 1));
          // cout << "[" << c2->getCommand() << "]" << endl;
          // string dude = c2->getCommand();
          // cout << dude << endl;
          Input* inputCon = new Input(c1, c2);
          /**
          INDEPENDENT PROCESSING
          **/
          tree.push(inputCon);
          root = tree.top();
          tree.pop();
          root->execute();
          // cout << "done" << endl;
          return;
          // command = c2->getCommand();
          first = false;
        }
        else {
        //if none of the connectors are found, truncate the string should be saved, removing the last space
        // Base* commandNoConnectorYet = new Command(command);
        // //cout << command << endl;
        // //parent = new Client(command);
        Base* elseC = new Command(command);
        tree.push(elseC);
        whileCond = false;
      }
    }
  }
}
}
    while (!tree.empty()) {
      root = tree.top();
      tree.pop();
    }
    root->execute();
}
