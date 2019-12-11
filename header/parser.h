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
class Command;
class Parser{
    public:
	Command* parse(std::string);
	Command* instantiate (std::string, std::string);
	Command* instantiate (Command*, Command*, std::string, bool);
};

#endif //__PARSER_H__
