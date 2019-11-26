#ifndef __INSTANTIATOR_H__
#define __INSTANTIATOR_H__
#include <string>
#include <vector>
#include <iostream>
#include "command.h"
#include "executable.h"
#include "test.h"
#include "and.h"
#include "or.h"
#include "semicolon.h"

class Instantiator{
    public:
	Instantiator(std::vector<std::string> cmdList);
};

#endif //__INSTANTIATOR_H__
