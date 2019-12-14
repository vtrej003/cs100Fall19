#ifndef __PARSER_H__
#define __PARSER_H__

#include <iostream>
#include <string>
#include <vector>
#include "test.h"
#include "command.h"
#include "and.h"
#include "or.h"
#include "semicolon.h"
#include "executable.h"
#include "pipe.h"
#include "inputRedirect.h"
#include "outputRedirect.h"
#include "outputAppendRedirect.h"

class Command;
class Parser{
    public:
	Command* parse(std::string);
	Command* instantiate (std::string, std::string);
	Command* instantiate (Command*, Command*, std::string, bool);
        Command* instantiate (Command*,std::string);//decorator redirect
	std::string redirector(int, std::string);
};

#endif //__PARSER_H__
