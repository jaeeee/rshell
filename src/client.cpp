#include "../header/base.h"
#include "../header/client.h"
#include "../header/command.h"
#include "../header/connector.h"
#include "../header/and.h"
#include "../header/semi.h"
#include "../header/pipe.h"
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

class Base;

// void Client::init() {
//   // cout << "hi" << endl;
//   //cout << "executing: " << root->getCommand() << endl;
//   root->execute();
// }


void Client::parse() {
  // Client * parent;
  string c1str;
  string c2str;
  stack<Base*> tree;
  // ; && ||
  // root = new Command("");
  if (command.at(0) == '[' || command.substr(0,4) == "test") {
    root = new TestCommand(command);
    cout << "bound TestCommand" << endl;
  }
  if (command.find('#') != -1) { //found #
    //ignore everything after #
    int indexOfPound = command.find('#');
    string substringedCommand = command.substr(0, indexOfPound);
    // cout << substringedCommand << endl;
    Base* cmdPound = new Command(substringedCommand);
    tree.push(cmdPound);
  }
  else if (command.find(' ') == -1) { //no spaces found
    Base* cmd0 = new Command(command);
    // root = cmd0;
    tree.push(cmd0);
    // cout << "no spaces, therefore command is: " << command << endl;
  } else {
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
          // cout << "NO MORE SPACES" << endl;
          // root = new Command(command);
          tree.push(new Command(command));
          // this->init();
          whileCond = false;
          break;
        }
        // cout << command << " F U " << numSpacesXD << endl;
        string commandCopy = command.substr(command.find(' '), command.size() - 1);
        // commandCopy = commandCopy.substr(commandCopy.find(' '), commandCopy.size());
        // cout << "CUT IT: " << commandCopy << endl;
        indexOfSpace = commandCopy.find(' ');
        // indexOfSpace = commandCopy.substr(command.find(' '), command.size() - 1);
      }
      if (command.at(indexOfSpace + 1) != '&' &&
      command.at(indexOfSpace + 1) != '|' &&
      command.at(indexOfSpace + 1) != ';') {
        if (command.find('&') != -1) {
        int indxOfAnd = command.find('&');
        // ls -l && ls -a
        // HALP
        Base* c1 = new Command(command.substr(0, indxOfAnd - 1));
        Base* c2 = new Command(command.substr(indxOfAnd + 3, command.size() - 1));
        Base* addCon = new And_Connector(c1, c2);
        // root = addCon;
        tree.push(addCon);
        command = c2->getCommand();
        // ls -l && echo hi && echo bye
        first = false;
        }
        if (command.find('|') != -1) {
        int indxOfPipe = command.find('|');
        Base* c1 = new Command(command.substr(0, indxOfPipe -1));
        Base* c2 = new Command(command.substr(indxOfPipe +3, command.size() - 1));
        Base* pipeCon = new Pipe_Connector(c1, c2);
        // root = pipeCon;
          tree.push(pipeCon);
        command = c2->getCommand();
        first = false;
        }
        if (command.find(';') != -1 ) {
        int indxOfSemi = command.find(';');
        Base* c1 = new Command(command.substr(0, indxOfSemi));
        // cout << (command.substr(0, indxOfSemi)) << endl;
        Base* c2 = new Command(command.substr(indxOfSemi + 2, command.size() - 1));
        Base* semiCon = new Semi_Connector(c1, c2);
        // root = semiCon;
          tree.push(semiCon);
        command = c2->getCommand();
        first = false;
      } else {
      //if none of the connectors are found, truncate the string should be saved, removing the last space
      // Base* commandNoConnectorYet = new Command(command);
      // //cout << command << endl;
      // //parent = new Client(command);
      Base* elseC = new Command(command);
      tree.push(elseC);
      // this->init();
      // cout << "WYD BRO: " << command << endl;
      whileCond = false;
    }
  }
}
}
    while (!tree.empty()) {
      // cout << "THE TREE ISNT EMPTY" << endl;
      cout << "command: [" << tree.top()->getCommand() << "]" << endl;
      root = tree.top();
      tree.pop();
    }
    root->execute();
}

