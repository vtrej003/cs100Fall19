#include <iostream>
#include <algorithm>
#include "../src/query.cpp"
#include "../header/parser.h"
#include "../src/parser.cpp"
#include "../header/executable.h"
#include "../header/semicolon.h"
#include "../header/and.h"
#include "../header/or.h"
#include "../header/command.h"
#include "../src/prompt.cpp"
#include "../header/instantiator.h"
#include "../header/ioRedirect.h"
#include "../header/inputRedirect.h"
#include "../header/outputRedirect.h"
#include "../header/outputAppendRedirect.h"

//#include "../src/instantiator.cpp"
//#include "../src/and.cpp"
//#include "../src/or.cpp"
//#include "../src/executable.cpp"
//#include "../src/semicolon.cpp"
int main(int argc, char **argv)
{
     //std::string destination;
    /*for (int i = 1; i < argc; ++i) {
        std::cout << argv[i] << " ";
    }*/
    do
    {
	      Command* cmd;
        std::string str = " ";
        prompt();
        Parser p;
	cmd = p.parse(query());
        std::cout<<"Input Parsed\n";
        cmd->execute();
	std::cout<<"Command Executed.\n";
    }while(true);

    return 0;
} 
