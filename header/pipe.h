#ifndef __PIPE_H__
#define __PIPE_H__

#include "command.h"

class Pipe : public Command{
    public:
        Pipe(Command*, Command*, bool);
        virtual void execute();
    protected:
        Command* leftCommand;
        Command* rightCommand;
        bool parenFound;
        std::string name = "|";
};
#endif //__PIPE_H__

