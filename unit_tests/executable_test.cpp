#include "gtest/gtest.h"
#include "../header/executable.h"

TEST(MyExDeathTest, execFuncTest) {
    //ASSERT_DEATH({
        Command* lsCommand = new Executable("ls", "-l");
        ASSERT_DEATH({
        lsCommand->execute();
        }, "error on line .* of execFuncTest()");
}
    
//TEST(MyExeDeathTest, executeCall) {
//    ASSERT_DEATH({int n = 5; ExecuteCall(&n);}, "Error on line .* of Foo()");
//   }
    
TEST(ExSucDeathTest, execFunNormalExit){
    Command* lsCommand = new Executable("ls", "-l");
    //lsCommand->execute();
    EXPECT_EXIT(lsCommand->execute(), ::testing::ExitedWithCode(0), "Success");           }
  
TEST(ExFailDeathTest, KillMyself){
    Command* lsCommand = new Executable("ls", "-l");
    //lsCommand->execute();
    EXPECT_EXIT(lsCommand->execute(), ::testing::KilledBySignal(SIGKILL), "Sending myself unblockable signal");
}

