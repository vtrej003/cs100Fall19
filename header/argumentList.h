#include "command.h"

class ArgumentList : Command
{
    protected:
         char* c_string = '';
    
    public:
        ArgumentList();
        virtual void execute();   
}

