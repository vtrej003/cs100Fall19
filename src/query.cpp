#include <iostream>
#include <string>
std::string query(){
        bool syntax = false;
        std::string connectorList("|| && ;");
	std::string input;
	
        do
        {
            str.clear();
            std::getline(std::cin, input);
        
            syntax = paraBalanceCheck(input);
        }
        while(!syntax);
	return input;
       
}

bool paraBalanceCheck(input)
{
    int counter = 0;
    for(std::string::iterator it = input.begin() it! = str.end(); ++it)
    {
        if(it == "(")
        {
            counter++;
            if(paraSyntaxCheck(it) == true)
                continue;
            else
                return false;
        }
        else if(it == ")") 
        {         
            counter--;
            if(paraSyntaxCheck(it) == true)
                continue;
            else
                return false;
        }
        else
            continue;
        
        if(counter < 0)
        {
            std::cout << "syntax error" << std::endl;
            return false;
        }
    }
    
    if(counter == 0)
        return true;
    else
        return false;
}
bool paraCompare(std:string it))
{
    std::string connectorList("|| && ;");
    if(it.compare(connectorList) == 0)
        return true;
    else
        return false;
}
bool paraSyntaxCheck(&it)
{
    if(it == "("){
        if(it == it.begin())
            if(!paraCompare(++it))
                return true;
            else
                return false;
    }
    else{
        if((!paraCompare(--it)) && (++it != connector))
            return true;
    else
       return false;
    }
    //end of left para--------------------------------
    
    else{
        if(it == it.end()){
            if(--it =! connector)
                return true;
            else 
                return false;
        }
        else
            if(--it  =! connector) && (++it == connector)
                return true
            else
                return false;
    
    }
} 
