#ifndef __OUTPUT_APPEND_REDIRECT_H__
#define __OUTPUT_APPEND_REDIRECT_H__

#include "ioRedirect.h"

//Redirect (and append) output to a file
class OutputAppendRedirect : public IoRedirect
{
    public:
        OutputAppendRedirect(Command*, std::string);
        virtual void execute();
    protected:
        Command* com;
}
#endif //__OUTPUT_APPEND_REDIRECT__
~                                                                                 
~                                                                                 
~                                                                                 
~                                                 
