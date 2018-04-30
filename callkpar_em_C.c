#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>   
#include <stdlib.h>   
#include <string.h>
#include <sys/wait.h> 


//dá fork e checa se o processo filho tem pid par, se tiver, mata ele
//se nao tiver retorna 1
int sys_killparchild() {

	pid_t pid, var1;
	int status;

	pid = fork();

	if (pid == 0){
		var1 = getpid();
		printf("o pid eh %d\n", var1);
		if (var1%2 == 0){
			printf("O processo filho foi morto\n");
			kill (var1, SIGKILL);
		}
		else {
			return 1;
		}


	} 

	wait(&status);
}


int main(){

	int teste;

	teste = sys_killparchild();

	if (teste == 1){
		printf("O processo filho tem o PID impar e nao foi morto\n");
	}

	return 0;
}