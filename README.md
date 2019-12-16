# shellProject
Kenneth Chin and Minuk Kim, System Level Programming, PD 4, Project 1

**We wrote a shell interface that**
1. reads in a line with single command or multiple commands separated with delimiter ";"

2. takes the "cd" command to change the location of directory

3. quits the program when the "exit" command or "CTRL + C", alternative "interrupt" signal, is used

4. redirects inputs and outputs to files using ">" and "<"

5. connects two commands to feed ouput of one command into the input of another using "|"

# Extra Features
1. Supports multiple redirections ...
2. ..

# Limitations
1. .
2. Unable to implement the ">>" redirection command that appends output to a files

# Function Headers

*  `int count(char* line, char * c)`
  - count the number of delimiters from a given argument seperated by char c.
* `char ** parse_args(char * line, char * d)`
  - parses through a char pointer.
  - returns an arrary of pointers seperated by a given delimeter.
* `int find_redirect(char * line)`
  - takes in input char * args and will return int based on if a certain character is present.
  - will return 1 if '>'
  - will return 2 if '<'
  - will return 3 if '|'
* `int output(char * line)`
  - takes an input char * line and returns 1.
  - runs stdout to a file.
* `int inputt(char * line)`
  - takes an input char * line and returns 1.
  - runs stdin to a file.
* `int mypipe (char * line)`
  - takes char * line.
  - parses for | character.
  - forks and runs the necessary arguments.
