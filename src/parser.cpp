#include "../header/parser.h"
Command* Parser::parse(std::string strToParse){
	std::string cmd = strToParse;
	std::vector<std::string> listOfConnectors({ "&&", "||", ";" });
	//step one: seperate from commands from connector
	std::string rightCom;
        std::string connector = "NULL";// 1.commands and connector
	std::string exec;//2.exe
	std::string arg;//3 args
	int connectorSize = 0;
	bool connectorFound = false;	
	
	Command* leftCMD;
        Command* rightCMD;
        Command* connectedCMD;
	Command* setPToken; // used to set mParToken to true or false
	for (int i = 0; i < cmd.size(); i++) {
                if (((cmd.at(i) == '&') && (cmd.at(i + 1) == '&')) || ((cmd.at(i) == '|') && (cmd.at(i + 1) == '|')) || (cmd.at(i) == ';' )){
                        connector = cmd.at(i);
                        if(connector == "&" || connector == "|"){connectorSize = 3;}
                        else {connectorSize = 2;}
			connectorFound = true;
                        break;
                }
		else if(cmd.at(i) == '('){
			std::cout<<"Erasing left parenthesis...\n";
			cmd.erase(cmd.begin() + i);
			std::cout<<"This is what is left of cmd: '"<<cmd<<"'\n";
			std::size_t rightParPos = cmd.find(')');
			if (rightParPos != std::string::npos){
				std::cout<<"Erasing right parenthesis...\n";
				cmd.erase(cmd.begin() + rightParPos);
				std::cout<<"This is what is left of cmd: '"<<cmd<<"'\nSubstringing...\n";
				std::string pStr = cmd.substr(0);
				std::cout<<"Substring: '"<<pStr<<"' \n";
			}
		}
        }
        std::size_t lExecPos = cmd.find(" ");
	std::size_t conPos = cmd.find(connector);//if a connector exists, find it pos
        exec = cmd.substr(0, lExecPos);
        arg = cmd.substr(lExecPos + 1, conPos-(lExecPos+2) );
        leftCMD = (instantiate(exec, arg)); 
        if (connectorFound == true) {
               //std::size_t startOfCon = cmd.find(connector);
               //std::size_t lExecPos = cmd.find(" ");
               //exec = cmd.substr(0, lExecPos);
               //arg = cmd.substr(lExecPos+1, startOfCon-(lExecPos+2));
               //leftCMD = (instantiate(exec, arg));
	        std::size_t startCon = cmd.find(connector);
                rightCom = cmd.substr(startCon + connectorSize);
	        rightCMD = parse(rightCom);
		connectedCMD = (instantiate(leftCMD, rightCMD, connector));
		return connectedCMD;		
	}
	return leftCMD;
}

Command* Parser::instantiate(std::string exec, std::string args){
        if (exec  == "test") {
		bool isTest = true;
		std::cout << "We have a test object\n";
                std::size_t endOfFlag = args.find(" ");
                std::string flag = args.substr(0, endOfFlag);
                std::string arg = args.substr(endOfFlag+1);
                std::cout<<"\nFlag*:'"<<flag<<"'\narg*:'"<<arg<<"'"<<std::endl;
                return new Executable(flag, arg, isTest);
        }
        else if(exec == "["){
            std::size_t endOfTest = args.find(']');
            if (endOfTest != std::string::npos){
		bool isTest = true;
                std::size_t endOfFlag = args.find(" ");
                std::string flag = args.substr(0, endOfFlag);
                std::string arg = args.substr(endOfFlag+1, endOfTest-(endOfFlag+2));
		std::cout<<"\nFlag:'"<<flag<< "'\narg:'"<<arg<<"'"<<std::endl;
                return new Executable(flag, arg, isTest);
            }
        }
        

        else{
        	return new Executable(exec, args);
        }
}
		
Command* Parser::instantiate(Command* left, Command* right, std::string con){
	if (con == "&"){
//		std::cout<<"Instantiating an && object.\n";
		return new And(left, right);
	}
	else if (con == "|"){
//		std::cout<<"Instantiating an || object.\n";
		return new Or(left, right);
	}
	else if (con == ";"){
//		std::cout<<"Instantiating an ; object.\n";
		return new Semicolon(left, right);
	}
}
