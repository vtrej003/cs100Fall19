#include "gtest/gtest.h"
//#include "../prototype/syscall_test.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
