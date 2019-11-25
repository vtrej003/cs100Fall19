#include "../header/semicolon.h"

Semicolon::Semicolon(Command* lCom, Command* rCom){
    leftCommand = lCom;
    rightCommand = rCom;
}

 void Semicolon::execute(){
    pid_t childPid = fork();
    int status = -1;
    if(childPid < 0){//Child not created{
            perror("fork");
            exit(EXIT_FAILURE);
    }
    else if(childPid !=  0)// this what the parent does
    {
        waitpid(childPid, &status, 0);
        std::cout<<"Executing right\n";
        rightCommand->execute();        
    }
    else //this is what child does
    {
        std::cout<<"Executing left\n";
        leftCommand->execute();
    }
}	
std::string Semicolon::print(){

}
