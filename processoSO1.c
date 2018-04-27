#include <unistd.h>
//#include <linux/linkage.h>
#include <linux/sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

pid_t vetor[10];


void salvaNumero(int j, pid_t pid1){

	vetor[j] = pid1;
	if (vetor[j]%2 == 0){

		printf("O processo filho com o pid %d foi morto\n", vetor[j]);
		kill(vetor[j], SIGKILL);
	}

}

void  sys_callkpar(pid_t pid) {

	int i;
	pid_t pidteste, aux;
	pid_t pidpai;
	int status = 0;

	pidpai = pid;

	memset(vetor, 0,sizeof(vetor));

	for (i = 0; i < 10; i++){
		pidteste = fork();

		if ( pidteste ==  0){
			aux = getpid();
			salvaNumero(i, aux);
			_exit(0);
		}
	}

}


int main(){

	pid_t pidaux;
	pidaux = getpid();

	sys_callkpar(pidaux);

	return 0;
}