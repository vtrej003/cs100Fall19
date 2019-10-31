#ifndef __PARSE_HPP__
#define __PARSE_HPP__
#include <string>
#include <iostream>
class exec;
class con;

class Parse{
     private:
	std::string strToParse;
        int elementCount;
     public:
	Parse(std::string aString){
	elementCount = 0;     
	strToParse = aString;
}
	 int getNumOfWords (){
		std::string a = " ";
		 for (int i = 0; i<strToParse.size(); i++){
		     if (strToParse.at(i)==a.at(0)){
			     elementCount++;
			}
		}
		if (strToParse.at(strToParse.size()-1) != a.at(0)){
				elementCount++;
			}
		return elementCount;
	}
};




#endif //__PARSE_HPP__

int main(){
     Parse* theString = new Parse("hello echo bye");
     std::cout << "This is the number of words in your string: " << theString->getNumOfWords();
	return 0;
}
