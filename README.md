# CS 100 Programming Project

# Project Information
## CS100 RShell
Fall 2019
Andres Estrada - 862136048
Vincent Trejo - 862087821

# Introduction
The program is a command shell that is capable of printing a command prompt, read in lines of commands and connectors from standard input and can execute commands such as fork, execvp, and waitpid. The design pattern we will be using for this program's representation of commands and operators is the composite pattern.

# Diagram

# Classes
**Base** - Our Base class is an abstract class that implements an interface evaluate(string)for our subclasses.
**Parser** - Inherits from Base and parses string of inputs and searches for command keywords and connectors. Once a 
keyword/connector is found it will keep track of its element type and count it accordingly.
**Executable** - Acts as the parent class for all of our executables. Passes on the evaluate() function to its subclasses, which 
are the leafs of this composition design.
**Connector** - Acts as the parent class for all of our executables. Passes on the evaluate() function to its subclasses, which 
are the leafs of this composition design.

# Prototypes/Research
- The **&&** connector will act as an evaluater that executes both executables on either side of it. E.g. echo hello && echo world will print "hello world".
- The **||** connector will pass over false executables and only execute on an executable that is true and return an error on any false executable, if any, that it passes over. E.g. hello || echo world will print "error world", echo hello || world will print "hello".
- The **;** connector will pass over any executable, whether it is false or true. E.g. echo hello; world will print "hello error".
# Devlopment and Testing Roadmap
"Using the design you have set out above, create an ordered list of development tasks that need to be fulfilled before 
the system can be completed. Note that this list will be relatively ordered, as some tasks can be completed in parallel. 
This list should include not only primary development tasks, that is building of classes and function, but also should 
include creating both unit and integration tests. For each item in your list, you should create a GitHub issue and assign 
it to the person who is planning on completing it. Note that these assignments will not be final as some tasks will be 
more difficult than expected and others will be easier and additional tasks will need to be completed as your design 
evolves. This will simply serve as a plan of action for how the work will be split between partners. Finally, you should 
use markdown to create a link between the development and testing roadmap task and the associated issue.
When you create your design document, do not think only about the specifications in current assignment but also think of 
ways that this type of program is likely to be extended and make sure your design is well positioned for these changes. 
This is an important exercise in software construction, as successful projects usually have new functions added to them 
and old functions updated and modified."

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

