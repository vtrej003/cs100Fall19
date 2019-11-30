#include "../header/instantiator.h"

Instantiator::Instantiator(std::vector<std::string> cmdList){
	Command* cmd;
	Command* leftCMD;
        Command* rightCMD;
	for (int i = 0; i<cmdList.size();i++){
		if (cmdList.at(i) == "test") {
            	        std::size_t endOfFlag = cmdList.at(i+1).find(" ");
                	std::string flag = cmdList.at(i+1).substr(0, endOfFlag);
                	std::string arg = cmdList.at(i+1).substr(endOfFlag);
			std::cout<<"Flag and arg:"<<flag<<arg<<std::endl;
                	 if (i == 0){
                         	leftCMD = new Test(flag, arg);
                         }
                         else if(i == 3){
                                rightCMD = new Test(flag, arg);
                         }
        	}
                else if(cmdList.at(i) == "["){
			std::cout<<"Inside [\n";
			std::size_t endOfTest = cmdList.at(i+1).find("]");
               		if (endOfTest != std::string::npos){
                        	std::size_t endOfFlag = cmdList.at(i+1).find(" ");
				std::string flag = cmdList.at(i+1).substr(1, endOfFlag);
				std::string arg = cmdList.at(i+1).substr(endOfFlag, endOfTest);
				std::cout<<"Arg and flag:"<<arg<<flag<<std::endl;
				if (i == 0){
                        		leftCMD = new Test(flag, arg);
	               		}
				else if(i == 3){
					rightCMD = new Test(flag, arg);
        			}
			}	
		}
	
		else if (i == 0){
			leftCMD = new Executable(cmdList.at(i), cmdList.at(i+1));
		}
		else if (i == 3){	
			rightCMD = new Executable(cmdList.at(i), cmdList.at(i+1));
		}
	}
        if (cmdList.at(2) == "&&"){ 
		cmd = new And(leftCMD, rightCMD);
        	std::cout<<"An And object has been instantiated.\n";
        }
        else if (cmdList.at(2) == "||"){
                cmd = new Or(leftCMD, rightCMD);
                std::cout<<"An Or object has been instantiated.\n";
        }
        else if (cmdList.at(2) == ";"){
                cmd = new Semicolon(leftCMD, rightCMD);
                std::cout<<"A Semicolon object has been instantiated.\n";
        }

	
		
	cmd->execute();
}
