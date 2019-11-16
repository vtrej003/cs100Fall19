#ifndef __EXECUTABLE_H__
#define __EXECUTABLE_H__

#include "command.h"

class Executable : Command
{
    public:
        Executable(std::string);
        Executable(std::string, std::string);
        virtual void execute();
        virtual std::string print();
    protected:
        std::string name;
}
#endif //__EXECUTABLE_H__
