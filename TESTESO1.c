/*
fork - create a child process 
Prof Kelen Vivaldini
September 2017
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>   
#include <stdlib.h>   
#include <string.h>
#include <sys/wait.h> 

pid_t par[5];

int main(){

	char Identifier[20];
	pid_t pid[5], teste[5];
	int i, j;

	memset(par, 0, sizeof(par));

	for(i=0; i<5; i++){
   		pid[i] = fork();
   
   		if (pid[i] == 0){

			teste[i] = getpid();

			printf("todos: %d\n", teste[i]);

			if(teste[i] % 2 == 0){
				par[i] = teste[i];
				printf("par: %d\n", par[i]);
			}


			if(i == 4){
				printf("\n");
				for(j=4; j>=0; j--){
					printf("par2: %d\n", par[j]);
					if(par[j] != 0 ){
						printf("matar: %d\n\n", par[j]);
						kill(par[j], SIGTERM);
					}
				}
			}		

		}else if (pid[i] < 0){

			printf ("\n Failed to fork");
			exit(1);

    	}else {
			break;
    	}
		
	}

	sleep(60);	

}
