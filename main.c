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
    int redirect = find_redirect(args[i]);
    // printf("%d\n",  redirect);
    //stout

    if(redirect == 1){
      int result = fork();
      if (result) {
          int status;
          wait(&status);
        } else {
          output(args[i]);
        }

    }

    if (redirect == 2) {
      int result = fork();
      if (result) {
          int status;
          wait(&status);
        } else {
          inputt(args[i]);
        }

    }

    if (redirect == 3) {
      printf("pipe\n");
      mypipe(args[i]);
    }

    if (redirect == 0) {
    char ** command = parse_args(args[i], " ");
    if (strcmp(command[0], "exit") == 0) {
      return 0;
    }
    if (strcmp(command[0], "cd") == 0) {
      if (command[2] != NULL){
        printf("Syntax error: cd <filepath> \n" );
      }
      else{
        chdir(command[1]);
        if (errno){
          printf("%s\n", strerror(errno));
          errno = 0;
        }
      }
    }
    else {
    int result = fork();
    if (result) {
        int status;
        wait(&status);
      } else {
        execvp(command[0], command);
        if (errno) {
          printf("%s: command not found\n", command[0]);
          return 0;
       }
      }
    }
    // i++;
  }
  i++;
}
    free(args);
  }

  return 0;
}
