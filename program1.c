#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void* thread1(void* arg) {
    int i;
    char nomeThread[] = "Thread 1";
    time_t tempoTotal;
    struct tm * tempoInfo;
    char dataHora[80];

    for (i = 1; i <= *((int*)arg); i++) {
        // Obtém data e hora atual
        time(&tempoTotal);
        tempoInfo = localtime(&tempoTotal);
        strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", tempoInfo);

        // Grava informações nos arquivos
        FILE* arquivo1 = fopen("registro1.txt", "a");
        fprintf(arquivo1, "Execucao %d - Programa 1 - %s - %s\n", i, nomeThread, dataHora);
        fclose(arquivo1);

        FILE* arquivo2 = fopen("registro2.txt", "a");
        fprintf(arquivo2, "Execucao %d - Programa 1 - %s - %s\n", i, nomeThread, dataHora);
        fclose(arquivo2);
    }

    pthread_exit(NULL);
}

void* thread2(void* arg) {
    int i;
    char nomeThread[] = "Thread 2";
    time_t tempoTotal;
    struct tm * tempoInfo;
    char dataHora[80];

    for (i = 1; i <= *((int*)arg); i++) {
        // Obtém data e hora atual
        time(&tempoTotal);
        tempoInfo = localtime(&tempoTotal);
        strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", tempoInfo);

        // Grava informações nos arquivos
        FILE* arquivo1 = fopen("registro1.txt", "a");
        fprintf(arquivo1, "Execucao %d - Programa 1 - %s - %s\n", i, nomeThread, dataHora);
        fclose(arquivo1);

        FILE* arquivo2 = fopen("registro2.txt", "a");
        fprintf(arquivo2, "Execucao %d - Programa 1 - %s - %s\n", i, nomeThread, dataHora);
        fclose(arquivo2);
    }

    pthread_exit(NULL);
}

void* thread3(void* arg) {
    int i;
    char nomeThread[] = "Thread 3";
    time_t tempoTotal;
    struct tm * tempoInfo;
    char dataHora[80];

    for (i = 1; i <= *((int*)arg); i++) {
        // Obtém data e hora atual
        time(&tempoTotal);
        tempoInfo = localtime(&tempoTotal);
        strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", tempoInfo);

        // Grava informações nos arquivos
        FILE* arquivo1 = fopen("registro1.txt", "a");
        fprintf(arquivo1, "Execucao %d - Programa 1 - %s - %s\n", i, nomeThread, dataHora);
        fclose(arquivo1);

        FILE* arquivo2 = fopen("registro2.txt", "a");
        fprintf(arquivo2, "Execucao %d - Programa 1 - %s - %s\n", i, nomeThread, dataHora);
        fclose(arquivo2);
    }

    pthread_exit(NULL);
}

int main() {
    int tarefaThread1, tarefaThread2, tarefaThread3;
    pthread_t idThread1, idThread2, idThread3;

    // Quantidade de execuções para cada thread
    printf("\nExecucoes para programa 1 Thread 1 = 5 Mil Registro \n");
    // scanf("%d", &tarefaThread1);
    tarefaThread1 = 5000;

    printf("Execucoes para programa 1 Thread 2 = 10 Mil Registro \n");
    // scanf("%d", &tarefaThread2);
    tarefaThread2 = 10000;

    printf("Execucoes para programa 1 Thread 3 = 100 Mil Registro \n");
    //scanf("%d", &tarefaThread3);
    tarefaThread3 = 100000;

    // Cria as threads  
    pthread_create(&idThread1, NULL, thread1, (void*)&tarefaThread1);
    pthread_create(&idThread2, NULL, thread2, (void*)&tarefaThread2);
    pthread_create(&idThread3, NULL, thread3, (void*)&tarefaThread3);

    // Aguarda as threads terminarem
    pthread_join(idThread1, NULL);
    pthread_join(idThread2, NULL);
    pthread_join(idThread3, NULL);

    printf("\n Programa 1 Finalizado \n");
    return 0;
    
}
