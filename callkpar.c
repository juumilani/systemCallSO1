#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/syscalls.h>
#include <linux/string.h>
#include <linux/kernel.h>


asmlinkage int sys_callkpar(void) {

	pid_t pid, valor_pid;
	int status;

	pid = sys_fork();

	if (pid == 0){
		valor_pid = sys_getpid();

		if (valor_pid % 2 == 0){

			sys_kill (valor_pid, SIGKILL);
			
		}else {
			return 1;
		}


	} 

}


