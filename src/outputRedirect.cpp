#include "../header/outputRedirect.h"

OutputRedirect::OutputRedirect(Command* com, std::string fileName) : IoRedirect(com, (char*)fileName.c_str())
{
    
}
void OutputRedirect::execute()
{
    //checks if file exists
    //if file exists copy data over existing file
    //if not create and store stdout

    int fdout = open(fileName,O_WRONLY | O_CREAT | O_TRUNC, 0644);
    /*system calls (read(2), write(2),
 *        lseek(2), fcntl(2), etc.) to refer to the open file.*/
    if(fdout < 0)
    {
        exit(1);
    }
    else
    {
        dup2(fdout, STDOUT_FILENO);
        //might want to close();
        com->execute();
    }
    
}
