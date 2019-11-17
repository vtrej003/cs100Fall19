#ifndef __COMMAND_H__
#define __COMMAND_H__
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <string>

class Command
{
    public:
        Command();
        
        virtual void execute() = 0;
        virtual std::string print() = 0;
};
#endif //__COMMAND_H__
