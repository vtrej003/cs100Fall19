#ifndef __PARSER_H__
#define __PARSER_H__

#include <iostream>
#include <string>
#include <vector>
#include "../header/parser.h"
#include "../header/command.h"
#include "../header/and.h"
#include "../header/or.h"
#include "../header/semicolon.h"
#include "../header/executable.h"

class Parser{
    private:
        std::string strToParse;
    public:
        Parser(std::string);
	void parse(std::vector<std::string> &str);
};

#endif //__PARSER_H__
