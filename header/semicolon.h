#ifndef __SEMICOLON_H__
#define __SEMICOLON_H__

#include "command.h"

class Semicolon : public Command
{
    public:
        Semicolon(Command*, Command*);
        virtual void execute();
    protected:
        Command* leftCommand;
        Command* rightCommand;
        
        std::string name = ";";
};
#endif //__SEMICOLON_H__
