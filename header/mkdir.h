#ifndef __MKDIR_H__
#define __MKDIR_H__

class mkdir : command
{
    public:
        virtual void execute();
        virtual std::string print();

    private:
        std::string fileName;
}
#endif __MKDIR_H__
