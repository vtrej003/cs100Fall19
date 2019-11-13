#ifndef __SEMICOLON_H__
#define __SEMICOLON_H__

#include "command.h"

class Semicolon : Command
{
    public:
        Semicolon(Command*, Command*)
        virtual void execute();
        virtual std::string print();
    protected:
        Command* leftCommand;
        Command* rightCommand;
        
        std::string name = ";"
}
#endif //__SEMICOLON_H__
