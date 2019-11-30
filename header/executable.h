#ifndef __EXECUTABLE_H__
#define __EXECUTABLE_H__

#include "command.h"
#include <sys/stat.h>
class Executable : public Command
{
    public:
        Executable(std::string);
        Executable(std::string, std::string);
        Executable(std::string, std::string, bool);
        virtual void execute();
	void testExecute();
	//virtual void setExToken();
//    protected:
  //      std::string execName;
    //    std::string argList;
      //  char* cmd;
        //char* args[3];
    private:
	bool mIsTest;
	std::string argList;
	std::string flag;
	std::string execName;
	char* cmd;
	char* args[3];
};
#endif //__EXECUTABLE_H__
