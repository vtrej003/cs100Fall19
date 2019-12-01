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
    waitpid(childPid, &status, 0);
    if(childPid < 0){//Child not created.
            perror("fork");
            exit(EXIT_FAILURE);
    }
    else if(childPid !=  0){//this is what parent does once child is done.
       // waitpid(childPid, &status, 0);
	Command::setConnector(connector);
        if ((WEXITSTATUS(status) == 2) && WIFEXITED(status)){Command::setToken(true); }
	else if ((WEXITSTATUS(status) != 0) && WIFEXITED(status)){Command::setToken(false);}
	else {Command::setToken(true);}
     //       std::cout<<"Executing right\n";
       // Command::setToken(true);
        std::cout<<"*Executing right\n";
	rightCommand->execute();
	std::cout<<"*Right failed.\n";
	Command::setToken(false);
        exit(420);
	
    }
    else //if child exists this is what child does.
    {
     //   std::cout<<"Executing left\n";
        //Command::setToken(true);
        std::cout<<"*Executing left\n";
        leftCommand->execute();
	std::cout<<"*Left Failed.\n";
	//Command::setToken(false);
	exit(420);
    }

}


