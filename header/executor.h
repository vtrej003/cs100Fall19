#ifndef __SYSCALL_H__
#define __SYSCALL_H__

/*headers for fork, waitpid, execvp*/
#include <sys/types.h> //lib from fork
#include <unistd.h> // lib for fork, waitpid, execvp
#include <sys/wait.h> //lib for wait
#include <stdlib.h> //lib for wait
#include <stdio.h> //lib for wait

/*standard headers*/
#include <iostream>
#include <string>

class SysCall(char[])
{
    public:
        SysCall();
        SysCall()(char[]);
    
        void execute(char[]);
        std::string getChildPid();
    
    private:
	char *const execArgs[] = {"/bin/ls", "-l", NULL};
	
    }
}
#endif //SYSCALL_H_
