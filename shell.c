#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]){
	int i;

	if (argc < 2){
		printf("no arg\n");
		exit(1);
	}

	for(int i=1; i<argc; i++){
		int pid = fork();
		if (pid < 0){
			perror("fork failed");
			exit(1);
		}
		else if (pid == 0){
			printf("%s " , argv[i]);
			printf("\n");
			execv(argv[0], argv);
		}
}

