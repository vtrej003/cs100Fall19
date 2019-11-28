#include "../header/test.h"

Test::Test(std::string flagList)
{
    flag = flagList;
    //argList = " "; // might work might not
    args[0] = (char*)flag.c_str();

}

Test::Test(std::string flag, std::string arg)
{
    cmd = "test";
    args[0] = "test";
    args[1] = const_cast<char*>(flag.c_str());
    args[2] = const_cast<char*>(arg.c_str());
    std::cout<<"This is what will be loaded as the test\n" << "executable:"<< cmd <<"\nflag: "<< args[1] << "\nArg:"<<args[2]<<std::endl;

}

void Test::execute()
{
    std::cout<<"EXECUTING...\n";
    //execvp(cmd, args);
    std::cout<<"Inside test bit "<<args[2]<<std::endl;
    if(!access((char*)args[2], F_OK)){
		std::cout<<"The file was found.\n";
		exit(0);
	}
    else{
	std::cout<<"File not found.\n";
	exit(1);
    }

}

std::string Test::print()
{
 //   return execName;
}

