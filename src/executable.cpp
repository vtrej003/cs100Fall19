#include "../header/executable.h"

Executable::Executable(std::string exec)
{
    execName = exec;
    //argList = " "; // might work might not
    args[0] = (char*)exec.c_str();

}

Executable::Executable(std::string exec, std::string arg)
{
    execName = exec;
    argList = arg;
    args[0] = (char*)exec.c_str();
    args[1] = (char*)arg.c_str();
}

void Executable::execute()
{  
    //shot in the dark but on the spot strtok typecast
    //char* args[3] = { (char*)execName.c_str(), (char*)argList.c_str(), NULL};
    std::cout<<"EXECUTING...\n";    
    execvp(args[0], args);
    std::cout << "Ending executables excute call and returning exit(1)\n \n";
    exit(420);
    
}

std::string Executable::print()
{
    return execName;
}


