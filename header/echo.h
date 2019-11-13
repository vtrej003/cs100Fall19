#ifndef __ECHO_H__
#define __ECHO_H__
#include "commands.h"

class Echo : Commands
{
    public:
        Echo();
        virtual void execute();
        virtual std::string print();
    private
        std::string name;
}
#endif//__ECHO_H__
