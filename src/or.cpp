#include "../header/or.h"

Or::Or(Command* lCom, Command* rCom, bool pFound) {
 leftCommand = lCom;
 rightCommand = rCom;
 parenFound = pFound;
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
      //  std::cout<<"Parenthesis status (0 = none found, 1 = found): "<<parenFound<<std::endl;
	
        if (Command::mParenToken == false && (parenFound == true)){
                Command::mParenToken = parenFound;
        }
	Command::setConnector(connector);
        if ((WEXITSTATUS(status) == 2) && WIFEXITED(status)){Command::setToken(false); }
	//exit 3, last connector exited was an and, we still want to execute this
	else if ((WEXITSTATUS(status) == 3) && (WIFEXITED(status)) && (mParenToken == true)){Command::setToken(false);}
	else if ((WEXITSTATUS(status) == 3) && WIFEXITED(status)){Command::setToken(false);}
	else if ((WEXITSTATUS(status) != 0) && WIFEXITED(status)){Command::setToken(false);}
	else {Command::setToken(true);}
     //       std::cout<<"Executing right\n";
       // Command::setToken(true);
        //std::cout<<"*Executing right\n";
	rightCommand->execute();
	//std::cout<<"*Right failed.\n";
	Command::setToken(false);
	std::cout<<"Command does not exist\n";
        exit(420);
	
    }
    else //if child exists this is what child does.
    {
     //   std::cout<<"Executing left\n";
        //Command::setToken(true);
     //   std::cout<<"*Executing left\n";
        leftCommand->execute();
//	std::cout<<"*Left Failed.\n";
	//Command::setToken(false);
	std::cout<<"Command does not exist\n";
	exit(420);
    }

}


