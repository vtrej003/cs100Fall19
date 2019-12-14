#include "../header/parser.h"

Command* Parser::parse(std::string strToParse){
	std::string cmd = strToParse;
	//std::vector<std::string> listOfConnectors({ "&&", "||", ";" });
	/*redirect strings*/
	std::string invalidChar = "& | ; < > ( )";
	std::string redirectList = "< > >>";
	
	//step one: seperate from commands from connector
	std::string rightCom;
        std::string connector = "NULL";// 1.commands and connector
	std::string exec;//2.exe
	std::string arg = "NULL";//3 args
	std::string leftStrCMD;
        std::string redirectCon;
	std::string redirectStr;
	int connectorSize = 0;
	int redirectPos = 0;
	bool connectorFound = false;	
        bool parenFound = false;	
	bool redirectorFound = false;
	Command* leftCMD;
        Command* rightCMD;
        Command* connectedCMD;
	Command* redirectCMD;
	//Command* setPToken;  //Used to set pToken.	
	std::cout<<"We are now parsing: '" << cmd<<"' \n";
	for (int i = 0; i < cmd.size(); i++) 
	{
            if (((cmd.at(i) == '&') && (cmd.at(i + 1) == '&')) || ((cmd.at(i) == '|') && (cmd.at(i + 1) == '|')) || (cmd.at(i) == ';' ))
	    {
                connector = cmd.at(i);
                if(connector == "&")
	        {
		    connector = "&&";
		    connectorSize = 3;
	        }
	        else if(connector == "|")
	        {
	            connector = "||";
	            connectorSize = 3;
	        }
                else 
	        {
	            connectorSize = 2;
	        }
	        connectorFound = true;
                break;
            }
            else if(cmd.at(i) == '|' && cmd.at(i-1) != '|')
	    {
	        connector = "|";
	        connectorSize = 2;
	        connectorFound = true;
	        break;
	    }
/*----------------Redirect Syntax----------------------------------------*/
            else if(cmd.at(i) == '<' || cmd.at(i) == '>')
	    {
		
		redirectorFound = true;
                std::cout << "redirect parser check\n";
		std::cout << "this is cmd now: " << cmd << std::endl;
		int appendedI = 0; 
		if (cmd.at(i) == '<'){
			redirectCon = "<";
		}           
		else if(cmd.at(i) == '>'){
         	    redirectCon = ">";
		    if (cmd.at(i+1) == '>'){
			redirectCon = ">>";
			appendedI++;
		    }
                }

		redirectPos = i + appendedI;
		break;	
	    }
/*------------------------------------------------------------------------------*/
	    else if(cmd.at(i) == '(')
	    {
			//std::cout<<"Erasing left parenthesis...\n";
		//	std::string fileNamed.erase(cmd.begin() + i);
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
	if (parenFound == false && redirectorFound == false){
        	
		std::size_t conPos = cmd.find(connector);//if a connector exists, find its pos
		if (redirectorFound == true){
			redirectStr = cmd.substr(redirectPos+1);
			if (cmd.at(redirectPos+1) == ' '){
				redirectStr = cmd.substr(redirectPos+2);
			}
			std::cout<<"This is everything right after '"<<redirectCon<<"': '"<< redirectStr<<"'\n";			
			std::size_t endOfFilenamePos = redirectStr.find(' ');
			/*if (endOfFilenamePos == std::string::npos){
				redirectStr+=' ';
				std::size_t endOfFilenamePos = redirectStr.find(' ');
				redirectStr = redirectStr.substr(0, endOfFilenamePos)
			}*/
			redirectStr = redirectStr.substr(0, endOfFilenamePos);
			std::cout<<"This is the file: '"<<redirectStr<<"'\n";
		}
		leftStrCMD = cmd.substr(0, conPos);
		std::size_t lExecPos = leftStrCMD.find(' ');
		std::size_t lArgPos = leftStrCMD.find_last_of(' ');
		if (leftStrCMD.back() != ' '){
			leftStrCMD += ' ';
			lArgPos = leftStrCMD.find_last_of(' ');
		}
		std::cout << "This is the leftStrCMD '" <<leftStrCMD <<"'\n";		
		arg = leftStrCMD.substr(lExecPos + 1, lArgPos);
		exec = cmd.substr(0, lExecPos);
		std::cout<<"Connector Found at pos: " << conPos<<std::endl;
		std::cout<<"Exec Found at pos: " << lExecPos<<std::endl;
		std::cout<<"Command: '" << cmd << "'\n"; 
		if ( arg == ""){
			std::cout<<"Loading NULL as arg\n";
			arg = "NULL";
		}
		std::cout<<"This is exec: '" << exec<<"'\n";
		std::cout<<"This is arg: '" << arg<<"'\n";
		leftCMD = (instantiate(exec, arg));
	}
	if (redirectorFound == true){
                        redirectStr = cmd.substr(redirectPos+1);
                        if (cmd.at(redirectPos+1) == ' '){
                                redirectStr = cmd.substr(redirectPos+2);
                        }
                        std::cout<<"This is everything right after '"<<redirectCon<<"': '"<< redirectStr<<"'\n";
                        std::size_t endOfFilenamePos = redirectStr.find(' ');
                        /*if (endOfFilenamePos == std::string::npos){
                                redirectStr+=' ';
                                std::size_t endOfFilenamePos = redirectStr.find(' ');
                                redirectStr = redirectStr.substr(0, endOfFilenamePos)
                        }*/
                        redirectStr = redirectStr.substr(0, endOfFilenamePos);
                        std::cout<<"This is the file: '"<<redirectStr<<"'\n";
	}

	if (redirectorFound == true){
                        redirectStr = cmd.substr(redirectPos+1);
                        if (cmd.at(redirectPos+1) == ' '){
                                redirectStr = cmd.substr(redirectPos+2);
                        }
                        std::cout<<"This is everything right after '"<<redirectCon<<"': '"<< redirectStr<<"'\n";
                        std::size_t endOfFilenamePos = redirectStr.find(' ');
        }	
	
        if (connectorFound == true){
		std::size_t startCon = cmd.find(connector);
		rightCom = cmd.substr(startCon + connectorSize);
		rightCMD = parse(rightCom);
		
		connectedCMD = (instantiate(leftCMD, rightCMD, connector, parenFound));
		return connectedCMD;		
	}


	if(redirectStr.empty()){
		return leftCMD;
	}
	else{
		std::cout << "returning a decorated executable\n"; 
                redirectCMD = (instantiate(leftCMD, redirectStr));
		redirectStr.clear();
  	  	return redirectCMD;
	}
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

Command* Parser::instantiate(Command* left, std::string redirectCom)
{
	std::cout << "this is the instantiate of redirectors\n";
	std::cout<< "Instantiating redirectCom: '" <<redirectCom<<"'\n";
    if ( redirectCom[0] == '>' && redirectCom[1] == '>')
    {	
        redirectCom.erase(0,2);	
	if (redirectCom[0] == ' '){
                std::cout<<"Erasing whitespace\n";
                redirectCom.erase(redirectCom.begin());
        }
        return new OutputAppendRedirect(left, redirectCom);
    }

    else if ( redirectCom[0] == '<')
    {
	redirectCom.erase(0,1);
	if (redirectCom[0] == ' '){
		std::cout<<"Erasing whitespace\n";
		redirectCom.erase(redirectCom.begin());
	}
	
	std::cout << "*This is redirectCom after erase :'"<<redirectCom<<"'\n";
        return new InputRedirect(left, redirectCom);
    }

    else if (redirectCom[0] == '>')
    {
	redirectCom.erase(0,1);
	std::cout << "This is redirectCom after erase :'"<<redirectCom<<"'\n";
	if (redirectCom[0] == ' '){
		std::cout<<"Erasing whitespace\n";
                redirectCom.erase(redirectCom.begin());
	}	
        return new OutputRedirect(left, redirectCom);
    }
    else
        std::cout << "error instantiating redirect class\n";
      
}

std::string Parser::redirector(int pos, std::string cmd)
{
/*    
    std::string redirectCom;

    std::cout << "this is pos:" << pos << "\nand this is character at pos:" << cmd.at(pos) << std::endl;
    std::cout << " this is cmd inside redirector at start:" << *cmd << std::endl;
    
    redirectCom = cmd->substr(pos);
    cmd->erase(pos);
    
    
    std::cout << "final check before exiting redirect syntax check\n:"; 
    std::cout << *cmd << std::endl << redirectCom << std::endl;
    return redirectCom;*/
}
