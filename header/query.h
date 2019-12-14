#ifndef __QUERY_H__
#define __QUERY_H__
#include <iostream>
#include <string>

class Query
{
    public:
        Query();
	std::string query();
	bool validCheck(char);
	bool redirectSyntax(std::string);
};
#endif
