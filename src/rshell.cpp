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
//#include "../src/instantiator.cpp"
//#include "../src/and.cpp"
//#include "../src/or.cpp"
//#include "../src/executable.cpp"
//#include "../src/semicolon.cpp"
int main(int argc, char **argv)
{
    do
    {
	Command* cmd;
        std::string str = " ";
        prompt();
    	Parser p;
	cmd = p.parse(query());
	std::cout<<"Input Parsed\n";
	cmd->execute();
	//exit(420);
    }while(true);
    return 0;
} 
