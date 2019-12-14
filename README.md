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
Furthermore, this program had functionality for input and output redirection using characters |, <, <<, > to represent piping, input redirection, output appended redirection, and output redirection respectively.

# Diagram
![Shell Diagram Image Link](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment/blob/master/images/UML.PNG)
# Classes
**Command** - Our base class is an abstract class that implements virual function execute() which is inherited and implemented
by all of its subclasses (executables and connectors). It also contains tokens that keep track of the validity of whether or not
the next executable that has been parsed should execute. Contains a token that is used to symbolize whether a parenthesis has 
been found or not. Also containes a string which is assigned the string name of whatever connector is currently being evaluated. 
Contains setters and getters for these variables.  

**Parser** - Parser in essentially the engine for our program. It parses user input and depending on what is read, it creates
objects accordingly. If an executable is seen on its own, it creates an executable object. If a connecctor is read, it creates
two executable objects and uses them to instansiate connector objects. If a test keyword is found, then it instantiates a test
object. This also takes care of the instantiation for our redirection objects. 

**Executable** - Acts on the parsed information that is passed into it. Assigns arguments and executables appropriately 
depending on what parameters it has been passed and also contains the functionality to execute on Command objects using execvp 
and other built functionality.. 

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
- The **test** keyword will check to see if whatever comes after it exists as a file/directory. An optional flag can be placed 
in the form of **-e**, **-d**, **-f** to check if the file exists, exists and is a directory, or exist and is a normal file 
repsectively.
- The bracket **[]** symbols can be used as an alternative means to using the test functionality, with the brackets enclosing 
the arguments in place of the keyword **test** preceding the arguments. 
- The **()** will give precedense to whatever commands are placed inside of it, meaning that it will return either true or false 
depending on the logic that is written within it. e.g. **(echo a || a) && echo c** will print **"ac"** while **echo a || (echo b 
&& echo c)** will only print **"a"**.
- The **|** connector will redirect output of one executable to another. e.g. **ls | cat** will print out the contents of ls using cat functionality. **ls | wc** will print perform wc functionality with the output of ls passed in as its argument.
- The **<** redirector will redirect input from the a file on its right to an executable on the left. 
- The **>** redirector will redirect output from the a file on its right to an executable on the left.
- The **<<** redirector is interpretted as an instruction to read input until it finds a line containing the specified delimiter. All the input lines up to the line containing the delimiter are then fed into the standard input of the command.
# Devlopment and Testing Roadmap
- [Create classes for the connectors.](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment/issues/2)
- [Create integration tests for connector classes.](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment
/issues/6)
- [Create Unit Test.](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment/issues/4)
- [Create classes for the executables.](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment/issues/3)
- [Create integration tests for the executable classes.](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment
/issues/5)

