#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>   
#include <stdlib.h>   
#include <string.h>
#include <sys/wait.h> 


//dá fork e checa se o processo filho tem pid par, se tiver, mata ele
//se nao tiver retorna 1
int sys_callkpar() {

	pid_t pid, valor_pid;
	int status;

	pid = fork();

	if (pid == 0){

		valor_pid = getpid();
		printf("o pid eh %d\n", valor_pid);

		if (valor_pid % 2 == 0){
			printf("O processo filho foi morto\n");
			kill (valor_pid, SIGKILL);
		}
		else {
			return 1;
		}


	} 

	wait(&status);
}


int main(){

	int retorno;

	retorno = sys_callkpar();

	if (retorno == 1){
		printf("O processo filho tem o PID impar e nao foi morto\n");
	}

	return 0;
}