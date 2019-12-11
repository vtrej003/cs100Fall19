#ifndef __PARENTHESIS_H__
#define __PARENTHESIS_H__
#include "command.h"
class Parenthesis : public Command{
    protected:
	std::string str; 
    public:
	Parenthesis(std::string);
	virtual void execute()=0;
	virtual std::string print()=0;
};
#endif
