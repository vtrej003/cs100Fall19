#include "../header/and.h"

And::And(Command* lCom, Command* rCom) {
	leftCommand = lCom;
	rightCommand = rCom;
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
	//waitpid(childPid, &status, 0);
	Command::setConnector(connector);
	if ((WEXITSTATUS(status) == 2) && WIFEXITED(status)){Command::setToken(true); }
	else if ((WEXITSTATUS(status) != 0) && WIFEXITED(status)){Command::setToken(false);}
	std::cout<<"Executing right\n";	
	rightCommand->execute();
	Command::setToken(false);
	exit(420);
    }
    else //this is what child does
    {
	std::cout<<"Executing left\n";
	leftCommand->execute();
	std::cout<<"Executing left failed\n";
        //Command::setToken(false);
	exit (420);
    }
	
}




