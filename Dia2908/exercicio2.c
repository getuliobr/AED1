#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int aleatorizar(int seed){
    srand(time(0) + seed);
    return 1 + (rand() % 1000);
}

int* vetor_aleatorio(int tamanho) {
    int *vetor;
    vetor = (int *) malloc (sizeof(int) * tamanho);
    for (int i = 0; i<tamanho;i++ )
        if (i == 0) vetor[i] = aleatorizar(i*(aleatorizar(i)%100+1));
        else vetor[i] = aleatorizar(vetor[i-1]*(aleatorizar(i)%10+1));
    return vetor;
}

void printVetor(int* vetor, int tamanho){
    printf("[");
    for(int i=0;i<tamanho;i++)
        if(i != tamanho - 1) printf("%d,",vetor[i]);
        else printf("%d",vetor[i]);
    printf("]\n");
}

int main(){
    int *v1 = vetor_aleatorio(10);
    int *v2 = vetor_aleatorio(100);

    printVetor(v1,10);
    printVetor(v2,100);
    return 0;
}