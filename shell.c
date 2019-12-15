#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
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
   if (strcmp(d, " ") == 0){ // remove white spaces
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

// search for stdout, stdin, and pipe
int find_redirect(char * line){
    if (strstr(line, ">")) {
      return 1;
    }
    if (strstr(line, "<")) {
      return 2;
    }
    if (strstr(line, "|"))  {
      return 3;
    }
    return 0;
}

int output(char * line){
  char ** command = parse_args(line, ">");
  int fd;
  char ** left = parse_args(command[0], " ");
  char ** right = parse_args(command[1], " ");
  fd = open(right[0], O_CREAT | O_WRONLY, 0644);
  dup(STDOUT_FILENO);
  execvp(left[0], left);
  dup2(fd, STDOUT_FILENO);
  close(fd);
  return 1;
}

int inputt(char * line){
  char ** command = parse_args(line, "<");
  char ** left = parse_args(command[0], " ");
  char ** right = parse_args(command[1], " ");
  int fd = open(right[0], O_RDONLY, 0644);
  int x = dup(STDOUT_FILENO);
  dup2(fd, x);
  execvp(left[0], left);
  if (errno) printf("%s\n", strerror(errno) );
  close(fd);
  return 1;
}
int mypipe (char * line) {
  char ** command = parse_args(line, "|");
  char ** left = parse_args(command[0], " ");
  char ** right = parse_args(command[1], " ");
  int pd[2];
  int pid;
  int backup = dup(0);
  int backup2 = dup(1);
  pipe(pd);
  pid = fork();
  if (pid){
    close(pd[1]);
    //wait(0);
    backup = dup(0);
    dup2(pd[0],0);
    execvp(right[0], right);

    dup2(backup,0);
    close(backup);
    close(pd[0]);
  }
  else {
    close(pd[0]);
    backup2 = dup(1);
    dup2(pd[1],1);
    execvp (left[0], left);
    dup2(backup2,1);
    close(backup2);
    close(pd[1]);
    exit(0);
  }
  return 1;
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
