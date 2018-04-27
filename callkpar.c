#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/syscalls.h>
#include <linux/string.h>
#include <linux/kernel.h>

pid_t vetor[10];

void salvaNumero(int j, pid_t pid1){

	vetor[j] = pid1;
	if (vetor[j]%2 == 0){

		printk("O processo filho com o pid %d foi morto\n", vetor[j]);
		sys_kill(vetor[j], SIGKILL);
	}
}

asmlinkage void sys_callkpar(pid_t pid) {
	printk("Syscall iniciada.\n");
	int i;
	pid_t pidteste, aux;
	pid_t pidpai;

	pidpai = pid;

	memset(vetor, 0,sizeof(vetor));

	for (i = 0; i < 10; i++){
		pidteste = sys_fork();

		if ( pidteste ==  0){
			aux = sys_getpid();
			salvaNumero(i, aux);
			sys_exit(0);
		}
	}
}