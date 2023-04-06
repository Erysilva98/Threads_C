#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *escreveArquivo1(void *arg);
//void *escreveArquivo2(void *arg);

int main()
{
    int processo1 = 2;
    pthread_t thread1, thread2, thread3;

    printf("Informe a quantidade de vezes que a Thread 1 deve executar: ")
    // scanf("%d", &processo1);

    // printf("Informe a quantidade de vezes que a Thread 2 deve executar: ")
    // scanf("%d", &processo2);

    // printf("Informe a quantidade de vezes que a Thread 3 deve executar: ")
    // scanf("%d", &processo3);

    // Criando os processos
    pthread_create(&thread1, NULL, escreveArquivo1, processo1);
    // pthread_create(&thread2, NULL, escreveArquivo2, processo2);
    // pthread_create(&thread3, NULL, escreveArquivo1, processo3);

    pthread_join(thread1, NULL);
    // pthread_join(thread2, NULL);
    // pthread_join(thread3, NULL);

    printf("As Threads terminaram seus Processos. \n")

    return 0;
}

void escreveArquivo1(void *arg)
{
    // Resevando espaço na memória
    int no = *(int *)arg;
    arquivo *leitura;

    leitura = fopen("registro1.txt", "a");

    // Obtendo o tempo atual
    time_t atual;
    struct tempo *tempoAtual; 

    atual = time(NULL);
    tempoAtual = localtime(&atual)

    for (int i =0; i <no; i++ )
    {
        fprintf(abrir, "Execucao %d do programa %s por Thread %lu em %d/%d/%d %d/%d/%d. \n,"
            i+1,__FILE__, pthread_self(), 
            tempoAtual->tempDia, tempoAtual->tempMes + 1, tempoAtual->tempAno + 1900,
            tempoAtual->tempHoura, tempoAtual->tempMinuto, tempoAtual->tempSegundo
        );
    }
    fclose(leitura);
    pthread_exit(NULL);
}