#include <iostream>
#include "../header/query.h"
#include "../header/parser.h"
#include "../header/execute.h"

int main(int argc, char **argv)
{
    do
    {
        query();
    	parse();
        execute();
    }
    return 0;
} 
