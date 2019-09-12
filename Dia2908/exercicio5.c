#include <stdio.h>
#include <stdlib.h>

void dobrarVetor(int **vetor,int tamanho) {
    int *salvar = (int *) malloc (sizeof(int) * tamanho * 2);
    for (int i = 0; i<tamanho*2;i++ )
        if( i < tamanho) salvar[i] = (*vetor)[i];
        else salvar[i] = 0;
    free(*vetor);
    *vetor = salvar;
}

void printVetor(int* vetor, int tamanho){
    printf("[");
    for(int i=0;i<tamanho;i++)
        if(i != tamanho - 1) printf("%d,",vetor[i]);
        else printf("%d",vetor[i]);
    printf("]\n");
}

int main(){
    int* v = (int*) calloc(5, sizeof(int));
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;
    printVetor(v, 5);
    dobrarVetor(&v, 5);
    printVetor(v, 10);
}