#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	printf("Execução do teste da Syscall:\n\n");
	int retorno;

	retorno = syscall(357);

	if (retorno == 1){
		printf("O processo filho tem o PID impar e nao foi morto\n\n");
	}else{
		printf("O processo filho foi morto\n\n");
	}

	return 0;

}

