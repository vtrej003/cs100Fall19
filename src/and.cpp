#include "../header/and.h"

And::And(Command* lCom, Command* rCom, bool pFound) {
	leftCommand = lCom;
	rightCommand = rCom;
	parenFound = pFound;
}

void And::execute() {
	pid_t childPid = fork();
	bool flagStatus = true;
	//bool insideParen = Command::mParenToken;
	int status = -1;
	std::string connector = "&&";
        Command::mExitStatus = WEXITSTATUS(status);
	Command::mExitStatus = WEXITSTATUS(status);
	waitpid(childPid, &status, 0);
        if(childPid < 0){//Child not created{
        	perror("fork");
        	exit(EXIT_FAILURE);
    	}
    	else if(childPid !=  0)// this what the parent does
    	{
		bool insideParen = parenFound;
		std::cout<<"InsideParen set to "<<insideParen<<std::endl; 
		if (WEXITSTATUS(status) != 0){
                	Command::mExToken = false;
        	}
        	else {
        	        Command::mExToken = true;
        	}
        	std::cout<<"\nExited with status: "<< WEXITSTATUS(status)<<std::endl;
        	std::cout<<"parenToken is currently: " << Command::mParenToken<<std::endl;
        	std::cout<<"mExToken is currently: "<<Command::mExToken<<std::endl;
	
		Command::setConnector(connector);
		if ((WEXITSTATUS(status) == 1) && WIFEXITED(status) && Command::mParenToken == false){
			Command::mExToken = false;
			std::cout<<"\n&& mExToken set to " <<Command::mExToken<<std::endl;
			//Command::setToken(true);
		} 
		else if ((WEXITSTATUS(status) == 3) && WIFEXITED(status) && Command::mParenToken == false ){
                        Command::mExToken = true;
                        std::cout<<"\n&& *mExToken set to " <<Command::mExToken<<std::endl;
                        //Command::setToken(true);
                }
		else if ((WEXITSTATUS(status) == 3) && WIFEXITED(status) && (Command::mParenToken == true || insideParen == true)){
                        Command::mExToken = false;
                        std::cout<<"\n&& m**ExToken set to " <<Command::mExToken<<std::endl;
                        //Command::setToken(true);
                }
		else if ((WEXITSTATUS(status) == 1) && WIFEXITED(status) && Command::mParenToken == true){
                        Command::mExToken = false;
                        std::cout<<"\n&& ***mExToken set to " <<Command::mExToken<<std::endl;

                        //Command::setToken(false);
                }  
		else if (WEXITSTATUS(status) == 0 && WIFEXITED(status)){
			Command::mExToken = true;
			std::cout<<"\n&& ****mExToken set to " <<Command::mExToken<<std::endl;
		}
		std::cout<<"Executing right\n";
		Command::mParenToken = parenFound; // If currently in a paren, set true	
		std::cout<<"ParenToken**: "<<Command::mParenToken<<std::endl;
		rightCommand->execute();
		//Command::mExToken = false;
		//std::cout<<"*****Command does not exist.\n";
		//exit(0);
    	}
    	else //this is what child does
    	{
		std::cout<<"Executing left\n";
		leftCommand->execute();
		std::cout<<"Executing left failed\n";
	        //Command::setToken(false);
	        //std::cout<<"***Command does not exist.\n\n\n";
		//exit (0);
	    }
	
}




