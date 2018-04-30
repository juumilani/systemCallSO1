#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/syscalls.h>
#include <linux/string.h>
#include <linux/kernel.h>

//pid_t vetor[5];
//pid_t somacontrole = 0;


pid_t teste(pid_t* somacontrole){

	pid_t pid, somafinal, soma = 0, vetor[5];
	int i;

	for(i=0; i<5; i++){
   		pid = sys_fork();
   
   		if (pid == 0){
			vetor[i] = sys_getpid();
			soma = soma + vetor[i];

		}else {
			break; 
    	}

    	if(i == 4){
			somafinal = soma;
			*somacontrole = soma;
			return somafinal;
    	}
		
	}
			
}


asmlinkage pid_t sys_callkpar(void) {

	pid_t somacontrole = 0;

	pid_t somafinal = teste(&somacontrole);

	if (somafinal == somacontrole){
		if (somacontrole != 0){
			return somacontrole;
		} 
	}
}

