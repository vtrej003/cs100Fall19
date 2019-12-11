#ifndef __IO_REDIRECT_H__
#define __IO_REDIRECT_H__
#include "command.h"

class IoRedirect : Public Command
{
    public: 
        IoRedirect();
        virtual void execute();
}
#endif //__IO_REDIRECT_H__
