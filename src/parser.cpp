#include "../header/parser.h"
Parser::Parser(std::string str){
    strToParse = str;   
}
void Parser::parse(std::vector<std::string*> result ){
	std::string cmd = strToParse;
	std::vector<std::string> listOfConnectors({ "&&", "||", ";" });
	//step one: seperate from commands from connector
	std::string leftCom, rightCom;
        std::string*  connector;// 1.commands and connector
	std::string* leftExec, rightExec;//2.execs
	std::string* leftArg, rightArg;//3 args
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

//	std::cout << "what is rexecpos:" << rExecEndPos << std::endl;
	rightExec = rightCom.substr(0, rExecEndPos);
	rightArg = rightCom.substr(rExecEndPos);
	Command* leftExqt = new Executable(leftExec, leftArg);
	Command* rightExqt = new Executable(rightExec, rightArg);
	std::cout<<"Connector is: " << connector<<std::endl;
	if ( connector == "&&"){
		connector = "0";
	}
	else if ( connector == "||"){
		connector = "1";
	}	
	else if ( connector == ";"){
		connector= "2";
	}
	std::cout << "Left Exec:" << leftExec << "\nLeft Alg:" << leftArg << std::endl;
	std::cout << "Connector is:" << connector << std::endl;
	std::cout << "Right Exec:" << rightExec << "\nRight Alg:" << rightArg << std::endl;
	result.push_back(leftExec); 
	result.push_back(leftArg); 
	result.push_back(connector);
	result.push_back(rightExec);
	result.push_back(rightArg);
 	std::cout<<"ALLDONE\n";	
}

