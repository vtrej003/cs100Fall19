#include "gtest/gtest.h"
#include "../header/parser.h"
#include "../src/parser.cpp"
TEST(ParserTest, ParseString) {
    Parser test("test -e rshell || echo a"); 
    EXPECT_EQ(test.parse(), "||");
}


