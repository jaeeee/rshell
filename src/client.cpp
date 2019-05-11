#include "../header/base.h"
#include "../header/client.h"
#include "../header/command.h"
#include "../header/connector.h"
#include "../header/and.h"

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Base;

void Client::init() {
  root->execute();
}


void Client::parse() {
  int ignoreSpaceIndx;
  // ; && ||
  if (command.find('#') != -1) { //found #
    //ignore everything after #
    int indexOfPound = command.find('#');
    string substringedCommand = command.substr(0, indexOfPound);
    cout << substringedCommand << endl;
    Base* cmdPound = new Command(substringedCommand);
  }
  else if (command.find(' ') == -1) { //no spaces found
    Base* cmd0 = new Command(command);
    cout << "no spaces, therefore command is: " << command << endl;
  } else {
    cout << "o fuhk spaces found, here we go boys" << endl;
    bool whileCond = true;
    while (whileCond == true) { //while there are spaces...
      int indexOfSpace = command.find(' ');
      if (command.at(indexOfSpace + 1) != '&' &&
      command.at(indexOfSpace + 1) != '|' &&
      command.at(indexOfSpace + 1) != ';') {
      //if none of the connectors are found, truncate the string should be saved, removing the last space
      Base* commandNoConnectorYet = new Command(command);
      cout << command << endl;
      whileCond = false;
    } else if (command.at(indexOfSpace + 1) == '&') {
      //remove the space, truncate command accordingly
      if (command.at(indexOfSpace + 2)  == '&') { //confirm it's two
      //create left side
        string c1str = command.substr(0, indexOfSpace);
          cout << "left: " << c1str << endl;
          // command = c1str;
          string c2str = command.substr(indexOfSpace + 4, command.size() - 1);
          cout << "right: " << c2str << endl;
          command = c2str;
          Base* andC = new And_Connector(new Command(c1str), new Command(c2str));
        }
    } else if (command.at(indexOfSpace + 1) == '|') {
      //remove the space, truncate command accordingly
    } else if (command.at(indexOfSpace + 1) == ';') {
      //remove the space, trucnate command accordingly
    }

    }
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
  }

}

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
