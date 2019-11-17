#ifndef __OR_H__
#define __OR_H__

#include "command.h"

class Or : public Command
{
    public:
        Or(Command*, Command*);
        virtual void execute();
        virtual std::string print();
    protected:
	Command* leftCommand;
        Command* rightCommand;
        std::string name = "||";
};
#endif //__OR_H__
