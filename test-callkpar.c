#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	printf("Execução do teste da Syscall SysParityKill:\n\n");
	int teste;

	teste = syscall(357);

	if (teste == 1){
		printf("O processo filho tem o PID impar e nao foi morto\n");
	}else{
		printf("O processo filho foi morto\n");
	}

	return 0;

}

