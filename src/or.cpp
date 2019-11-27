#include "../header/or.h"

Or::Or(Command* lCom, Command* rCom) {
 leftCommand = lCom;
 rightCommand = rCom;
}

void Or::execute() {
 pid_t childPid = fork();
 bool flagStatus = true;
 int status = 0;
    if(childPid < 0){//Child not created{
            perror("fork");
            exit(EXIT_FAILURE);
    }
    else if(childPid !=  0)// this what the parent does
    {
 waitpid(childPid, &status, 0);
// std::cout<< "Status: " << status<<std::endl;
 if ((WEXITSTATUS(status) != 0) && WIFEXITED(status)){
  // std::cout<<"Status*: " << status << std::endl;
   std::cout<<"Executing right\n";
   rightCommand->execute();
 }
 std::cout<<status<<std::endl;
    }
    else //this is what child does
    {
   std::cout<<"Executing left\n";
   leftCommand->execute();
 }

}



std::string Or::print() {
 return "Executed";

}


