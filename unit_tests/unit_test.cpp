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
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

TEST(CountVisitorTest, IOPipeTest1) {
	Base* cmd1 = new Command("ls");
	Base* cmd2 = new Command("more");
	Base* pip = new IOPipe(cmd1,cmd2);

	EXPECT_TRUE(pip->execute());
}

TEST(CountVisitorTest, IOPipeTest2) {
	Base* cmd1 = new Command("ls");
	Base* cmd2 = new Command("less");
	Base* pip = new IOPipe(cmd1,cmd2);

	EXPECT_TRUE(pip->execute());
}

TEST(CountVisitorTest, IOPipeTest3) {
	Base* cmd1 = new Command("ls");
	Base* cmd2 = new Command("ls");
	Base* pip = new IOPipe(cmd1,cmd2);

	EXPECT_FALSE(pip->execute());
}

TEST(CountVisitorTest, IOPipeTest4) {
	Base* cmd1 = new Command("ls");
	Base* cmd2 = new Command("");
	Base* pip = new IOPipe(cmd1,cmd2);

	EXPECT_FALSE(pip->execute());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
