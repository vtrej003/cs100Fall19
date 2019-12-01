# CS 100 Programming Project

# Project Information
## CS100 RShell
Fall 2019  
Andres Estrada - 862136048  
Vincent Trejo - 862087821  

# Introduction
The program is a command shell that is capable of printing a command prompt, read in lines of commands and connectors 
from standard input and can execute commands such as fork, execvp, and waitpid. The design pattern we will be using for 
this program's representation of commands and operators is the composite pattern. This program also has functionality for test 
in keyword **test** form and bracket **[]** form. This program is also capable of executing commands wrapped in parenthesis 
**()** and can assign them precedence based on whether or not they are wrapped in parenthesis.

# Diagram
![Shell Diagram Image Link](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment/blob/master/images
/ShellDiagram.png)
# Classes
**Command** - Our base class is an abstract class that implements virual function execute() which is inherited and implemented
by all of its subclasses (executables and connectors). It also contains tokens that keep track of the validity of whether or not
the next executble that has been parsed should execute. Contains a token that is used to symbolize whether a parenthesis has 
been found or not. Also containes a string which is assigned the string name of whatever connector is currently being evaluated. 
Contains setters and getters for these variables.  
**Parser** - Parser in essentially the engine for our program. It parses user input and depending on what is read, it creates
objects accordingly. If an executable is seen on its own, it creates an executable object. If a connecctor is read, it creates
two executable objects and uses them to instansiate connector objects. If a test keyword is found, then it instantiates a test
object.  
**Executable** - Acts on the parsed information that is passed into it. Assigns arguments and executables appropriately and also
contains the functionality to execute on Command objects. 
**or, and, & semicolon** - Act as composites of executable objects. Determines the way that executable objects are executed.
Contains logic that handles the order in which executable objects are acted on.
**Query** - This is where the user input is handled.
**rshell** - Acts as our main. This is where all our functionality is initially called.
# Prototypes/Research
- The **&&** connector will act as an evaluater that executes both executables on either side of it. E.g. echo hello && 
echo world will print "hello world".  
- The **||** connector will pass over false executables and only execute on an executable that is true and return an 
error on any false executable, if any, that it passes over. E.g. hello || echo world will print "error world", echo hello 
|| world will print "hello".  
- The **;** connector will pass over any executable, whether it is false or true. E.g. echo hello; world will print 
"hello error".  
# Devlopment and Testing Roadmap
- [Create classes for the connectors.](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment/issues/2)
- [Create integration tests for connector classes.](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment
/issues/6)
- [Create Unit Test.](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment/issues/4)
- [Create classes for the executables.](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment/issues/3)
- [Create integration tests for the executable classes.](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment
/issues/5)


