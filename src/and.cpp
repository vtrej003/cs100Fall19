#include "../header/and.h"

And::And(Command* lCom, Command* rCom) {
	leftCommand = lCom;
	rightCommand = rCom;
}

void And::execute() {
	pid_t childPid = fork();
	bool flagStatus = true;
	int status;
    if(childPid < 0){//Child not created{
            perror("fork");
            exit(EXIT_FAILURE);
    }
    else if(childPid !=  0)// this what the parent does
    {
	//waitpid(childPid, NULL, -1);
        std::cout << "*Parent PID: " << getpid() << std::endl;
        std::cout << "Child PID: " << childPid << std::endl;
        std::cout << "waiting for child to catch up!\n";


        waitpid(childPid, &status, -1); //waits for child to catch up
	std::cout<<status<<std::endl;
	if (WEXITSTATUS(status) != 69 ){
		std::cout<<"Executing right\n";	
		rightCommand->execute();
	}
	std::cout<<status<<std::endl;
    }
    else //this is what child does
    {
        std::cout << "Parent PID: " << getppid() << std::endl; //childPID looks at parentPID -> getppid()
        std::cout << "*Child PID: " << getpid() << std::endl; //currently in childPID -> getpid()
        std::cout << "Child process should execute file here\n";
        //char *const execArgs[] = {"/bin/ls", "-l", NULL};
        //execvp("ls", execArgs);
     //   exit(1);
        //std::cout << "execvp error! did not ls\n";

		std::cout<<"Executing left\n";
		leftCommand->execute();
		std::cout<<"left failed"<<std::endl;
		flagStatus = false;
		exit(69);
	}
	
}



std::string And::print() {
	return "Executed";

}


