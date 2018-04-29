#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	printf("Execução do teste da Syscall SysParityKill:\n\n");
	pid_t soma = syscall(359);
	printf("Soma: %d.\n", soma);
	return soma;
}
