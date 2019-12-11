#include "../header/outputAppendRedirect.h"

OutputAppendRedirect(Command* com, std::string fileName)
{
    this.com = com;
    this.fileName = fileName;
}
virtual void execute()
{
    //check if file exists
    //if exists append output to file
    //else create and store output
    
    //i may have to check if file is open succesfully first
    int fdout = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
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
#endif //__OUTPUT_APPEND_REDIRECT__
~                                                                                 
~                                                                                 
~                                                                                 
~                                                 
