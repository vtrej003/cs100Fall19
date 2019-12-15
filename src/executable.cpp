#include "../header/executable.h"

Executable::Executable(std::string exec)
{
 //   std::cout<<"Making\n";
    execName = exec; 
    args[0] = (char*)exec.c_str();

}

Executable::Executable(std::string exec, std::string arg)
{
    std::cout<<"Arg inside executable is: "<<arg<<std::endl;
    if (arg == "NULL"){
	std::cout<<"Only exec loaded\n";
	execName = exec;
	cmd = const_cast<char*>(execName.c_str());
	args.push_back(const_cast<char*>(execName.c_str()));
	std::cout<<"SUP\n";
    }
    else{
	std::cout<<"Exec and arg loaded\n";
    	execName = exec;
    	argList = arg;
//	std::cout<<"Arg parsing: '" << argList<<"'\n";
	args.push_back(const_cast<char*>(execName.c_str()));
	//args.push_back(const_cast<char*>(execName.c_str()));
	args.push_back(const_cast<char*>(argList.c_str()));
	/*do{
		args.push_back(const_cast<char*>(execName.c_str()));
		std::string currentArg;
		bool whitespaceFound = true;
		std::size_t argEndPos = argList.find(' ');
		int argEnd = argEndPos;
		if (argEndPos == std::string::npos){
			std::cout << "No whitespace found\n";
			argEnd = argList.back();
			whitespaceFound = false;
                }
		currentArg = argList.substr(0, argEndPos);
		std::cout<<"Loading arg: '"<<currentArg<<"'\n";
		args.push_back(const_cast<char*>(currentArg.c_str()));
		argList.erase(0, argEnd+1);
		if (whitespaceFound == false){
			argList.erase(0, argEnd);
		}
		std::cout<<"Arg left to parse is: '"<<argList<<"'\n";		
	}while(argList.size()!=0);*/
	args.push_back(NULL);	
    }
	/*if (arg == "a-z A-Z"){
		std::cout << "We have a tr exec\n";
		std::string tr1 = "a-z";
		std::string tr2 = "A-Z";
		args[0] = const_cast<char*>(execName.c_str());
        	args[1] = const_cast<char*>(tr1.c_str());
		args[2] = const_cast<char*>(tr2.c_str());
	}
	else if (arg == "A-Z a-z"){
		std::cout << "*We have a tr exec\n";
                std::string tr1 = "a-z";
                std::string tr2 = "A-Z";
                args[0] = const_cast<char*>(execName.c_str());
                args[1] = const_cast<char*>(tr2.c_str());
                args[2] = const_cast<char*>(tr1.c_str());
        }*/
	//else{
    	//	cmd = const_cast<char*>(execName.c_str());
    	//	args[0] = const_cast<char*>(execName.c_str());
    	//	args[1] = const_cast<char*>(argList.c_str());
    	//}
    
}

Executable::Executable(std::string nFlag, std::string arg, bool isTest){
    argList = arg;
    flag = nFlag;
    cmd = "test";
    args[0] = "test";
    mIsTest = isTest;
    if (flag == "-e" || flag == "-d" || flag == "-f"){
        args[1] = const_cast<char*>(flag.c_str());
        args[2] = const_cast<char*>(argList.c_str());
    }
    else{
	flag = "-e";
        args[1] = const_cast<char*>(flag.c_str());
        args[2] = const_cast<char*>(argList.c_str());
    }
    std::cout<<"\n\nflag:'" << args[1] <<"'\narg:'"<<args[2]<<"'\n\n";
}
void Executable::execute()
{
   // std::cout<<"Exectuting && object:'"<<cmd<< "' '"<<args[0]<<"' '"<<args[1]<<"'\n";
    char** CMD = &args[0];
    std::string connector = Command::getConnector();
    std::cout<<"**Using connector: '" <<connector<<"'\n";
    std::cout<<"Executable token is set to " <<Command::mExToken<<std::endl;
    
    if (connector == "NULL"){
	std::cout<<"Exectuting reg. object:'"<<cmd<<"'\n";
	if (mIsTest == true){
		testExecute();
		mIsTest = false;
	}
	else{ 
	      	Command::mExToken = true;
		execvp(CMD[0], CMD);
		std::cout<<"Command does not exist\n";
		exit(1);
	}	
    }
    else if(connector == ";"){
	 if(mIsTest == true){testExecute(); mIsTest = false;}
         else{
              execvp(CMD[0], CMD);
         }	
    }
    if(Command::mExToken == true){
	std::cout<<"Execution token is set to true" <<"\n";
	if (connector == "&&"){
//	    std::cout<<"Exectuting && object:'"<<cmd<< "' '"<<args[0]<<"' '"<<args[1]<<"'\n";
	    if(mIsTest == true){
		testExecute(); 
		mIsTest = false;
	    }
	    else{    
		Command::mExToken = true;
                execvp(CMD[0], CMD);
		std::cout<<"ex Command does not exist\n";
		exit(1);
            }		
	}
	else {// else connector is "||" and we don't execute this arg. 2 symbolizes don't care
	std::cout<<"Exectuting || object:'"<<cmd<< "' '"<<args[0]<<"' '"<<args[1]<<"'\n";
   	    exit(3);
	}
    }
    else if ( Command::mExToken == false){
	if (connector == "&&"){ // the last executable failed and we don't want to execute
//	 std::cout<<"*Exectuting && object:'"<<cmd<< "' '"<<args[0]<<"' '"<<args[1]<<"'\n";
	    exit(1);
	}
	else { // connector is ||
//	std::cout<<"*Exectuting || object:'"<<cmd<< "' '"<<args[0]<<"' '"<<args[1]<<"'\n";
	    if(mIsTest == true){testExecute(); mIsTest = false;}
            else{
		Command::mExToken = true;
                execvp(CMD[0], CMD);
		std::cout<<"Command does not exist\n";
		//Command::mExToken = false;
		exit (1);		
            }
	}
    }
}
void Executable::testExecute(){
 //   std::cout<<"EXECUTING...\n";
   // std::cout<<"Inside test bit "<<"'"<<args[1]<<"' '"<<args[2]<<"'"<<std::endl;
    if((!access((char*)args[2], F_OK))){
                if (flag == "-e"){
                        std::cout<<"(True)\n";
                        exit(0);
                }
                else if (flag == "-d"){
                        struct stat path_stat;
                        stat(args[2],&path_stat);
                        if (S_ISDIR(path_stat.st_mode) == 1){
                                std::cout<<"(True)\n";
				exit(0);
                        }
                        else {
			    std::cout<<"(False)\n";
			    exit(1);
			}

                }
                else if (flag == "-f"){
                        struct stat path_stat;
                        stat(args[2],&path_stat);
                        if(S_ISREG(path_stat.st_mode) == 1){
                                std::cout<<"(True)\n";
                        	exit(0);
			}
                        else {
			    std::cout<<"(False)\n";
			    exit(1);	
			}
                }
                else {
		    std::cout<<"(True)\n";
		    exit(0);	
		}
        }
    else{
        std::cout<<"(False)\n";
        exit(1);
    }

}

