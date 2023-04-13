#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

// Definir o Numero de tarefas 

#define tarefas 5000

// Tamanho máximo do Caracter
#define tamMax 100

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

int numThread = 3;
int numTarefas;
int totalTarefas;

void *thread1(void *arg);
void *thread2(void *arg);
void *thread3(void *arg);
void escreveArquivo(char* arquivo, int nExecucao, char* programa, char* numThread);

int main() {
    clock_t inicio, fim;
    double tempoGasto;

    // Numero de Tarefas da Thread
    numTarefas = tarefas;
    totalTarefas = numTarefas * numThread;

    pthread_t threads[numThread];
    inicio = clock();
    pthread_create(&threads[0], NULL, thread1, NULL);
    pthread_create(&threads[1], NULL, thread2, NULL);
    pthread_create(&threads[2], NULL, thread3, NULL);
    fim = clock();

    // Tempo em Segundos
    tempoGasto = (double)(fim - inicio);
    printf("\n\t Executando o Programa 1 \n\n"
    " Executando %d tarefas \n"
    " Foram executadas %d Tarefas no Total \n"
    " Tempo gasto: %.2f segundos\n\n", tarefas, totalTarefas, tempoGasto);
    
    for (int i = 0; i < numThread; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *thread1(void *arg) {
    int nExecucao = 0;
    char programa[tamMax] = "Programa2";
    char nomeThread[tamMax] = "Thread1";
    char arquivo1[tamMax] = "registro1.txt";
    char arquivo2[tamMax] = "registro2.txt";

    for (int i = 0; i < numTarefas; i++) {
        pthread_mutex_lock(&mutex1);
        nExecucao++;
        escreveArquivo(arquivo1, nExecucao, programa, nomeThread);
        escreveArquivo(arquivo2, nExecucao, programa, nomeThread);
        if(nExecucao == numThread)
        {
            nExecucao = 0;
        }
        pthread_mutex_unlock(&mutex2);
    }

    return NULL;
}

void *thread2(void *arg) {
    int nExecucao = 0;
    char programa[tamMax] = "Programa2";
    char nomeThread[tamMax] = "Thread2";
    char arquivo1[tamMax] = "registro1.txt";
    char arquivo2[tamMax] = "registro2.txt";

    for (int i = 0; i < numTarefas; i++) {
        pthread_mutex_lock(&mutex2);
        nExecucao++;
        escreveArquivo(arquivo1, nExecucao, programa, nomeThread);
        escreveArquivo(arquivo2, nExecucao, programa, nomeThread);
        if(nExecucao == numThread)
        {
            nExecucao = 0;
        }
        pthread_mutex_unlock(&mutex1);
    }

    return NULL;
}

void *thread3(void *arg) {
    int nExecucao = 0;
    char programa[tamMax] = "Programa2";
    char nomeThread[tamMax] = "Thread3";
    char arquivo1[tamMax] = "registro1.txt";
    char arquivo2[tamMax] = "registro2.txt";

    for (int i = 0; i < numTarefas; i++) {
        pthread_mutex_lock(&mutex2);
        nExecucao++;
        escreveArquivo(arquivo1, nExecucao, programa, nomeThread);
        escreveArquivo(arquivo2, nExecucao, programa, nomeThread);
        if(nExecucao == numThread)
        {
            nExecucao = 0;
        }
        pthread_mutex_unlock(&mutex1);
    }

    return NULL;
}

void escreveArquivo(char* arquivo, int nExecucao, char* programa, char* nomeThread) {
    FILE *fp = fopen(arquivo, "a");

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", arquivo);
        exit(1);
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char data_hora[tamMax];
    strftime(data_hora, tamMax, "%c", t);

    fprintf(fp, "%d - %s - %s - Data/Hora: %s\n", nExecucao, programa, nomeThread, data_hora);

    fclose(fp);
}