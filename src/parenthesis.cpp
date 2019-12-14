#include "../header/parenthesis.h"

parenthesis(std::string subCommand)
{
    com = subParser(subCommand);
}    

virtual void execute()
{
    com->execute();
}
