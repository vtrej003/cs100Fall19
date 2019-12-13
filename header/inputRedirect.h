#ifndef __INPUT_REDIRECT_H__
#define __INPUT_REDIRECT_H__

#include "ioRedirect.h"

class InputRedirect : public IoRedirect
{
    public:
        InputRedirect(Command*, std::string); 
        virtual void execute();
    //protected:
        //Command* com;
	//char* fileName;
};
#endif //__INPUT_REDIRECT_H__

