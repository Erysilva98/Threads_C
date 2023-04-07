#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *write_file1(void *arg);
void *write_file2(void *arg);

int main() {
    int a, b, c;
    pthread_t tid1, tid2, tid3;

    printf("Digite a quantidade de vezes que a Thread 1 deve executar: ");
    scanf("%d", &a);
    printf("Digite a quantidade de vezes que a Thread 2 deve executar: ");
    scanf("%d", &b);
    printf("Digite a quantidade de vezes que a Thread 3 deve executar: ");
    scanf("%d", &c);

    pthread_create(&tid1, NULL, write_file1, &a);
    pthread_create(&tid2, NULL, write_file2, &b);
    pthread_create(&tid3, NULL, write_file1, &c);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    printf("As threads terminaram suas execuções.\n");
    return 0;
}

void *write_file1(void *arg) {
    int n = *(int *)arg;
    FILE *fp;
    fp = fopen("registro1.txt", "a");

    time_t now;
    struct tm *tm_now;
    now = time(NULL);
    tm_now = localtime(&now);

    for (int i = 0; i < n; i++) {
        fprintf(fp, "Execução %d do programa %s pela Thread %lu em %d/%d/%d %d:%d:%d.\n",
                i+1, __FILE__, pthread_self(), tm_now->tm_mday, tm_now->tm_mon + 1, tm_now->tm_year + 1900,
                tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
    }

    fclose(fp);
    pthread_exit(NULL);
}

void *write_file2(void *arg) {
    int n = *(int *)arg;
    FILE *fp;
    fp = fopen("registro2.txt", "a");

    time_t now;
    struct tm *tm_now;
    now = time(NULL);
    tm_now = localtime(&now);

    for (int i = 0; i < n; i++) {
        fprintf(fp, "Execução %d do programa %s pela Thread %lu em %d/%d/%d %d:%d:%d.\n",
                i+1, __FILE__, pthread_self(), tm_now->tm_mday, tm_now->tm_mon + 1, tm_now->tm_year + 1900,
                tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
    }

    fclose(fp);
    pthread_exit(NULL);
}
