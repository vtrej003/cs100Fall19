#include "../header/parser.h"

#define LOCATION __FILE__ + 73

Command* Parser::parse(std::string strToParse){
	std::string cmd = strToParse;

	std::string connectorList = "& | ;";
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
	std::string tempCMD;
	int connectorSize = 0;
	int redirectPos = 0;
	std::size_t endOfFilenamePos;
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
				std::string pSubstr = cmd.substr(i+1, rightParPos-1);
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
	  if (parenFound == false)
	  {
        	
		std::size_t conPos = cmd.find(connector);//if a connector exists, find its pos

		leftStrCMD = cmd.substr(0, conPos-1);
		if (redirectorFound == true)
       		{
            	    std::cout << " entering redirector found\n";
		    leftCMD = instantiateRedirect(leftStrCMD);
		    
		    redirectorFound ==false; 
		    std::cout << "exiting redirectorFOund\n:";    
	        }
		else
		{
                    
		 a   std::cout << " did not enter redirector\n" << LOCATION << __LINE__ << std::endl;
		    std::size_t lExecPos = leftStrCMD.find(' ');
	  	    std::size_t lArgPos = leftStrCMD.find_last_of(' ');
		    if (leftStrCMD.back() != ' ')
                    {
			leftStrCMD += ' ';
			lArgPos = leftStrCMD.find_last_of(' ');

		    }   
		    std::cout << "This is the leftStrCMD '" <<leftStrCMD <<"'\n";		
		    arg = leftStrCMD.substr(lExecPos + 1, lArgPos);
		    exec = cmd.substr(0, lExecPos);
		    std::cout<<"Connector Found at pos: " << conPos<<std::endl;
		    std::cout<<"Exec Found at pos: " << lExecPos<<std::endl;
		    std::cout<<"Command: '" << cmd << "'\n"; 
		    if ( arg == "" || arg == exec)
		    {
			std::cout<<"Loading NULL as arg\n";
			arg = "NULL";
		    }   
		    std::cout<<"This is exec:" << exec<<":\n";
		    std::cout<<"This is arg:" << arg<<":\n";
		    leftCMD = (instantiate(exec, arg));
		}		
        	if (connectorFound == true)
		{
			std::cout << "entering connector found";
		    std::size_t startCon = cmd.find(connector);
		    rightCom = cmd.substr(startCon + connectorSize);
		    rightCMD = parse(rightCom);
		
		    connectedCMD = (instantiate(leftCMD, rightCMD, connector, parenFound));
		    return connectedCMD;		
	        }
		//single command
		return leftCMD;

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



Command* Parser::instantiateRedirect(std::string cmd)
{
   std::cout << "i am in side the initaiteRedirect\n";
    std::size_t inputRedirectPos, outputRedirectPos, execEndPos;
    std::string innerFile, outerFile, exec, arg;
    inputRedirectPos = cmd.rfind('<');
    outputRedirectPos = cmd.rfind('>');
    Command* com;
    Command* redirectCom;
    execEndPos = cmd.find(' ');
    std::cout << "This is cmd:" << cmd << std::endl;
    if(inputRedirectPos == std::string::npos)//no input redirector 
    {
	std::cout << "\nstepped into outputRedirect \n";
        exec = cmd.substr(0, execEndPos);
	arg = cmd.substr(execEndPos, outputRedirectPos-execEndPos);
        innerFile = cmd.substr(outputRedirectPos+2);
        
         if (arg == " " || arg == "")
       {   
           std::cout<<"Loading NULL as arg\n";
           arg = "NULL";
       }
	
	std::cout << "this is exec:" << exec << ":\nthis is arg:" << arg << ":\nthis is input:" << innerFile << ":" << std::endl;
	com = new Executable(exec,arg );
        return new OutputRedirect(com, innerFile);

    }
    else if(outputRedirectPos == std::string::npos)
    {
       //no output redirect
       std::cout << "\nStepped into Input redirect \n";
       exec = cmd.substr(0, execEndPos);
       arg = cmd.substr(execEndPos, inputRedirectPos-execEndPos);
       innerFile = cmd.substr(inputRedirectPos+2);
       
       
       if (arg == " " || arg == "")
       {
           std::cout<<"Loading NULL as arg\n";
           arg = "NULL";
       }
 	std::cout << "this is exec:" << exec << "this is arg:" << arg << "\nthis is input:" << innerFile << ":" << std::endl;
       com = new Executable(exec, arg);
       return new InputRedirect(com, innerFile);
    }
else if (inputRedirectPos < outputRedirectPos)
    {
        //both exits   (>(<(executable)))
        std::cout << "\nstepped into inputRedirect < outputRedirect \n";
	
        exec = cmd.substr(0, execEndPos);
        arg = cmd.substr(execEndPos, inputRedirectPos-execEndPos);  //substr 0 to input <
        innerFile = cmd.substr(inputRedirectPos+2, (cmd.size() - outputRedirectPos-1));// substr < to >
        outerFile = cmd.substr(outputRedirectPos+2, cmd.size()-1); //substr < to end of line
	
        if (arg == " " || arg == "")
       {
           std::cout<<"Loading NULL as arg\n";
           arg = "NULL";
       }

	      std::cout << "Exec:"<< exec <<":\narg:" << arg << ":\ninnerFile:"<< innerFile << ":\nouterFile:" << outerFile << ":\nInnerPOs:"<<inputRedirectPos <<"\nthis outerPos:"<< outputRedirectPos << std::endl;

        com = new Executable(exec, arg);
        redirectCom = new InputRedirect(com, innerFile);
        return new OutputRedirect(redirectCom, outerFile);

    }
    else if(inputRedirectPos > outputRedirectPos)
    {
         std::cout << "\nstepped into inputRedirect > outputRedirect \n";
         // both exits   (<(>(executable)))
        exec = cmd.substr(0, execEndPos);
        arg = cmd.substr(execEndPos, outputRedirectPos-execEndPos);
        
	innerFile = cmd.substr(outputRedirectPos+2, inputRedirectPos  - cmd.size());
        outerFile = cmd.substr( inputRedirectPos+2);
	
       if (arg == " " || arg == "")
       {
           std::cout<<"Loading NULL as arg\n";
           arg = "NULL";
       }

       std::cout << "Exec:"<< exec <<":\narg:" << arg << ":\ninnerFile:"<< innerFile << ":\nouterFile:" << outerFile << "InnerPOs:"<<inputRedirectPos <<"\nthis outerPos:"<< outputRedirectPos << std::endl;          
  
        com = new Executable(exec, arg);

        redirectCom = new OutputRedirect(com, innerFile);
        return new InputRedirect(redirectCom, outerFile);

    }


}
