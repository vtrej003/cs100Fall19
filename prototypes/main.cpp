#include <iostream>
#include <string>
#include "../header/command.h"
#include "../header/executable.h"

int main()
{
    Command* lsCommand = new Executable("ls");
    lsCommand->execute();

    return 0;
}

