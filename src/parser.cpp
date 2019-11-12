#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "../header/parser.h"
std::string parser(std::string qToParse) {
        std::string andDelimiter = "&&"; //Delimiters to look out for
        std::string orDelimiter = "||";
        std::string seperatorDelimiter = ";";
        std::string args = "";
        bool lastArgFlag = false;       //Will be set true when the iterator reaches the end of the string. Makes hanging strings that are not appended by connector into an arg.
        size_t pos = 0;

        for (int i = 0; i < qToParse.size(); i++) {             //for loop to iterate through the string until a connector is found
                if (qToParse.at(i) == ';') {            //checks to see if a connector is in the part of the string.
                        pos = qToParse.find(seperatorDelimiter);                //pos is equal to the string length it takes to find the delimiter.
                        std::string token = qToParse.substr(0, pos);            // token is assigned the value of the string up to the delimiter.
                        args += token;                                                      // args is appended with token value.
                        qToParse.erase(0, pos + seperatorDelimiter.length());           //erases a portion of the string up to and including the delimiter.
                        i = 0;                  //This line in all the "if statements" is to keep the "for loop" from ending too soon.
                        if (i == qToParse.size()-1) { lastArgFlag = true; }                 //checks to see if the (end - 1) of the string has been reached.
                }
                else if (qToParse.at(i) == '&' && qToParse.at(i+1) == '&') {
                        pos = qToParse.find(andDelimiter);
                        std::string token = qToParse.substr(0, pos);
                        args += token;
                        qToParse.erase(0, pos + andDelimiter.length());
                        i = 0;
                        if (i == qToParse.size()-1) { lastArgFlag = true; }
                }
                else if (qToParse.at(i) == '|' && qToParse.at(i + 1) == '|') {
                        pos = qToParse.find(orDelimiter);
                        std::string token = qToParse.substr(0, pos);
                        args += token;
                        qToParse.erase(0, pos + orDelimiter.length());
                        i = 0;
                        if (i == qToParse.size()-1) { lastArgFlag = true; }
                }
                else {
                        if (i == qToParse.size()-1) { lastArgFlag = true; }
                }

           if (lastArgFlag == true) { args += qToParse; }
        }
        return args;                    //returns args
}

