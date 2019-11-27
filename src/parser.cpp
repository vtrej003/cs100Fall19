#include "../header/parser.h"
Command* Parser::parse(std::string strToParse){
	std::string cmd = strToParse;
	std::vector<std::string> listOfConnectors({ "&&", "||", ";" });
	//step one: seperate from commands from connector
	std::string rightCom;
        std::string connector = "NULL";// 1.commands and connector
	std::string exec;//2.exe
	std::string arg;//3 args
								  //substring left command
	bool connectorFound = false;	
	
	Command* leftCMD;
        Command* rightCMD;
        Command* connectedCMD;
	
	for (int i = 0; i < cmd.size(); i++) {
		if (((cmd.at(i) == '&') && (cmd.at(i + 1) == '&')) || ((cmd.at(i) == '|') && (cmd.at(i + 1) == '|')) || (cmd.at(i) == ';' )){
			connector = cmd.at(i);
			std::size_t endOfCon = cmd.find_last_of(connector);
                        rightCom = cmd.substr(endOfCon + 2);
                        rightCMD = parse(rightCom);
			//std::size_t startOfCon = cmd.find(connector);
			//std::size_t lExecPos = cmd.find(" ");
			//exec = cmd.substr(0, lExecPos);
			//arg = cmd.substr(lExecPos+1, startOfCon-(lExecPos+1));
			//std::cout<<"This is Exec and arg:"<<exec<<" "<<arg<<std::endl;
			//leftCMD = (instantiate(exec, arg));*/
			connectorFound = true;
			rightCMD = parse(rightCom);
			break;
		}
	/*	if (connectorFound == false){	
			std::size_t lExecPos = cmd.find(" ");
                        exec = cmd.substr(0, lExecPos);
                        arg = cmd.substr(lExecPos + 1);
			leftCMD = (instantiate(exec, arg));
			std::cout<<"This is what is being returned from parse\nExec:" <<exec<<"\nArg:"<<arg<<std::endl; 
			return leftCMD;
		}*/
	}
	if (connectorFound == false){
         	std::size_t lExecPos = cmd.find(" ");
                exec = cmd.substr(0, lExecPos);
                arg = cmd.substr(lExecPos + 1);
                leftCMD = (instantiate(exec, arg));
                std::cout<<"This is what is being returned from parse\nExec:" <<exec<<"\nArg:"<<arg<<std::endl;
                        return leftCMD;
                }
        else if (connectorFound == true){
	 	//std::size_t endOfCon = cmd.find_last_of(connector);
                //rightCom = cmd.substr(endOfCon + 2);
                //rightCMD = parse(rightCom);
                std::size_t startOfCon = cmd.find(connector);
                std::size_t lExecPos = cmd.find(" ");
                exec = cmd.substr(0, lExecPos);
                arg = cmd.substr(lExecPos+1, startOfCon-(lExecPos+1));
                std::cout<<"This is Exec and arg:"<<exec<<" "<<arg<<std::endl;
                leftCMD = (instantiate(exec, arg));
                connectorFound = true;
		std::cout<<"Connector has been found.\n";
		connectedCMD = (instantiate(leftCMD, rightCMD, connector));
		//rightCMD = parse(rightCom);
		return connectedCMD;		
	}
	else{std::cout<<"\n\nERROR IN PARSE\n\n.";}
}

Command* Parser::instantiate(std::string exec, std::string args){
        if (exec  == "test") {
                std::size_t endOfFlag = args.find(" ");
                std::string flag = args.substr(0, endOfFlag);
                std::string arg = args.substr(endOfFlag);
                std::cout<<"Flag and arg:"<<flag<<arg<<std::endl;
                return new Test(flag, arg);
        }
        else if(exec == "["){
            std::size_t endOfTest = args.find(']');
            if (endOfTest != std::string::npos){
                std::size_t endOfFlag = args.find(" ");
                std::string flag = args.substr(1, endOfFlag);
                std::string arg = args.substr(endOfFlag, endOfTest);
                std::cout<<"Flag:"<<flag<<arg<<std::endl;
                return new Test(flag, arg);
            }
        }
        

        else{
        	return new Executable(exec, args);
        }
}
		
Command* Parser::instantiate(Command* left, Command* right, std::string con){
	if (con == "&"){
		return new And(left, right);
	}
	else if (con == "|"){
		return new Or(left, right);
	}
	else if (con == ";"){
		return new Semicolon(left, right);
	}
}
