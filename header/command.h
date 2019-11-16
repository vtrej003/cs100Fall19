#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <string>

class Command
{
    public:
        virtual void execute(std::string);
        virtual std::string print();
}
#endif //__COMMAND_H__
