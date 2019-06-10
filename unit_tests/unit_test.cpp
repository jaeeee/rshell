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
#include "../header/iopipe.h"
#include "../header/input.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

TEST(CountVisitorTest, IOPipeTest1) {
	Base* cmd1 = new Command("ls");
	Base* cmd2 = new Command("more");
	Base* connector = new IOPipe(cmd1,cmd2);

	EXPECT_TRUE(connector->execute());
}

TEST(CountVisitorTest, IOPipeTest2) {
	Base* cmd1 = new Command("ls");
	Base* cmd2 = new Command("less");
	Base* connector = new IOPipe(cmd1,cmd2);

	EXPECT_TRUE(connector->execute());
}

TEST(CountVisitorTest, IOPipeTest3) {
	Base* cmd1 = new Command("ls");
	Base* cmd2 = new Command("ls");
	Base* connector = new IOPipe(cmd1,cmd2);

	EXPECT_FALSE(connector->execute());
}

TEST(CountVisitorTest, IOPipeTest4) {
	Base* cmd1 = new Command("ls");
	Base* cmd2 = new Command("");
	Base* connector = new IOPipe(cmd1,cmd2);

	EXPECT_FALSE(connector->execute());
}

TEST(CountVisitorTest, ABracketTest1) {
	Base* cmd1 = new Command("wc");
	Base* cmd2 = new Command("names.txt");
	Base* connector = new Input(cmd1,cmd2);

	EXPECT_TRUE(connector->execute());
}

TEST(CountVisitorTest, ABracketTest2) {
	Base* cmd1 = new Command("wc");
	Base* cmd2 = new Command("asdftxt");
	Base* connector = new Input(cmd1,cmd2);

	EXPECT_FALSE(connector->execute());
}

TEST(CountVisitorTest, ABracketTest3) {
	Base* cmd1 = new Command("cat names.txt");
	Base* cmd2 = new Command("names2.txt");
	Base* connector = new Input(cmd1,cmd2);

	EXPECT_FALSE(connector->execute());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
