# systemCallSO1
Neste projeto devemos inserir uma nova system call ao Kernel do Linux. Nossa syscall pega um processo, cria 10 filhos através da call fork() e coloca seus PIDs em um vetor. Após isso, é lido esse vetor e todos os processos filhos que sejam pares são mortos.

Para implementação do trabalho, utilizamos o kernel em sua versão 3.17.2, e a imagem de sistema DC_SO.img fornecida em aula.

### Instruções de instalação e execução

Para testar a implementação da systemcall, realizamos os seguintes passos:

1. Descompactar o arquivo Projeto_01.zip, que contem o kernel e a imagem do sistema.

2. Modificar o arquivo *linux-3.17.2/arch/x86/syscalls/syscall_32.tlb*, adcionando a seguinte linha ao final do código:
    **357     i386    callkpar                  sys_callkpar**
3. Adcionar a declaração da função  *nome da nossa função* no final do arquivo *linux-3.17.2/include/linux/syscalls.h*: 
    **asmlinkage void sys_callkpar(pid_t pid);**
4. Incluir o código **callkpar.c** na pasta *linux-3.17.2/arch/x86/kernel/*.

5. Modificar o Makefile da pasta *linux-3.17.2/arch/x86/kernel/*, para que o nosso arquivo **callkpar.c** seja compilado com o kernel, incluindo a linha:
    **obj-y                                   += callkpar.o**
6. Acessar a pasta *linux-3.17.2/* e compilar o kernel, com o comando:
    **$ make -j 5 ARCH=i386**
7. Após isso, compilar o código de teste **test-callkpar.c** com o comando:
    **$ gcc -m32 -static test-callkpar.c -o test-callkpar**
8. Agora devemos executar nossa máquina virtual para testar a implementação de nossasystemcall no kernel, utilizando o comando:
    **$ qemu-system-i386 -hda DC_SO.img -kernel linux-3.17.2/arch/i386/boot/bzImage -append "ro root=/dev/hda" -hdb test-callkpar**
9. Após a maquina inciar, logar com as credênciais:
    **user:root**
    **password:root**
10. Executar os seguintes comandos para teste da systemcall:
    **$ cat /dev/hdb > test-callkpar**
    **$ chmod +x test-callkpar**
    **$ ./test-callkpar**


-----------------------------

**Realizado pelos alunos:**
* Cassiano Maia - RA:726507
* Julia Milani  - RA:726
* Mariana Cavichioli Silva - RA:726

**Disciplina:** Sistemas Operacionais 01 - Profª Kellen Vivaldini