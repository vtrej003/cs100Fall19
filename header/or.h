#ifndef __OR_H__
#define __OR_H__

#include "command.h"

class Or : public Command
{
    public:
        Or(Command*, Command*, bool);
        virtual void execute();
    protected:
	Command* leftCommand;
        Command* rightCommand;
	bool parenFound;
        std::string name = "||";
};
#endif //__OR_H__
