#ifndef __TEST_H__
#define __TEST_H__
//#include <boost/filesystem.hpp>
#include "command.h"
//namespace filesys = boost::filesystem

class Test : public Command{
    public:
	Test(std::string);
        Test(std::string, std::string);
        virtual void execute();
        virtual std::string print();
  
    protected:
	std::string flag;
	std::string argList;
	char* cmd;
	char* args[3];
};
#endif //__TEST_H__
