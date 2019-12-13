#include "../header/outputAppendRedirect.h"

OutputAppendRedirect::OutputAppendRedirect(Command* com, std::string fileName) : IoRedirect(com, (char*)fileName.c_str())
{
   
}
void OutputAppendRedirect::execute()
{
    //check if file exists
    //if exists append output to file
    //else create and store output
    
    //i may have to check if file is open succesfully first
    int fdout = open(fileName, O_WRONLY | O_CREAT | O_APPEND, 0644);
    /*system calls (read(2), write(2), lseek(2), fcntl(2), etc.) to refer to the open file.*/
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
