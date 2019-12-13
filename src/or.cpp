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
    
   if (WEXITSTATUS(status) != 0){
	Command::mExToken = false;
   }
   else {
        Command::mExToken = true;
   }

    /*std::cout<<"*Exited with status: "<< WEXITSTATUS(status)<<std::endl;
    std::cout<<"*parenToken set to: "<< Command::mParenToken<<std::endl;
    std::cout<<"mExToken is currently: "<<Command::mExToken<<std::endl;
    */
    if(childPid < 0){//Child not created.
            perror("fork");
            exit(EXIT_FAILURE);
    }
    else if(childPid !=  0){//this is what parent does once child is done.
	bool insideParen = Command::mParenToken;
	if (WEXITSTATUS(status) != 0){
                Command::mExToken = false;
        }
        else {
        	Command::mExToken = true;
        }
	
	Command::mExitStatus = WEXITSTATUS(status);
	Command::setConnector(connector);
	std::cout<<"*Exited with status: "<< WEXITSTATUS(status)<<std::endl;
        std::cout<<"*parenToken set to: "<< Command::mParenToken<<std::endl;
        std::cout<<"mExToken is currently: "<<Command::mExToken<<std::endl;
        if ((WEXITSTATUS(status) == 1) && WIFEXITED(status) && Command::mParenToken == false){
		Command::mExToken = false; 
		std::cout<<"\nmExToken set to " <<Command::mExToken<<std::endl;
	}
	/*else if ((WEXITSTATUS(status) == 2) && WIFEXITED(status) && Command::mParenToken == false){
                Command::mExToken = true;
        }

	//exit 3, last connector exited was an and, we still want to execute this
	else if ((WEXITSTATUS(status) == 3) && WIFEXITED(status) && Command::mParenToken == true){
		std::cout<<"\n WE HAVE PARENTHESIS\n";
		Command::mExToken = true;
	}
	else if ((WEXITSTATUS(status) == 3) && WIFEXITED(status) && Command::mParenToken == false ){
		Command::mExToken = true;
	}*/
	else if (WEXITSTATUS(status) == 1 && WIFEXITED(status) && Command::mParenToken == true){
		 Command::mExToken = false;
		 std::cout<<"\nmExToken set to " <<Command::mExToken<<std::endl;
	}
	else if (WEXITSTATUS(status) == 0 && WIFEXITED(status) && Command::mParenToken == false){
                Command::mExToken = true;
                std::cout<<"\nmExToken set to " <<Command::mExToken<<std::endl;
        }
	else if (WEXITSTATUS(status) == 0 && WIFEXITED(status) && Command::mParenToken == true){
                Command::mExToken = true;
                std::cout<<"\nmExToken set to " <<Command::mExToken<<std::endl;
        }

	/*else {
		Command::mExToken = true;
	}*/
     //       std::cout<<"Executing right\n";
       // Command::setToken(true);
    //    std::cout<<"*Exited with status: "<< WEXITSTATUS(status)<<std::endl;
	std::cout<<"*Executing right\n";
	Command::mParenToken = parenFound; // If currently in a paren, set true
	std::cout <<"**parenToken: "<< Command::mParenToken<<std::endl;
	rightCommand->execute();
	//std::cout<<"*Right failed.\n";
	Command::mExToken = false;
	std::cout<<"*Command does not exist\n";
        exit(1);
	
    }
    else //if child exists this is what child does.
    {
  //      Command::setToken(true);
        std::cout<<"*Executing left\n";
        leftCommand->execute();
//	std::cout<<"*Left Failed.\n";
	//Command::setToken(false);
//	std::cout<<"*Command does not exist\n";
	//exit(0);
    }

}


