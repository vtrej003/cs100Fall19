#include "../header/ioRedirect.h"

IoRedirect::IoRedirect(Command* com, char*fileName)
{
    this->com = com;
    this->fileName = fileName;
}
