#ifndef __PARSER_H__
#define __PARSER_H__

#include <iostream>
#include <string>
//#include <stdio.h>
#include <vector>
class Parser{
    private:
        std::string strToParse;
    public:
        Parser(std::string);
	std::string parse();
};

#endif //__PARSER_H__
