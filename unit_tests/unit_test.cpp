//test
//#include "base.h"

#include "gtest/gtest.h"
#include "../header/client.h"
#include "../header/connector.h"
#include "../header/and.h"
#include "../header/pipe.h"
#include "../header/semi.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

TEST(TestName, EchoTests) {
  string cmd = "a";
  Command *test = new Command(cmd);
  EXPECT_FALSE(test->execute());
  delete test;
}

TEST(TestName, EchoTest1) {
  string cmd = "ls";
  Command *test = new Command(cmd);
  EXPECT_TRUE(test->execute());
  delete test;
}

TEST(TestName, EchoTest2) {
  string cmd = "echo a";
  Command *test = new Command(cmd);
  EXPECT_TRUE(test->execute());
  delete test;
}

TEST(TestName, EchoTest3) {
  string cmd = "ls";
  Command *test = new Command(cmd);
  EXPECT_TRUE(test->execute());
  delete test;
}

TEST(TestName, EchoTest4) {
  string cmd = "ls && ls";
  Command *test = new Command(cmd);
  EXPECT_TRUE(test->execute());
  delete test;
}

TEST(TestName, EchoTest5) {
  string cmd = "ls || ls";
  Command *test = new Command(cmd);
  EXPECT_TRUE(test->execute());
  delete test;
}

TEST(TestName, EchoTest6) {
  string cmd = "ls ; ls";
  Command *test = new Command(cmd);
  EXPECT_TRUE(test->execute());
  delete test;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
