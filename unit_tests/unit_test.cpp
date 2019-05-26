//test
//#include "base.h"

#include "gtest/gtest.h"
#include "../header/client.h"
#include "../header/connector.h"
#include "../header/and.h"
#include "../header/pipe.h"
#include "../header/semi.h"
#include "../header/base.h"
#include "../header/command.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

TEST(TestName, EchoTests) {
  string cmd = "a";
  Command *test = new Command(cmd);
  EXPECT_TRUE(test->execute());
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

TEST(TestName, getCommandTest) {
  string cmd = "a || ls";
  Command *test = new Command(cmd);
  EXPECT_TRUE(test->execute());
  delete test;
}
TEST(TestName, getCommandTest2) {
  string cmd = "ls && ls";
  Command *test = new Command(cmd);
  EXPECT_TRUE(test->execute());
  delete test;
}

TEST(TestName, getCommandTest3) {
  string cmd = "ls ; a";
  Command *test = new Command(cmd);
  EXPECT_TRUE(test->execute());
  delete test;
}

TEST(TestName, CombinationTest1) {
  string cmd1 = "ls #ls";
  string cmd2 = "ls -a";
  string cmd3 = "ls -l";

  Base *test = new Command(cmd1);
  Base *temp = new Command(cmd2);
  Base *test2 = new And_Connector(test, temp);
  EXPECT_TRUE(test2->execute());
  //delete test;
  //delete test2;
}

TEST(TestName, CombinationTest2) {
  string cmd1 = "ls";
  string cmd2 = "ls -a";
  string cmd3 = "ls -l";
  string cmd4 = "echo hello";
  string cmd5 = "echo goodbye";

  Base *test = new Command(cmd1);
  Base *test0 = new Command(cmd2);
  Base *test1 = new And_Connector(test, test0);
  Base *test2 = new Command(cmd3);
  Base *test3 = new And_Connector(test2, test1);

  EXPECT_EQ(test3->getCommand(), "ls -l && ls && ls -a");
}

TEST(TestCommand, EXIST) {
  string cmd1 = "touch wat";
  string cmd2 = "test -e wat";
  Base *test1 = new Command(cmd1);
  Base *test2 = new TestCommand(cmd2);
  test1->execute();
  EXPECT_TRUE(test2->execute());
  Base *test3 = new Command("rm -f wat");
  test3->execute();
}

TEST(TestCommand, EXIST_DIRECTORY) {
  string cmd1 = "touch fileName";
  string cmd2 = "test -d fileName";
  Base *test1 = new Command(cmd1);
  Base *test2 = new TestCommand(cmd2);
  test1->execute();
  EXPECT_FALSE(test2->execute());
  Base *test3 = new Command("rm -f fileName");
  test3->execute();
}

TEST(TestCommand, EXIST_YES) {
  string cmd1 = "touch fileName";
  string cmd2 = "[fileName]";
  Base *test1 = new Command(cmd1);
  Base *test2 = new TestCommand(cmd2);
  test1->execute();
  EXPECT_TRUE(test2->execute());
  Base *test3 = new Command("rm -f fileName");
  test3->execute();
}

TEST(TestCommand, EXIST_E_WITH_BRACKET) {
  string cmd1 = "touch fileName";
  string cmd2 = "[ -e fileName ]";
  Base *test1 = new Command(cmd1);
  Base *test2 = new TestCommand(cmd2);
  test1->execute();
  EXPECT_TRUE(test2->execute());
  Base *test3 = new Command("rm -f fileName");
  test3->execute();
}

TEST(TestCommand, DIRECTORY_TEST) {
  string cmd1 = "mkdir direc";
  string cmd2 = "[ -d direc ]";
  Base *test1 = new Command(cmd1);
  Base *test2 = new Command(cmd2);
  test1->execute();
  EXPECT_TRUE(test2->execute());
  Base *test3 = new Command("rm -r direc");
  test3->execute();
}

TEST(TestCommand, TEST_COMB_TEST) {
  string cmd1 = "mkdir hammer";
  string cmd2 = "[ hammer ]";
  Base *test1 = new Command(cmd1);
  Base *test2 = new TestCommand(cmd2);
  Base *test3 = new Command("touch haha");
  test3->execute();
  Base *test4 = new Command("[ haha ]");
  Base *test5 = new TestCommand("test -e wtf");
  Base *test6 = new TestCommand("[ -f hammer ]");
  Base *test7 = new TestCommand("[ -d haha ]");
  EXPECT_TRUE(test4->execute());
  EXPECT_FALSE(test5->execute());
  EXPECT_FALSE(test6->execute());
  EXPECT_FALSE(test7->execute());
  test1->execute();
  EXPECT_TRUE(test2->execute());
  Base *rm3 = new Command("rm -r hammer");
  Base *rm4 = new Command("rm -f haha");
  rm3->execute();
  rm4->execute();
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
