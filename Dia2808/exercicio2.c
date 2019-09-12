#include <stdio.h>
#include <stdlib.h>

void vetorScanf(int **vetor, int valor, int tamanho) {
    *vetor = (int*)calloc(tamanho, sizeof(int));
    for (int i = 0; i<tamanho;i++ )
        (*vetor)[i] = valor;
}

int* vetorReturn(int valor, int tamanho) {
    int *vetor;
    vetor = (int *) malloc (sizeof(int) * tamanho);
    for (int i = 0; i<tamanho;i++ )
        vetor[i] = valor;
    return vetor;
}

void printVetor(int *vetor, int tamanho){
    printf("[");
    for(int i=0;i<tamanho;i++)
        if(i != tamanho - 1) printf("%d,",vetor[i]);
        else printf("%d",vetor[i]);
    printf("]\n");
}

int main(){
    int *x;
    int *y;
    x = vetorReturn(5,10);
    printVetor(x,10);
    vetorScanf(&y,13,37);
    printVetor(y,37);
}