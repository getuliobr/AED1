
#include <stdio.h>
#include <stdlib.h>

void vetor_dobra(int *vetor,int tamanho) {
    for (int i = 0; i<tamanho;i++ )
        vetor[i]*=2;
}

void printVetor(int* vetor, int tamanho){
    printf("[");
    for(int i=0;i<tamanho;i++)
        if(i != tamanho - 1) printf("%d,",vetor[i]);
        else printf("%d",vetor[i]);
    printf("]\n");
}

int main(){
    int v1[5] = {10,20,30,40,50};
    vetor_dobra(v1, 5); // [20,40,60,80,100]
    printVetor(v1, 5);
}