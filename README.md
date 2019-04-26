# CS100 RShell
> Spring 2019 - Daniel Kwong (862032167) and Jason Chang (862046747)

## Introduction
Our program will be a basic command shell that will be created using C++. The shell will be able to take in and execute standard commands. It will also have 3 connectors: "||", "&&", and ";". They will allow the user to run multiple commands at once. The composite pattern will be used to handle all commands and operators. We will have a base class that connects all of the classes together as an interface. The subclasses will include a regular input classe that will take in and execute the commands and operator classes that will build a tree using the operators and command inputs.

## Diagram
![image info](./images/diagram.png)
## Classes

### client.cpp
Provides the interface in which the user can use the console/shell. Takes user input.

### input.cpp
Process command function, takes in parameter string

* `execute()`

* `print()`

### base.cpp
Base class, holds virtual functions.

* `Base* left, right`

* `execute()` - Detect type of command based on string input. Runs the command.

* `print()` - Prints a new line, and $


### and.cpp
Also known as “&&” next command executed only if the first command succeeds.

* `Base* left, right`

* `execute()`

* `print()`

### or.cpp
Also known as “||” next command executed only if the first command fails.

* `Base* left, right`

* `execute()`

* `print()`

### semicolon.cpp
Also known as “;” next command is always executed.

* `Base* left, right`

* `execute()`

* `print()`


#


## Prototypes/Research

## Development and Testing Roadmap
