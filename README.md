# systemCallSO1
Neste projeto devemos inserir um novo system call ao Kernel do Linux.

Nossa syscall pega um processo, cria 10 filhos através da call fork() e coloca seus PIDs em um vetor. Após isso, é lido esse vetor e todos os processos filhos que sejam pares são mortos.

