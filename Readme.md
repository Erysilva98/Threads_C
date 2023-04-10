# Threads em C


- Compilando os Programas 

    gcc -pthread program1.c -o thread1 | gcc -pthread program2.c -o thread2

- Executando os 2 Programas no mesmo Terminal

    ./thread1 $1 & ./thread2 $1 &
