#include "../header/parser.h"
Command* Parser::parse(std::string strToParse){
	std::string cmd = strToParse;
	std::vector<std::string> listOfConnectors({ "&&", "||", ";" });
	//step one: seperate from commands from connector
	std::string rightCom;
        std::string connector = "NULL";// 1.commands and connector
	std::string exec;//2.exe
	std::string arg;//3 args
	std::string leftStrCMD;
	int connectorSize = 0;
	bool connectorFound = false;	
        bool parenFound = false;	
	Command* leftCMD;
        Command* rightCMD;
        Command* connectedCMD;
	//Command* setPToken;  //Used to set pToken.	
	std::cout<<"We are now parsing: '" << cmd<<"' \n";
	for (int i = 0; i < cmd.size(); i++) {
                if (((cmd.at(i) == '&') && (cmd.at(i + 1) == '&')) || ((cmd.at(i) == '|') && (cmd.at(i + 1) == '|')) || (cmd.at(i) == ';' )){
                        connector = cmd.at(i);
                        if(connector == "&"){
				connector = "&&";
				connectorSize = 3;
			}
			else if(connector == "|"){
				connector = "||";
				connectorSize = 3;
			}
                        else {connectorSize = 2;}
				connectorFound = true;
                        break;
                }
		else if(cmd.at(i) == '|' && cmd.at(i-1) != '|'){
			connector = "|";
			connectorSize = 2;
			connectorFound = true;
			break;
		}
		else if(cmd.at(i) == '('){
			//std::cout<<"Erasing left parenthesis...\n";
			cmd.erase(cmd.begin() + i);
			//std::cout<<"This is what is left of cmd: '"<<cmd<<"'\n";
			std::size_t rightParPos = cmd.find(')');
			if (rightParPos != std::string::npos){
				parenFound = true;
				std::string pSubstr = cmd.substr(i, rightParPos);
				std::size_t lastOfSubstr = cmd.find(pSubstr.back());
			//	std::cout<<"PARENTHESIS HAS BEEN FOUND.\n";
			//	std::cout<<"SENDING '"<<pSubstr<< "' TO SUBPARSER...\n";
				leftCMD = parse(pSubstr);
			//	std::cout<<"Erasing right parenthesis...\n";
				cmd.erase(0, pSubstr.length());
				std::cout<<"This is what it left of command after cutting out parenthesis: '"<< cmd <<"'\n";
			//	std::cout<<"This is what is left of cmd: '"<<cmd<<"'\nSubstringing...\n";
				
			}
		}
        }
	std::cout<<"Connector found is '" << connector << "'\n";
	if (parenFound == false){
        	//std::size_t lExecPos = cmd.find(" ");
		std::size_t conPos = cmd.find(connector);//if a connector exists, find its pos
		leftStrCMD = cmd.substr(0, conPos);
        	//exec = cmd.substr(0, lExecPos);
		std::size_t lExecPos = leftStrCMD.find(" ");
		std::size_t lArgPos = cmd.find_last_of(" ");
		arg = leftStrCMD.substr(lExecPos + 1, lArgPos);
		exec = cmd.substr(0, lExecPos);
		std::cout<<"Connector Found at pos: " << conPos<<std::endl;
		std::cout<<"Exec Found at pos: " << lExecPos<<std::endl;
		std::cout<<"Command: '" << cmd << "'\n"; 
		if (arg == exec || arg == ""){
			std::cout<<"Loading NULL as arg\n";
			arg = "NULL";
		}
		std::cout<<"This is exec: '" << exec<<"'\n";
		std::cout<<"This is arg: '" << arg<<"'\n";
		leftCMD = (instantiate(exec, arg));
	}
        if (connectorFound == true){
		
		std::size_t startCon = cmd.find(connector);
                rightCom = cmd.substr(startCon + connectorSize);
	        rightCMD = parse(rightCom);
		connectedCMD = (instantiate(leftCMD, rightCMD, connector, parenFound));
		return connectedCMD;		
	}
	return leftCMD;
}

Command* Parser::instantiate(std::string exec, std::string args){
        if (exec  == "test") {
		bool isTest = true;
//		std::cout << "We have a test object\n";
                std::size_t endOfFlag = args.find(" ");
                std::string flag = args.substr(0, endOfFlag);
                std::string arg = args.substr(endOfFlag+1);
  //              std::cout<<"\nFlag*:'"<<flag<<"'\narg*:'"<<arg<<"'"<<std::endl;
                return new Executable(flag, arg, isTest);
        }
        else if(exec == "["){
            std::size_t endOfTest = args.find(']');
            if (endOfTest != std::string::npos){
		bool isTest = true;
                std::size_t endOfFlag = args.find(" ");
                std::string flag = args.substr(0, endOfFlag);
                std::string arg = args.substr(endOfFlag+1, endOfTest-(endOfFlag+2));
//		std::cout<<"\nFlag:'"<<flag<< "'\narg:'"<<arg<<"'"<<std::endl;
                return new Executable(flag, arg, isTest);
            }
        }
        
//	else if (args == "noArg"){
//		return new Executable(exec);
//	}
        else{
        	return new Executable(exec, args);
        }
}
		
Command* Parser::instantiate(Command* left, Command* right, std::string con, bool pFound){
	if (con == "&&"){
		std::cout<<"Instantiating an && object.\n";
		return new And(left, right, pFound);
	}
	else if (con == "||"){
		std::cout<<"Instantiating an || object.\n";
		return new Or(left, right, pFound);
	}
	else if (con == ";"){
		std::cout<<"Instantiating an ; object.\n";
		return new Semicolon(left, right);
	}
	else if (con == "|"){
		std::cout<<"Making a pipe object.\n";
		return new Pipe(left, right, pFound);
	}
}
