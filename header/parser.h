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
#include "parenthesis.h"

class Command;
class Parser{
    public:
	      Command* parse(std::string);
	      Command* instantiate (std::string, std::string);
	      Command* instantiate (Command*, Command*, std::string, bool);
        Command* instantiateRedirect(std::string);//decorator redirect
  
};

#endif //__PARSER_H__
