#!/bin/bash
#testing each connector And, Or, Semicolon

#and connector
#set +x

../rshell "echo a && echo b"
#echo testing if files exists
#if(../rshell); then
#    echo open successful

#echo TESTING AND CASE\n

#Arguement="echo thisIsTheLeftsideOfAnd && echo rightSideOFAnd"
#OUTPUT=[../rshell "$ARGUEMENT"]
 
#if( "$OUTPUT" = "$ARGUEMENT" );
#then
#   echo the input is equal to the output
#else
#   echo this is output "$OUTPUT" and now "$ARGUEMENT"
#   echo the input is not equal to the output
#fi


#echo testing composite or
# ../rshell "echo thisistheOr || echo IamRightSide"

#echo testing composite semicolon
# ../rshell "echo thisISSemi ; echo Colen"

#else
#    echo failed to open
#fi

