#include "gtest/gtest.h"
#include "../header/executable.h"
#include "../src/executable.cpp"
#include "../header/command.h"
#include "../src/command.cpp"
#include "../header/and.h"
#include "../src/and.cpp"
TEST(andTest, someTest) {
  Command* exec = new Executable("ls", "-l");
  Command* exec2 = new Executable("ls");
  Command* test = new And(exec, exec2);
  EXPECT_EXIT(test->execute(), ::testing::ExitedWithCode(1), "And exited successfully");
}

