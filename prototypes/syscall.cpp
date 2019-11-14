/*headers for fork, waitpid, execvp*/
#include <sys/types.h> //lib from fork
#include <unistd.h> // lib for fork, waitpid, execvp
#include <sys/wait.h> //lib for wait
#include <stdlib.h> //lib for wait
#include <stdio.h> //lib for wait

/*standard headers*/
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
     
    pid_t childPid = fork();
     
    if(childPid < 0)//if child is done returns -1
    {
	perror("fork");
	exit(EXIT_FAILURE);
    }
    if(childPid !=  0)// child is 1 or greater -> parent is 0
    {
	std::cout << "*Parent PID: " << getpid() << std::endl;
	std::cout << "Child PID: " << childPid << std::endl;
	std::cout << "waiting for child to catch up!\n";
	waitpid(childPid, NULL, -1); //waits for child to catch up
    }
    else //child process exists but is not a parent process so do this
    {
	std::cout << "Parent PID: " << getppid() << std::endl; //childPID looks at parentPID -> getppid()
        std::cout << "*Child PID: " << getpid() << std::endl; //currently in childPID -> getpid()
	std::cout << "Child process should execute file here\n";
	char* args[3];
        std::string ls = "ls";
        std::string arglist = "-l";
        args[0] = (char*)ls.c_str();
        args[1] = (char*)arglist.c_str();
        args[2] = NULL;
        execvp(args[0], args);
	exit(1); 
	std::cout << "execvp error! did not ls\n"; 
	
    }

    std::cout << "i dont know";
    return 0; 
}
