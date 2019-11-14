#pragma once
#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "NegThreeOpMock.hpp"
#include "ZeroOpMock.hpp"
#include "MockOpPosFour.hpp"
#include "/home/csmajs/aestr074/lab-05-strategy-pattern-vincent_andres_lab_5/ops/add.hpp"

TEST(AddTest, Add_OpOp_Eval) {
    NegThreeOpMock* mockNegThree = new NegThreeOpMock();
    MockOpPosFour* mockPosFour = new MockOpPosFour();
    Add* test = new Add(mockNegThree, mockPosFour);
    std::cout << test->stringify() + "\n";
    EXPECT_EQ(test->evaluate(), 1);
}
TEST(AddTest, Add_Nested_Eval) {
    NegThreeOpMock* mockNegThree = new NegThreeOpMock();
    MockOpPosFour* mockPosFour = new MockOpPosFour();
    Add* mockAdd = new Add(mockNegThree,mockPosFour);
    std::cout << "mockAdd Created\n";
    Add* test = new Add(mockAdd,mockPosFour);
    std::cout << test->stringify() + "\n";
    EXPECT_EQ(test->evaluate(), 5);
}
TEST(AddTest, Add_OP_Zero_Eval) {
    NegThreeOpMock* mockNegThree = new NegThreeOpMock();
    ZeroOpMock* mockZero = new ZeroOpMock();
    Add* test = new Add(mockNegThree,mockZero);
    std::cout << "mockAdd Created\n";
    std::cout << test->stringify() + "\n";
    EXPECT_EQ(test->evaluate(), -3);
}
#endif //__ADD_TEST_HPP__

