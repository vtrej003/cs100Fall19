#include "../header/executable.h"

Executable::Executable(std::string a)
{
    execName = a;
    argList = NULL;// might work might not
}

Executable::Executable(std::string exec, std::string arg)
{
    execName = exec;
    argList = arg;
}

virtual void Executable::execute()
{
    //shot in the dark but on the spot strtok typecast
    execvp((char*)execName.c_str(),{(char*)argList.c_str(), NULL});

}

