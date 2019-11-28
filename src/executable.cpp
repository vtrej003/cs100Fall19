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
    cmd = const_cast<char*>(execName.c_str());
    args[0] = const_cast<char*>(execName.c_str());
    args[1] = const_cast<char*>(argList.c_str());
    std::cout<<"This is what will be loaded as a Command:'"<< cmd << "'\nExecutable:'"<< args[0] <<"'\nArgument:'"<< args[1] <<"'"<<std::endl;

}

void Executable::execute()
{  
    //shot in the dark but on the spot strtok typecast
    //char* args[3] = { (char*)execName.c_str(), (char*)argList.c_str(), NULL};
    std::cout<<"EXECUTING...\n";    
    execvp(cmd, args);
    std::cout << "Ending executables execute call and returning exit(1)\n \n";
    
    std::cout<<"This is what was loaded as a Command:'"<< cmd << "'\nExecutable:'"<< args[0] <<"'\nArgument:'"<< args[1] <<"'"<<std::endl;
    exit(420);
}

std::string Executable::print()
{
    return execName;
}


