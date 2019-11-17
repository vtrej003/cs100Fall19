#ifndef __PARSER_H__
#define __PARSER_H__

#include <iostream>
#include <string>
#include <vector>
#include "command.h"
class Parser{
    private:
        std::string strToParse;
    public:
        Parser(std::string);
	Command* parse();
};

#endif //__PARSER_H__
