
#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


asmlinkage long sys_callordenar(pid_t pid) {

	int i;
	int vetor[10];
	int status = 0;

	for (i = 0; i < 10; i++){
		pidteste = fork();

		if (pidteste == 0) {
			vetor[i] = getpid();
			exit(0);
		}

		wait(&status); 
	}

	for (i = 0; i < 10; i++){
		if (vetor[i]%2 == 0)
			kill(vetor[i], SIGKILL);
		printf("O processo filho com o pid %d foi morto", vetor[i]);
	}

}


