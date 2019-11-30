#include "../header/command.h"
bool Command::mExToken = true;
std::string Command::mConnector = "NULL";
Command::Command(){}

void Command::execute(){}
void Command::setToken(bool token){
	mExToken = token;
}
void Command::setConnector(std::string connector){
	mConnector = connector;
}
bool Command::getToken(){
	return mExToken;
}
std::string Command::getConnector(){
	return mConnector;
}


//std::string Command::print(){}
