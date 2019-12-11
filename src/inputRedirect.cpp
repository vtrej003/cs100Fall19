#include "../header/inputRedirect.h"

InputRedirect(Command* com, std::string fileName)
{
    this.com = com;
    this.fileName = fileName;
}

virtual void execute()
{
    //check file is open
    //if fail exit
    //else
    //load file into stdin
    //call execute and pass the down to execution command
    int fdin = open(filename, O_RDONLY | O_CLOEXEC );
    /*system calls (read(2), write(2),
       lseek(2), fcntl(2), etc.) to refer to the open file.*/
    if(fdin < 0)
    {
        exit(1);
    }
    else
    {
        dup2(fdin, STDIN_FILENO);
        //might want to close();
        com->execute();
    }
}

