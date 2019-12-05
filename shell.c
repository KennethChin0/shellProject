#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>


char **parse_args(char* line) {
  char **arg = malloc(6 * sizeof(char*));
  char *curr = line;
  int i = 0;
  while (curr != NULL) {
    arg[i++] = strsep(&curr, ";");
  }
  arg[i] = NULL;
  return arg;
}

int main(){
  char input[512];
  fgets(input, sizeof(input)-1, stdin);
  char ** args = parse_args(input);
  int i =0;
  while(args[i]){
    if (strcmp(args[i], "exit") ==0) {
      printf("here");
      return 0;
    }
    // printf("%s\n", args[i] );
      i++;
  }
  return 0;
}
