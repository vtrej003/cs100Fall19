#include "../header/semicolon.h"

Semicolon::Semicolon(Command* lCom, Command* rCom){
    leftCommand = lCom;
    rightCommand = rCom;
}

virtual void And::execute(){

}

virtual std::string And::print(){

}
