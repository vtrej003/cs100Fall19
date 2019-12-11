#ifndef __OUTPUT_REDIRECT_H__
#define __OUTPUT_REDIRECT_H__

#include "ioRedirect.h"

class OutputRedirect : public IoRedirect
{
    public:
        OutputRedirect(Command*, std::string);
        virtual void execute();
    protected:
        Command* com;
}
#endif //__OUTPUT__REDIRECT_H__
~                                                                                 
~                                                                                 
~                                                                                 
~                                                 
