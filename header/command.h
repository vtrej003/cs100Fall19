#ifndef __COMMAND_H__
#define __COMMAND_H__
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

class Command
{
    private: 
	static bool mExToken;//is set to true if an executable executes, set to false
			     //if it doesn't	
	static std::string mConnector;//Keeps track of what the current composite is;
    public:
        Command();
        virtual void execute() = 0;
	void setToken (bool);
	void setConnector(std::string);
	bool getToken();
        std::string getConnector();
	//virtual void setExToken() = 0;
};
#endif //__COMMAND_H__
