#include "shell.h"

char** strip_args(char* line){
  int i = 0;
  while(line != NULL){
    if(line[i] == '\n'){
      line[i] == '\0';
    }
  }
  return 0;
}

int count(char* line){ // count the number of delimiters from a given argument
  int num = 1;
  int i;
  for(i = 0; line[i] != '\0'; i++){
    if(line[i] == ';'){
      num++;
    }
  }
  return num;
}

char **parse_args(char* line, char delim) {
  char **args = malloc(count(line) * sizeof(char*));
  char *buff = line;
  int i = 0;
  while (buff != NULL) {
    args[i++] = strsep(&buff, args[0]);
  }
  args[i] = NULL;
  return args;
}

int exec_cmd(char *cmd){
  char **args = parse_args(cmd, ';');
  if (fork() == 0){
    if(execvp(args[0], args) == -1){
      printf("incorrect command");
    }
    free(args);
    exit(0);
  }
  else{
    wait(0);
  }
  free(args);
  return 0;
}