/**
Old conditions
**/
// else if (command.at(indexOfSpace + 1) == '&') {
//   //remove the space, truncate command accordingly
//   if (command.at(indexOfSpace + 2)  == '&') { //confirm it's two
//   //create left side
//       c1str = command.substr(0, indexOfSpace);
//       cout << "left: " << c1str << endl;
//       // command = c1str;
//       c2str = command.substr(indexOfSpace + 4, command.size() - 1);
//       cout << "right: " << c2str << endl;
//       command = c2str;
//       //parent = new Client(command);
//       root = new And_Connector(new Command(c1str), new Command (c2str));
//       //parent = new And_Connector(new Command(c1str), new Command(c2str));
//       //Base* andC = new And_Connector(new Command(c1str), new Command(c2str));
//       first = false;
//     }
// } else if (command.at(indexOfSpace + 1) == '|') {
//   //remove the space, truncate command accordingly
//   if (command.at(indexOfSpace + 2)  == '|') { //confirm it's two
//   //create left side
//     c1str = command.substr(0, indexOfSpace);
//       cout << "left: " << c1str << endl;
//       // command = c1str;
//       c2str = command.substr(indexOfSpace + 4, command.size() - 1);
//       cout << "right: " << c2str << endl;
//       command = c2str;
//       root = new Pipe_Connector(new Command(c1str), new Command (c2str));
//
//       //parent = new Client(command);
//       //parent = new Pipe_Connector(new Command(c1str), new Command(c2str));
//       //Base* pipeC = new Pipe_Connector(new Command(c1str), new Command(c2str));
//     // }
//     first = false;
//   }
//   //remove the space, truncate command accordingly
// } else if (command.at(indexOfSpace + 1) == ';') {
//   // create left side
//     c1str = command.substr(0, indexOfSpace);
//       cout << "left: " << c1str << endl;
//       // command = c1str;
//       c2str = command.substr(indexOfSpace + 3, command.size() - 1);
//       cout << "right: " << c2str << endl;
//       command = c2str;
//       root = new Semi_Connector(new Command(c1str), new Command (c2str));
//       first = false;
//       //parent = new Client(command);
//       //parent = new Semi_Connector(new Command(c1str), new Command(c2str));
//       //Base* semiC = new Semi_Connector(new Command(c1str), new Command(c2str));
//   // remove the space, trucnate command accordingly
// }
// else {
//   root = new Command(command);
// }
// cout << "operatorsCount: "<< operatorsCount << endl;
// if (operatorsCount > 1) {
//   parent->parse();
//   }
// }
// int firstSpcIndx = command.find(' ');
// switch (temp.at(firstSpcIndx + 1)) {
// case '&':
// // cout << "found case &" << endl;
// if (temp.at(1) == '&') {
//   // cout << "HEHE &&" << endl;
//   // cout << "yup that's a &&" << endl;
//   string cutTheStringBro = temp.substr(3, command.size());
//   temp = cutTheStringBro;
//   // cout << temp << endl;
//   Base* cmd2 = new Command(temp);
//   Base* addC = new And_Connector(cmd1, cmd2);
//   // cout << "2 && found" << endl;
// }
// // if ()
// break;
// case '|':
//
//
//
// break;
// default: //cases for non operators
//
// break;
// }

/**
OLD PARSE
**/
// void Client::parse() { //; && ||
//   if (command.find(' ') == -1) {
//     cout << "THIS COMMAND HAS NO SPACES BRO" << endl;
//     /**
//     execute command directly
//     **/
//     return;
//   }
//   int begIndcommand = 0;
//   int firstSpcIndx = command.find(' ');
//   string temp = "";
//   for (int i = begIndcommand; i <= firstSpcIndx; i++) {
//     temp = temp + command.at(i);
//   }
// //let's try splitting the string
// // cout << "bro size: " << command.size() << endl;
// string theCommand = command.substr(firstSpcIndx + 1, command.size() - 1);
// // cout << "temp: " << temp << endl;
// temp = theCommand;
// // cout << "substringed: " << temp << endl;
//   Base * cmd1 = new Command(theCommand);
// // switch(command.at(firstSpcIndx + 1)) {
// switch (temp.at(0)) {
// case '&':
// // cout << "found case &" << endl;
// if (temp.at(1) == '&') {
//   // cout << "HEHE &&" << endl;
//   // cout << "yup that's a &&" << endl;
//   string cutTheStringBro = temp.substr(3, command.size());
//   temp = cutTheStringBro;
//   // cout << temp << endl;
//   Base* cmd2 = new Command(temp);
//   Base* addC = new And_Connector(cmd1, cmd2);
//   cout << "2 && found" << endl;
// }
// // if ()
// break;
// case '|':
//
//
//
// break;
// default: //cases for non operators
//
// break;
// }
// }

/**
TODO PARSE
**/
