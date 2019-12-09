#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>


char** strip_args(char* line);

int count(char* line);

char **parse_args(char* line, char delim);

int exec_cmd(char *cmd);
