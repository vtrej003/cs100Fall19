#ifndef __OR_H__
#define __OR_H__

#include "command.h"

class Or : Command
{
    public:
        Or(Command*, Command*)
        virtual void execute();
        virtual std::string print();
    private:
	Command* leftCommand;
        Command* rightCommand;
        std::string name = "||";
}
#endif //__OR_H__
