#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/syscalls.h>
#include <linux/string.h>
#include <linux/kernel.h>

pid_t vetor[5];


asmlinkage void sys_callsumpid() {

	char Identifier[20];
	pid_t pid[5], teste[5], soma = 0;
	int i, j;

	memset(vetor, 0, sizeof(vetor));

	for(i=0; i<5; i++){
   		pid[i] = fork();
   
   		if (pid[i] == 0){
			teste[i] = getpid();
			//printf("todos: %d\n", teste[i]);
			soma = soma + teste[i];
			//printf("soma: %d\n\n", soma);

			if(i==4){
				//printf("somafinal: %d\n\n", soma);	

				for(int j=0; j<5; j++){
					kill(teste[j], SIGTERM);
				}
	
				return soma;
				
			}


		}else if (pid[i] < 0){

			//printf ("\n Failed to fork");
			exit(1);

    		}else {
			break; 
    		}
		
	}
	
}
