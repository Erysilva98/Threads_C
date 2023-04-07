#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_EXECUCOES 3 // Quantidade máxima de execuções por thread

void* thread1(void* arg) {
    int i;
    char nome_thread[] = "Thread 1";
    time_t rawtime;
    struct tm * timeinfo;
    char data_hora[80];

    for (i = 1; i <= *((int*)arg); i++) {
        // Obtém data e hora atual
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(data_hora, sizeof(data_hora), "%d/%m/%Y %H:%M:%S", timeinfo);

        // Grava informações nos arquivos
        FILE* arquivo1 = fopen("registro1.txt", "a");
        fprintf(arquivo1, "Execucao %d - Programa 2 - %s - %s\n", i, nome_thread, data_hora);
        fclose(arquivo1);

        FILE* arquivo2 = fopen("registro2.txt", "a");
        fprintf(arquivo2, "Execucao %d - Programa 2 - %s - %s\n", i, nome_thread, data_hora);
        fclose(arquivo2);
    }

    pthread_exit(NULL);
}

void* thread2(void* arg) {
    int i;
    char nome_thread[] = "Thread 2";
    time_t rawtime;
    struct tm * timeinfo;
    char data_hora[80];

    for (i = 1; i <= *((int*)arg); i++) {
        // Obtém data e hora atual
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(data_hora, sizeof(data_hora), "%d/%m/%Y %H:%M:%S", timeinfo);

        // Grava informações nos arquivos
        FILE* arquivo1 = fopen("registro1.txt", "a");
        fprintf(arquivo1, "Execucao %d - Programa 2 - %s - %s\n", i, nome_thread, data_hora);
        fclose(arquivo1);

        FILE* arquivo2 = fopen("registro2.txt", "a");
        fprintf(arquivo2, "Execucao %d - Programa 2 - %s - %s\n", i, nome_thread, data_hora);
        fclose(arquivo2);
    }

    pthread_exit(NULL);
}

void* thread3(void* arg) {
    int i;
    char nome_thread[] = "Thread 3";
    time_t rawtime;
    struct tm * timeinfo;
    char data_hora[80];

    for (i = 1; i <= *((int*)arg); i++) {
        // Obtém data e hora atual
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(data_hora, sizeof(data_hora), "%d/%m/%Y %H:%M:%S", timeinfo);

        // Grava informações nos arquivos
        FILE* arquivo1 = fopen("registro1.txt", "a");
        fprintf(arquivo1, "Execucao %d - Programa 2 - %s - %s\n", i, nome_thread, data_hora);
        fclose(arquivo1);

        FILE* arquivo2 = fopen("registro2.txt", "a");
        fprintf(arquivo2, "Execucao %d - Programa 2 - %s - %s\n", i, nome_thread, data_hora);
        fclose(arquivo2);
    }

    pthread_exit(NULL);
}

int main() {
    int qtd_execucoes_thread1, qtd_execucoes_thread2, qtd_execucoes_thread3;
    pthread_t thread_id1, thread_id2, thread_id3;

    // Quantidade de execuções para cada thread
    printf("Execucoes para programa 2 Thread 1 = 5 Mil Registro \n");
    // scanf("%d", &qtd_execucoes_thread1);
    qtd_execucoes_thread1 = 5000;

    printf("Execucoes para programa 2 Thread 2 = 10 Mil Registro \n");
    // scanf("%d", &qtd_execucoes_thread2);
    qtd_execucoes_thread2 = 10000;

    printf("Execucoes para programa 2 Thread 3 = 100 Mil Registro \n");
    //scanf("%d", &qtd_execucoes_thread3);
    qtd_execucoes_thread3 = 100000;

    // Cria as threads
    pthread_create(&thread_id1, NULL, thread1, (void*)&qtd_execucoes_thread1);
    pthread_create(&thread_id2, NULL, thread2, (void*)&qtd_execucoes_thread2);
    pthread_create(&thread_id3, NULL, thread3, (void*)&qtd_execucoes_thread3);

    // Aguarda as threads terminarem
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    pthread_join(thread_id3, NULL);

    return 0;
}
