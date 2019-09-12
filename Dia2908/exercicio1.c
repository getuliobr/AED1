#include <stdio.h>
#include <stdlib.h>

void vetor_cloneB(int **vetor, int *valor, int tamanho) {
    *vetor = (int*)calloc(tamanho, sizeof(int));
    for (int i = 0; i<tamanho;i++ )
        (*vetor)[i] = valor[i];
}

int* vetor_cloneA(int *valor, int tamanho) {
    int *vetor;
    vetor = (int *) malloc (sizeof(int) * tamanho);
    for (int i = 0; i<tamanho;i++ )
        vetor[i] = valor[i];
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
    int v[5] = {2,4,6,8,10};
    int *copia1, *copia2;
    copia1 = vetor_cloneA(v, 5);
    printVetor(copia1,5);

    vetor_cloneB(&copia2, v, 5);
    printVetor(copia2,5);
    return 0;
}