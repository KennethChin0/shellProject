#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
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

int count(char* line, char * c){ // count the number of delimiters from a given argument
  int num = 1;
  int i;
  for(i = 0; line[i] != '\0'; i++){
    // printf("%s\n", &line[i] );
    if(&line[i] != c){
      num++;
    }
  }
  return num;
}

char ** parse_args(char * line, char * d) { // up to size - 1 commands/args
 char ** args = malloc(count(line, d) * sizeof(char *));
 int i = 0;
 while(line != NULL && i < (count(line, d) - 1)) {
   char * holder = strsep(&line, d);
   if (strcmp(d, " ") == 0){ // remove extraneous spaces
     if(holder[0] != '\0') {
       args[i] = holder;
       i++;
     }
   }
   else{
     args[i] = holder;
     i++;
   }
 }
 args[i] = NULL;
 return args;
}






// int exec_cmd(char *cmd){
//   // char **args = parse_args(cmd, ';');
//   if (fork() == 0){
//     if(execvp(args[0], args) == -1){
//       printf("incorrect command");
//     }
//     free(args);
//     exit(0);
//   }
//   else{
//     wait(0);
//   }
//   free(args);
//   return 0;
// }
