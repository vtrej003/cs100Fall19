#include "../header/and.h"

And::And(Command* lCom, Command* rCom, bool pFound) {
	leftCommand = lCom;
	rightCommand = rCom;
	parenFound = pFound;
}

void And::execute() {
	pid_t childPid = fork();
	bool flagStatus = true;
	int status = -1;
	std::string connector = "&&";
	waitpid(childPid, &status, 0);
	//std::string connector = "&&";
    if(childPid < 0){//Child not created{
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if(childPid !=  0)// this what the parent does
    {
//	std::cout<<"Parenthesis status (0 = none found, 1 = found): "<<parenFound<<std::endl;
	if (Command::mParenToken == false && (parenFound == true)){
		Command::mParenToken = parenFound;
	}
	//waitpid(childPid, &status, 0);
	Command::setConnector(connector);
	if ((WEXITSTATUS(status) == 2) && WIFEXITED(status) && Command::mParenToken == false){Command::setToken(true);} 
	//Parenthesis condition
	else if ((WEXITSTATUS(status) == 2) && (WIFEXITED(status)) && mParenToken == true){Command::setToken(false);}
	else if ((WEXITSTATUS(status) == 3) && WIFEXITED(status)){Command::setToken(false);}
	else if ((WEXITSTATUS(status) != 0) && WIFEXITED(status)){Command::setToken(false);}
	std::cout<<"Executing right\n";	
	rightCommand->execute();
	Command::setToken(false);
	std::cout<<"Command does not exist.\n";
	exit(420);
    }
    else //this is what child does
    {
	std::cout<<"Executing left\n";
	leftCommand->execute();
//	std::cout<<"Executing left failed\n";
        //Command::setToken(false);
        std::cout<<"Command does not exist.\n";
	exit (420);
    }
	
}




