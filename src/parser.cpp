#include "../header/parser.h"
#include "../header/command.h"
#include "../header/and.h"
#include "../header/or.h"
#include "../header/semicolon.h"
#include "../header/executable.h"
#include "../src/and.cpp"
#include "../src/or.cpp"
#include "../src/semicolon.cpp"
#include "../src/executable.cpp"

Parser::Parser(std::string str){
    strToParse = str;   
}
Command* Parser::parse(){
	std::string result;
	std::string cmd = strToParse;
	std::vector<std::string> listOfConnectors({ "&&", "||", ";" });
	//step one: seperate from commands from connector
	std::string leftCom, rightCom, connector;// 1.commands and connector
	std::string leftExec, rightExec;//2.execs
	std::string leftArg, rightArg;//3 args
								  //substring left command
	std::size_t startOfCon;
	std::string connectorUsed;
	bool connectorFound;
	for (int i = 0; i < cmd.size(); i++) {
		if (((cmd.at(i) == '&') && (cmd.at(i + 1) == '&')) || ((cmd.at(i) == '|') && (cmd.at(i + 1) == '|')) || (cmd.at(i) == ';' )){
			startOfCon = cmd.find(cmd.at(i));
			connectorUsed = cmd.at(startOfCon);
			break;
		}
	}
	std::cout << "pos from start: " << startOfCon << std::endl;      
	leftCom = cmd.substr(0, startOfCon);

	//substring right command
	std::size_t endOfCon = cmd.find_last_of(connectorUsed);
	std::cout << "position of last of: " << endOfCon << std::endl;

	rightCom = cmd.substr(endOfCon + 2);

	//connector
	connector = cmd.substr(startOfCon, endOfCon - startOfCon + 1);

	//parse left exec and alg
	std::size_t lExecPos = leftCom.find(" ");
	leftExec = leftCom.substr(0, lExecPos);
	leftArg = leftCom.substr(lExecPos + 1);

	//parse right exec alg
	std::size_t rExecEndPos = rightCom.find(" ");

	std::cout << "what is rexecpos:" << rExecEndPos << std::endl;
	rightExec = rightCom.substr(0, rExecEndPos);
	rightArg = rightCom.substr(rExecEndPos);
	Command* leftExqt = new Executable(leftExec, leftArg);
	Command* rightExqt = new Executable(rightExec, rightArg);
	if ( connector == "&&"){
		*Command connector = new And(leftExqt, rightExqt);
	}
	else if ( connector == "||"){
		*Command connector = new Or(leftExqt, rightExqt);
	}	
	else if ( connector == ";"){
		*Command connector = new Semicolon(leftExqt, rightExqt);
	}
	std::cout << "Left Exec:" << leftExec << "\nLeft Alg:" << leftArg << std::endl;
	std::cout << "Connector is:" << connector << std::endl;
	std::cout << "Right Exec:" << rightExec << "\nRight Alg:" << rightArg << std::endl;
	return connector;

}

