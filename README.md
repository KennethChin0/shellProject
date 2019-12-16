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
* char** strip_args(char* line)

* int count(char* line, char * c)
* char ** parse_args(char * line, char * d)
* int find_redirect(char * line)
* int output(char * line)
* int inputt(char * line)
* int mypipe (char * line)
