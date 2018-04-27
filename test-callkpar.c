#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pidaux;
	pidaux = getpid();
	printf("Pid atual = %d\n", pidaux);
	printf("Execução do teste da Syscall SysParityKill:\n\n");
	syscall(357, pidaux);
	printf("Syscall executada.");
	return 0;
}