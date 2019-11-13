#ifndef __LS_H__
#define __LS_H__

class Ls : command
{
    public:
        ls();
        virtual void execute();
        virtual std::string print();
}
#endif //__LS_H__
