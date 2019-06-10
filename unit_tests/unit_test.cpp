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
#include "../header/output.h"
#include "../header/input.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

TEST(CountVisitorTest, InputTest1) {
	Base* cmd1 = new Command("wc");
	Base* cmd2 = new Command("names.txt");
	Input* connector = new Input(cmd1,cmd2);

	EXPECT_TRUE(connector->execute());

	delete connector;
}

TEST(CountVisitorTest, InputTest2) {
	Base* cmd1 = new Command("wc");
	Base* cmd2 = new Command("asdftxt");
	Input* connector = new Input(cmd1,cmd2);

	EXPECT_FALSE(connector->execute());
	delete connector;
}

TEST(CountVisitorTest, InputTest3) {
	Base* cmd1 = new Command("wc");
	Base* cmd2 = new Command("asdftxt");
	Output* connector = new Output(cmd1,cmd2, true);

	EXPECT_FALSE(connector->execute());
	delete connector;
}

TEST(CountVisitorTest, OutputTest3) {
	Base* cmd1 = new Command("cat names.txt");
	Base* cmd2 = new Command("names2.txt");
	Output* connector = new Output(cmd1,cmd2, true);

	EXPECT_TRUE(connector->execute());
	delete connector;
}

TEST(CountVisitorTest, IOPipeTest1) {
	Base* cmd1 = new Command("ls");
	Base* cmd2 = new Command("more");
	IOPipe* connector = new IOPipe(cmd1,cmd2);

	EXPECT_TRUE(connector->execute());
	delete connector;
}

TEST(CountVisitorTest, IOPipeTest2) {
	Base* cmd1 = new Command("ls");
	Base* cmd2 = new Command("less");
	IOPipe* connector = new IOPipe(cmd1,cmd2);

	EXPECT_TRUE(connector->execute());
	delete connector;
}

TEST(CountVisitorTest, IOPipeTest3) {
	Base* cmd1 = new Command("ls");
	Base* cmd2 = new Command("ls");
	IOPipe* connector = new IOPipe(cmd1,cmd2);

	EXPECT_FALSE(connector->execute());
	delete connector;
}

TEST(CountVisitorTest, IOPipeTest4) {
	Base* cmd1 = new Command("ls");
	Base* cmd2 = new Command("");
	IOPipe * connector = new IOPipe(cmd1,cmd2);

	EXPECT_FALSE(connector->execute());
	delete connector;
}



int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
