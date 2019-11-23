#include <iostream>
#include <string>
#include "../header/command.h"
#include "../header/executable.h"
#include "../header/and.h"
#include "../header/or.h"
int main()
{
    Command* lsCommand = new Executable("dsf");
    Command* rCom = new Executable("ls", "-l");
    Command* theOr = new Or(lsCommand, rCom);
    theOr->execute();

    return 0;
}

