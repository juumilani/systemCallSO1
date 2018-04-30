#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/syscalls.h>
#include <linux/string.h>
#include <linux/kernel.h>


asmlinkage int sys_callkpar(void) {

	pid_t pid, var1;
	int status;

	pid = sys_fork();

	if (pid == 0){
		var1 = sys_getpid();

		if (var1%2 == 0){
			sys_kill (var1, SIGKILL);
		}
		else {
			return 1;
		}


	} 

}


