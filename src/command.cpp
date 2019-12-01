#include "../header/command.h"
bool Command::mExToken = true;
bool Command::mParenToken = false;
std::string Command::mConnector = "NULL";

Command::Command(){}

void Command::execute(){}
void Command::setToken(bool token){
	mExToken = token;
	std::cout<<"Executable token had been called and set to: " << mExToken<<std::endl;
}
void Command::setParenToken(bool token){
        mParenToken = token;
}
void Command::setConnector(std::string connector){
	mConnector = connector;
}
bool Command::getToken(){
	std::cout<<"Executable token had been called and is returning: " << mExToken<<std::endl;
	return mExToken;
}
bool Command::getParenToken(){
        return mParenToken;
}
std::string Command::getConnector(){
	return mConnector;
}


//std::string Command::print(){}
