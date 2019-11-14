#ifndef __SYSCALL_TEST__HPP__
#define __SYSCALL_TEST__HPP__

#include "gtest/gtest.h"

#include "syscall.hpp"

TEST(SysCallTest, SaySomethingImgivingUpOnYou) {
    
    EXPECT_EQ(test->evaluate(), 8);
}



#endif //__SYSCALL_TEST_HPP__
