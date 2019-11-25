#include "../header/parser.h"
Parser::Parser(std::string str){
    strToParse = str;   
}
void Parser::parse(std::vector<std::string> &result ){
	std::string cmd = strToParse;
	std::vector<std::string> listOfConnectors({ "&&", "||", ";" });
	//step one: seperate from commands from connector
	std::string leftCom, rightCom;
        std::string connector;// 1.commands and connector
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
	leftCom = cmd.substr(0, startOfCon);
	//substring right command
	std::size_t endOfCon = cmd.find_last_of(connectorUsed);
	rightCom = cmd.substr(endOfCon + 2);
	//connector
	connector = cmd.substr(startOfCon, endOfCon - startOfCon + 1);

	//parse left exec and alg
	std::size_t lExecPos = leftCom.find(" ");
	leftExec = leftCom.substr(0, lExecPos);
	leftArg = leftCom.substr(lExecPos + 1);
	std::cout<<"This is what is loaded into leftArg:"<<leftArg<<"."<<std::endl;

	//parse right exec alg
	std::size_t rExecEndPos = rightCom.find(" ");
	rightExec = rightCom.substr(0, rExecEndPos);
	rightArg = rightCom.substr(rExecEndPos+1);
	Command* leftExqt = new Executable(leftExec, leftArg);
	Command* rightExqt = new Executable(rightExec, rightArg);

	result.push_back(leftExec); 
	result.push_back(leftArg); 
	result.push_back(connector);
	result.push_back(rightExec);
	result.push_back(rightArg);
 	std::cout<<"Displaying Vector:\n";	
	for (int it = 0; it < result.size(); it++){
		std::cout<<"At [" << it << "]: " << result.at(it) << std::endl;
	
	}
//	return result;
}

