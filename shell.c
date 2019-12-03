#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]){

	int i;
	if (argc < 2){
		printf("no arg\n");
		exit(1);
	}

	for(int i=1; i<argc; i++){
		printf("%s " , argv[i]);
		printf("\n");
	}
}

