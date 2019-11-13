#include "../header/or.h"

Or::Or(Command* lCom, Command* rCom) : Command(){
    leftCommand = lCom;
    rightCommand = rCom;
}

virtual void Or::execute(){
     
}

virtual std::string Or::print(){

}

