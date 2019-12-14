#include "../header/query.h"
Query::Query(){};
std::string Query::query()
{
        //bool syntax = false;
	std::string input;
	
        
        std::getline(std::cin, input);

        if(redirectSyntax(input))
	{
	     std::cout << "passes the syntax\n";
             return input;
	}
        else
        {
	    std::cout << "Incorrect user input\n";
            exit(1);
	}
       
}

bool Query::redirectSyntax(std::string cmd)
{
    std::string invalidChar = "& | ; < > ( )";
    std::size_t found;
    for(int i = 0; i < cmd.size(); i++)
    {
	    if(cmd.at(i) == '>')
            {
		std::cout << "redirect found\n";
                if (cmd.at(i+1) == '>')
		{
		  
		    if(validCheck(cmd.at(i+3)))
		    {
			continue;
		    }
		    else
		    {
		        return false;
		    }
		}
		else
		{
		    if(validCheck(cmd.at(i+2)))
		    {
			continue;
		    }
		    else
		    {
		        return false;
		    }
		}    

            }
	    else if( cmd.at(i) == '<')
	    {
		std::cout << "redirector found\n";
	        if(validCheck(cmd.at(i+2)))
		{
		    continue;
		}
		else
		{
		    return false;
	    	}
	    }
    return true;           
    }
}

bool Query::validCheck(char c)
{
	 std::string invalidChar = "& | ; < > ( )";
         std::size_t found;

	if(found = invalidChar.find(c) !=std::string::npos)
	{
            std::cout << "invalid syntax after redirect char\n";
            return false;
	}
        return true;;
}
//bool paraBalanceCheck(input)
//{
/*     iterates through the input sting
 *     increments and decrements the counter
 *     counter is to make sure we never have 1 too many closing brackets
 *     then it continues to call more functions at each paranthesis
 *     to check for the previous and next elements for syntax erros*/
/*
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
} */
