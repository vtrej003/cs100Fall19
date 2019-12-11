#include "../header/pipe.h"
Pipe::Pipe(Command* lCom, Command* rCom, bool pFound) {
        leftCommand = lCom;
        rightCommand = rCom;
        parenFound = pFound;
}


void Pipe::execute(){

    int pipefd[2];
    int status;
    int done = 0;
    pid_t childPid;
    pipe(pipefd);

    childPid = fork();
    //waitpid(-1, &status, 0); 
    if(childPid == 0) //this is what child does
    {
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	leftCommand->execute();
        std::cout<<"Command does not exist.\n";
        exit (420);
    }
    childPid = fork();
    waitpid(-1, &status, 0);
    if(childPid == 0){
	close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        rightCommand->execute();

	
    }
    /*if (childPid <0){
	perror("fork");
	exit(EXIT_FAILURE);	
    }*/
     
    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(-1, &status, 0);
    waitpid(-1, &status, 0);



}
