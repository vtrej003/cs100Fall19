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
    do
    {
        Command* userCmd;
        prompt();
    	Parser p(query());
	p.parse(userCmd);
	std::cout<<"Parse done.\n";
//	userCmd->execute();
    }while(true);
    return 0;
} 
