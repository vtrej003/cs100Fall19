#include <iostream>
#include "../src/query.cpp"
#include "../header/parser.h"
#include "../src/parser.cpp"
#include "../header/executable.h"
#include "../header/semicolon.h"
#include "../header/and.h"
#include "../header/or.h"
#include "../header/command.h"
#include "../src/prompt.cpp"
//#include "../src/and.cpp"
//#include "../src/or.cpp"
//#include "../src/executable.cpp"
//#include "../src/semicolon.cpp"
int main(int argc, char **argv)
{
     //std::string destination;
    for (int i = 1; i < argc; ++i) {
        std::cout << argv[i] << " ";
    }
    //do
    /*{
        Command* userCMD;
	std::vector<std::string> oCMD;
        prompt();
    	Parser p(query());
	p.parse(oCMD);
	std::cout<<"Parsed string loaded into rshell vector.\n";
	std::cout <<oCMD.at(0) << " " << oCMD.at(1) << std::endl;	
        Command* leftCMD = new Executable(oCMD.at(0),oCMD.at(1));
	std::cout<<"LeftCMD assigned in rshell.\n";
	Command* rightCMD = new Executable(oCMD.at(3),oCMD.at(4));
	std::cout<<"RightCMD assigned in rshell.\n";
	std::cout << oCMD[3] << oCMD[4] << std::endl;
	std::cout<<"This is the connector we are using: " << oCMD.at(2)<<std::endl;
	if (oCMD.at(2) == "&&"){
		userCMD = new And(leftCMD, rightCMD);
	}
	else if (oCMD.at(2) == "||"){
		userCMD = new Or(leftCMD, rightCMD);
	}
	else if (oCMD.at(2) == ";"){
		userCMD = new Semicolon(leftCMD, rightCMD);
		std::cout<<"A Semicolon object has been instantiated.\n";
        }
	std::cout<<"Parse done.\n";
	userCMD->execute();
	std::cout<<"CMD EXECUTED\n";
    }while(true);*/
    return 0;
} 
