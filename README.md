A beautiful simple shell code that passes Betty checks.

shell.h: 
This file header encompasses function prototypes, definitions, structures, macros, and constants utilized across the project. Its purpose is to provide an interface for other source files to obtain shared declarations, thereby enhancing modularity and facilitating code organization.

main.c:
This file is the shell's primary starting point. It typically performs tasks such as initializing essential variables, configuring the environment, showing a prompt, and managing the primary loop responsible for reading and executing commands.

getline.c:
This file is responsible for the task of capturing and storing a line of user input in a designated buffer. It may contain functions that interact with the input stream and carry out essential operations such as input validation or memory allocation.

split.c:
This particular file focuses on the process of analyzing the user input and breaking it down into separate commands and their respective arguments. It may consist of functions that divide the input string into tokens, manage special characters, and structure the parsed data in a manner that enables subsequent processing.

helper files (helper.c, helpers_2.c & input_helpers.c):
Typically, these files comprise utility functions that are employed throughout the codebase. They encompass commonly utilized functions such as string manipulation, memory management, or other auxiliary functions that aid in implementing the shell's functionality.

linkedlist.c:
This particular file is responsible for the implementation of a data structure known as a linked list. It contains functions that facilitate the creation, modification, and traversal of linked lists. Linked lists are utilized within the shell to store and manage various data elements, such as command history or lists of environment variables.

str_funcs1.c & str_funcs2.c:
These files consist of functions that manipulate strings. They may encompass functions for performing common operations on strings, such as concatenation, comparison, tokenization, or any other string-related functionality that the shell requires.

env_builtins.c:
The purpose of this file is to provide functions for managing environment variables. It contains implementations for setting, retrieving, and modifying environment variables within the shell. These functions are designed to handle built-in commands that are specifically related to managing environment variables.

alias_builtins.c:
If your project incorporates alias functionality, this file may contain functions that manage operations related to aliases. It could include functions for creating, retrieving, or resolving aliases specified by the user. These functions are responsible for handling the alias-related features within the project.

proc_file_comm.c:
This particular file is responsible for managing communication with process file systems in Unix-like systems. It encompasses functions that facilitate reading from or writing to process file systems, enabling access to system information or data associated with processes.

locate.c:
The contents of this file consist of functions designed to find executable files within the system's PATH variable. These functions enable the search for executables within the directories listed in the PATH variable and verify their presence or accessibility.

errors.c:
This file has the capability to include functions that handle errors, such as displaying error messages or terminating the program in a controlled manner.