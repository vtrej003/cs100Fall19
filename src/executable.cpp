#include "../header/executable.h"

Executable::Executable(std::string a)
{
        char* args[3];
        std::string ls = "ls";
        std::string arglist = "-l";
        args[0] = (char*)ls.c_str();
        args[1] = (char*)arglist.c_str();
        args[2] = NULL;
        execvp(args[0], args);

         = a;
}

virtual void Executable::execute()
{
    
}

virtual std::string And::print()
{

}

