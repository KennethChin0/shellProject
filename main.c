#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"



int main(){
  char input[512];
  while(1) {
    char dir[1024];
    getcwd(dir, sizeof(dir));
    printf("%s$ ", dir);
    fgets(input, sizeof(input), stdin);
    if (input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';
    char ** args = parse_args(input, ";");
    int i = 0;
  while(args[i]){
    // printf("%s\n", args[i] );
    char ** command = parse_args(args[i], " ");
    if (strcmp(command[0], "exit") == 0) {
      // printf("here");
      return 0;
    }
    // printf("adsfasdf%s\n", command[0] );
    // free(command);
    // i++;

    int result = fork();
    if (result) {
        int status;
        wait(&status);
      } else {
        // printf("adsf\n" );
        execvp(command[0], command);
        if (errno) {
          printf("%s: command not found\n", command[0]);
          return 0;
       }
      }
      i++;
    }
    free(args);
  }

  return 0;
}
