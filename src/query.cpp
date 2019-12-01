#include <iostream>
#include <string>
std::string query(){
        bool syntax = false;
	std::string input;
	
        do//loop until successful syntax input
        {
            std::getline(std::cin, input);
        
            syntax = paraBalanceCheck(input);//syntax check
        }
        while(!syntax);
	return input;
       
}

bool paraBalanceCheck(input)
{
/*     iterates through the input sting
 *     increments and decrements the counter
 *     counter is to make sure we never have 1 too many closing brackets
 *     then it continues to call more functions at each paranthesis
 *     to check for the previous and next elements for syntax erros*/

    int counter = 0;
    for(std::string::iterator it = input.begin() it! = str.end(); ++it)
    {
        if(it == "(")//left bracket comparison
        {
            counter++;
            if(paraSyntaxCheck(it) == true)//checks the previous and last element from the current paranthesis
                continue;
            else
                return false;
        }
        else if(it == ")")//if not a left para its a right
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
bool paraCompare(std:string it))//reusable compare function
{
    std::string connectorList("|| && ;");
    if(it.compare(connectorList) == 0)
        return true;
    else
        return false;
}
bool paraSyntaxCheck(&it)//this checks the previous and next elements
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
