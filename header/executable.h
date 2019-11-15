#ifndef __EXECUTABLE_H__
#define __EXECUTABLE_H__

#include "command.h"

class Executable : public Command
{
    public:
        Executable(std::string);
        Executable(std::string, std::string);
        
        virtual void execute();
        virtual std::string print();
    protected:
        std::string execName;
        std::string argList;
        char* args[3];
};
#endif
