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
    if(childPid < 0){//Child not created{
            perror("fork");
            exit(EXIT_FAILURE);
    }
    else if(childPid !=  0)// this what the parent does
    {
        waitpid(childPid, &status, 0);
	//waitpid(childPid, NULL, -1);
     //   std::cout << "*Parent PID: " << getpid() << std::endl;
       // std::cout << "Child PID: " << childPid << std::endl;
      //  std::cout << "waiting for child to catch up!\n";
	//std::cout << "parent* calling parent" <<getppid()<<std::endl;

        //waitpid(childPid, &status, -1); //waits for child to catch up
	//std::cout<< "Status: " << status<<std::endl;
	///if ((WEXITSTATUS(status) == 0) && WIFEXITED(status)){
//		std::cout<<"Status*: " << status << std::endl;
		Command::setConnector(connector);
		//std::cout<<"Executing right\n";	
		rightCommand->execute();
	///}
	//std::cout<<status<<std::endl;
    }
    else //this is what child does
    {
  //      std::cout << "Parent PID: " << getppid() << std::endl; //childPID looks at parentPID -> getppid()
    //    std::cout << "*Child PID: " << getpid() << std::endl; //currently in childPID -> getpid()
      //  std::cout << "Child process should execute file here\n";
        //char *const execArgs[] = {"/bin/ls", "-l", NULL};
        //execvp("ls", execArgs);
     //   exit(1);
        //std::cout << "execvp error! did not ls\n";

		//std::cout<<"Executing left\n";
		leftCommand->execute();
	}
	
}




