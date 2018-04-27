# systemCallSO1
Neste projeto devemos inserir uma nova system call ao Kernel do Linux. Nossa syscall pega um processo, cria 10 filhos através da call fork() e coloca seus PIDs em um vetor. Após isso, é lido esse vetor e todos os processos filhos que sejam pares são mortos.

Para implementação do trabalho, utilizamos o kernel em sua versão 3.17.2, e a imagem de sistema DC_SO.img fornecida em aula.

### Instruções de instalação e execução

Para testar a implementação da systemcall, realizamos os seguintes passos:

1. Descompactar o arquivo Projeto_01.zip, que contem o kernel e a imagem do sistema.

2. Modificar o arquivo *linux-3.17.2/arch/x86/syscalls/syscall_32.tlb*, adcionando a seguinte linha ao final do código:
 
3. Adcionar a declaração da função  *nome da nossa função* no final do arquivo *linux-3.17.2/include/linux/syscalls.h*: 

4. Incluir o código *nomedonossocódigo* na pasta *linux-3.17.2/arch/x86/kernel/*:

5. Modificar o Makefile da pasta *linux-3.17.2/arch/x86/kernel/*, para que o nosso arquivo *nomedonossocódigo* seja compilado com o kernel, incluindo a linha:

6. Acessar a pasta *linux-3.17.2/* e compilar o kernel, com o comando:
    **make -j 5 ARCH=i386**
7. 


-----------------------------

**Realizado pelos alunos:**
* Cassiano Maia - RA:726507
* Julia Milani  - RA:726
* Mariana Cavichioli Silva - RA:726

**Disciplina:** Sistemas Operacionais 01 - Profª Kellen Vivaldini