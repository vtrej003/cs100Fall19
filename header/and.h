#ifndef __AND_H__
#define __AND_H__

#include "command.h"

class And : public Command {
public:
	And(Command*, Command*);
	virtual void execute();
	//virtual void setExToken();
protected:
	Command* leftCommand;
	Command* rightCommand;

	std::string name = "&&";
};
#endif //__AND_H__

