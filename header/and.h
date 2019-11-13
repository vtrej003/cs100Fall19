#ifndef __AND_H__
#define __AND_H__

#include "command.h"

class And : Command
{
    public:
        And(Command*, Command*)
        virtual void execute();
        virtual std::string print();
    protected:
        Command* leftCommand;
        Command* rightCommand;
        
        std::string name = "&&";
}
#endif //__AND_H__
