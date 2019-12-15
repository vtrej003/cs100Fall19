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

