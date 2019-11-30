#include "../header/or.h"

Or::Or(Command* lCom, Command* rCom) {
 leftCommand = lCom;
 rightCommand = rCom;
}

void Or::execute() {
    pid_t childPid = fork();
    bool flagStatus = true;
    int status = 0;
    std::string connector = "||";
    //Command::setConnector(connector);
    //std::cout <<"\n\nConnector instantiating to "<<Command::getConnector();
    if(childPid < 0){//Child not created.
            perror("fork");
            exit(EXIT_FAILURE);
    }
    else if(childPid !=  0){//this is what parent does once child is done.
        waitpid(childPid, &status, 0);
	Command::setConnector(connector);
        //if ((WEXITSTATUS(status) != 0) && WIFEXITED(status)){ 
     //       std::cout<<"Executing right\n";
            rightCommand->execute();
        //}
    }
    else //if child exists this is what child does.
    {
     //   std::cout<<"Executing left\n";
        leftCommand->execute();
    }

}


