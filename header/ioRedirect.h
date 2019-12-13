#ifndef __IO_REDIRECT_H__
#define __IO_REDIRECT_H__
#include "command.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class IoRedirect : public Command
{
    public: 
        IoRedirect();
	IoRedirect(Command* com, char* fileName);
        virtual void execute() = 0;
    protected:
    Command* com;
    char* fileName;
};
#endif //__IO_REDIRECT_H__
