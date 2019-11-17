#include "gtest/gtest.h"
#include "../header/executable.h"
#include "../src/executable.cpp"
#include "../header/command.h"
#include "../src/command.cpp"
TEST(MyExecDeathTest, ExecNormalExit) {
  Command* exec = new Executable("ls","-l");
  EXPECT_EXIT(exec->execute();, ::testing::ExitedWithCode(0), "Success");
}

TEST(MyExecFailedDeathTest, ExecNormalFailExit) {
  Command* exec = new Executable("fail");
  EXPECT_EXIT(exec->execute(), ::testing::ExitedWithCode(EXIT_FAILURE), "Exec Failed like I wanted");
}

TEST(MyClassTest, foo_death_test) {
  Command* clazz = new Executable("hellfire"); // make some_flag false so the CHECK fails
  ASSERT_DEATH( { clazz->execute(); }, "must be true");
}
