# CS100 RShell
> Spring 2019 - Daniel Kwong (862032167) and Jason Chang (862046747)

## Introduction
Our program will be a basic command shell that will be created using C++. The shell will be able to take in and execute standard commands. It will also have 3 connectors: "||", "&&", and ";". They will allow the user to run multiple commands at once. The composite pattern will be used to handle all commands and operators. We will have a base class that connects all of the classes together as an interface. The subclasses will include a regular input classe that will take in and execute the commands and operator classes that will build a tree using the operators and command inputs.

## Diagram

## Classes

`main.cpp`
Provides the interface in which the user can use the console/shell. Takes user input.

`base.cpp`
Base class, holds virtual functions.

* execute() - Detect type of command based on string input. Runs the command.

* print() - Prints a new line, and $

`input.cpp`
Process command function, takes in parameter string

* execute()

* print()

`and.cpp`
Also known as “&&” next command executed only if the first command succeeds.

* execute()

* print()

`or.cpp`
Also known as “||” next command executed only if the first command fails.

* execute()

* print()

`semicolon.cpp`
Also known as “;” next command is always executed.

* execute()

* print()

Command Line
Input
Read input
If input contains * -> symbol evaluate
If contains text -> string evaluate
Put everything in tree evaluate recursively
Add subtrafct dnfianofa
Git add .
|| && ; -> stack/queue

Commands class
-different command classes



#


## Prototypes/Research

## Development and Testing Roadmap
