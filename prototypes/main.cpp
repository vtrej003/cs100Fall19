#include <iostream>
#include <string>
#include "../header/command.h"
#include "../header/executable.h"
#include "../header/and.h"
#include "../header/or.h"
int main()
{
    Command* lsCommand = new Executable("echo");
    Command* rCom = new Executable("ls", "sdfs");
    Command* theOr = new Or(lsCommand, rCom);
    theOr->execute();

    return 0;
}

