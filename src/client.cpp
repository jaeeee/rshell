#include "../header/base.h"
#include "../header/client.h"
#include "../header/command.h"
#include "../header/connector.h"

#include <iostream>
#include <string>

using namespace std;

class Base;

void Client::init() {
  root->execute();
}

/**
TODO PARSE
**/
