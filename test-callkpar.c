#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pidaux;
	pidaux = getpid();
	printf("Execução do teste da Syscall SysParityKill:\n\n");
	syscall(357,pidaux);

	return 0;
}