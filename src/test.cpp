#include "../header/test.h"

Test::Test(std::string flagList)
{
    flag = flagList;
    //argList = " "; // might work might not
    args[0] = (char*)flag.c_str();

}

Test::Test(std::string nFlag, std::string arg)
{
    flag = nFlag;
    cmd = "test";
    args[0] = "test";
    if (flag == "-e" || flag == "-d" || flag == "-f"){
    	args[1] = const_cast<char*>(flag.c_str());
    	args[2] = const_cast<char*>(arg.c_str());
    }
    else{
	args[1] = const_cast<char*>(flag.c_str());
        args[2] = const_cast<char*>(flag.c_str());
    }
}

void Test::execute()
{
    std::cout<<"EXECUTING...\n";
    std::cout<<"Inside test bit "<<"'"<<args[1]<<"'"<<std::endl;
    if((!access((char*)args[2], F_OK))){
		if (flag == "-e"){
			std::cout<<"(True)\n";
			exit(0);
		}
		else if (flag == "-d"){
			struct stat path_stat;
			stat(args[2],&path_stat);
			if (S_ISDIR(path_stat.st_mode) == 1){
				std::cout<<"(True*)\n";
			}
			else {std::cout<<"(False*)\n";}
			
		}
		else if (flag == "-f"){
			struct stat path_stat;
			stat(args[2],&path_stat);
			if(S_ISREG(path_stat.st_mode) == 1){
				std::cout<<"(True**)\n";
			}
			else {std::cout<<"(False**)\n";}
		}
		else {std::cout<<"(True)\n";}
	}
    else{ 
	std::cout<<"(False)\n";
	exit(1);
    }

}


