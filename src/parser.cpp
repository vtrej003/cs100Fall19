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
	for (int i = 0; i < cmd.size(); i++) {
                if (((cmd.at(i) == '&') && (cmd.at(i + 1) == '&')) || ((cmd.at(i) == '|') && (cmd.at(i + 1) == '|')) || (cmd.at(i) == ';' )){
                        connector = cmd.at(i);
                        if(connector == "&" || connector == "|"){connectorSize = 3;}
                        else {connectorSize = 2;}
			connectorFound = true;
                        break;
                }
        }


                std::size_t lExecPos = cmd.find(" ");
		std::size_t secondSpace = cmd.find("");
                exec = cmd.substr(0, lExecPos);
                arg = cmd.substr(lExecPos + 1 );
                std::cout<<"This is Exec and arg*:'" <<exec<<"' '"<<arg<<"'"<<std::endl;
                leftCMD = (instantiate(exec, arg));
                //return leftCMD;
          if (connectorFound == true){
                std::size_t startOfCon = cmd.find(connector);
                lExecPos = cmd.find(" ");
                exec = cmd.substr(0, lExecPos);
                arg = cmd.substr(lExecPos+1, startOfCon-(lExecPos+2));
                std::cout<<"This is Exec and arg:'"<<exec<<"' '"<<arg<<"'"<<std::endl;
                leftCMD = (instantiate(exec, arg));
                //connectorFound = true;	
		std::size_t startCon = cmd.find(connector);
                rightCom = cmd.substr(startCon + connectorSize);
		rightCMD = parse(rightCom);
		connectedCMD = (instantiate(leftCMD, rightCMD, connector));
		//rightCMD = parse(rightCom);
		return connectedCMD;		
	}
	std::cout<<"Reached leaf.\n";
	return leftCMD;
	//else{std::cout<<"\n\nERROR IN PARSE\n\n.";}
}

Command* Parser::instantiate(std::string exec, std::string args){
        if (exec  == "test") {
		std::cout << "We have a test object\n";
                std::size_t endOfFlag = args.find(" ");
                std::string flag = args.substr(0, endOfFlag);
                std::string arg = args.substr(endOfFlag+1);
                std::cout<<"\nFlag*:'"<<flag<<"'\narg*:'"<<arg<<"'"<<std::endl;
                return new Test(flag, arg);
        }
        else if(exec == "["){
            std::size_t endOfTest = args.find(']');
            if (endOfTest != std::string::npos){
                std::size_t endOfFlag = args.find(" ");
                std::string flag = args.substr(0, endOfFlag);
                std::string arg = args.substr(endOfFlag+1, endOfTest-(endOfFlag+2));
		std::cout<<"\nFlag:'"<<flag<< "'\narg:'"<<arg<<"'"<<std::endl;
                return new Test(flag, arg);
            }
        }
        

        else{
        	return new Executable(exec, args);
        }
}
		
Command* Parser::instantiate(Command* left, Command* right, std::string con){
	if (con == "&"){
		std::cout<<"Instantiating an && object.\n";
		return new And(left, right);
	}
	else if (con == "|"){
		std::cout<<"Instantiating an || object.\n";
		return new Or(left, right);
	}
	else if (con == ";"){
		std::cout<<"Instantiating an ; object.\n";
		return new Semicolon(left, right);
	}
}
