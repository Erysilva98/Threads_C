#!/bin/bash

# Compila os programas
gcc -o thread1 program1.c -lpthread
gcc -o thread2 program2.c -lpthread

# Executa os programas em threads separadas
./thread1 &
./thread2 &

# Aguarda a execução dos programas terminarem
wait

# Remove os arquivos objeto gerados durante a compilação
rm thread1 thread2
