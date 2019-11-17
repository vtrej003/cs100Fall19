#include "../header/semicolon.h"

Semicolon::Semicolon(Command* lCom, Command* rCom){
    leftCommand = lCom;
    rightCommand = rCom;
}

 void Semicolon::execute(){
	leftCommand->execute();
	rightCommand->execute();
}

 std::string Semicolon::print(){

}
