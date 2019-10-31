# CS 100 Programming Project

# Project Information
## CS100 RShell
Fall 2019  
Andres Estrada - 862136048  
Vincent Trejo - 862087821  

# Introduction
The program is a command shell that is capable of printing a command prompt, read in lines of commands and connectors 
from standard input and can execute commands such as fork, execvp, and waitpid. The design pattern we will be using for 
this program's representation of commands and operators is the composite pattern.

# Diagram

# Classes
**Base** - Our Base class is an abstract class that implements an interface evaluate(string)for our subclasses.  
**Parser** - Inherits from Base and parses string of inputs and searches for command keywords and connectors. Once a 
keyword/connector is found it will keep track of its element type and count it accordingly.  
**Executable** - Acts as the parent class for all of our executables. Passes on the evaluate() function to its 
subclasses, which are the leafs of this composition design.  
**Connector** - Acts as the parent class for all of our executables. Passes on the evaluate() function to its subclasses, 
which are the leafs of this composition design.  

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
- [Create integration tests for connector classes.](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment/issues/6)
- [Create Unit Test.](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment/issues/4)
- [Create classes for the executables.](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment/issues/3)
- [Create integration tests for the executable classes.](https://github.com/cs100/assignment-andres_vincent_cs_100_assignment/issues/5)

### Submission
"Commit any images you create and code prototypes to the proper directories and commit the updates to your README.md to 
your fork of the assignment repo from GitHub Classrooms.

You will also need to add an annotated *hw1* tag to the commit that you want to be graded. Annotated tags are described 
in lab 2 and in the git documentation. git push will not automatically push tags to your repository. Use git push origin 
hw1 to update your repository to include the hw1 tag. If you need to update your tag, you can remove the old tag using 
git push --delete origin hw1 and push an updated one to your repo.

Your project must also contain a names.txt file in the root directory which contains the name, SID, and email of each of 
the partners in your group. It should have the following format.

Brian Crites, 860XXXXXX, bcrit001@ucr.edu
Andrew Lvovsky, 860XXXXXX, alvov001@ucr.edu"

