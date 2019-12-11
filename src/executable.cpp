#include "../header/executable.h"

Executable::Executable(std::string exec)
{
    std::cout<<"Making\n";
    execName = exec; 
    args[0] = (char*)exec.c_str();

}

Executable::Executable(std::string exec, std::string arg)
{
    if (arg == "NULL"){
	std::cout<<"Only exec loaded\n";
	execName = exec;
	cmd = const_cast<char*>(execName.c_str());
	args[0] = const_cast<char*>(execName.c_str());
    }
    else{
	std::cout<<"Exec and arg loaded\n";
    	execName = exec;
    	argList = arg;
    	cmd = const_cast<char*>(execName.c_str());
    	args[0] = const_cast<char*>(execName.c_str());
    	args[1] = const_cast<char*>(argList.c_str());
    }
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
//    std::cout<<"\n\nflag:'" << args[1] <<"'\narg:'"<<args[2]<<"'\n\n";
}
void Executable::execute()
{
    std::string connector = Command::getConnector();
    //std::cout<<"Using connector: '" <<connector<<"'\n";
    //std::cout<<"Executable token is set to " <<mExToken<<std::endl;
    
    if (connector == "NULL"){
	if (mIsTest == true){testExecute(); mIsTest = false;}
	else{ 
	      	//mExToken = true;
		//Command::setToken(token);		
		execvp(cmd, args);
		std::cout<<"Command does not exist\n";
		exit(420);
		//std::cout<<"Setting execution token to false\n";
		//token = false;
	}	
    }
    else if(connector == ";"){
	 if(mIsTest == true){testExecute(); mIsTest = false;}
         else{
              execvp(cmd, args);
         }	
    }
    if(mExToken == true){
//	std::cout<<"Execution token is set to true" <<"\n";
	if (connector == "&&"){
	    std::cout<<"Exectuting && object:'"<<cmd<< "' '"<<args[0]<<"' '"<<args[1]<<"'\n";
	    if(mIsTest == true){testExecute(); mIsTest = false;}
	    else{    
                execvp(cmd, args);
		std::cout<<"Command does not exist\n";
		exit(3);
            }		
	}
	else {
	std::cout<<"Exectuting || object:'"<<cmd<< "' '"<<args[0]<<"' '"<<args[1]<<"'\n";
	//    std::cout<<"'exit(2)'\n"; 
   	    exit(2);
	}// else connector is "||" and we don't execute this arg. 2 symbolizes don't care
    }
    else if ( mExToken == false){
//	std::cout<<"Execution token is false.\n";
	if (connector == "&&"){
	 std::cout<<"*Exectuting && object:'"<<cmd<< "' '"<<args[0]<<"' '"<<args[1]<<"'\n";
	//    std::cout<<"'exit(3)'\n"; 
	    exit(3);
	} // the last executable failed and we don't want to execute
	else { // connector is ||
	std::cout<<"*Exectuting || object:'"<<cmd<< "' '"<<args[0]<<"' '"<<args[1]<<"'\n";
	    if(mIsTest == true){testExecute(); mIsTest = false;}
            else{
                execvp(cmd, args);
		std::cout<<"Command does not exist\n";
		exit (2);		
            }
	}
    }
 //   std::cout << "Ending executable's execute call and returning exit(420)\n";
   // std::cout<<"This is the last cmd, executable and arg to load: '"<<cmd<<"' '" << args[0]<<"' '" << args[1] << "'\n";
   
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

