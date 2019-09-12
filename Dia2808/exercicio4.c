#include <stdio.h>
#include <stdlib.h>

int *intercala_a(int* vetora, int tamanhoa, int* vetorb, int tamanhob){
    int *vetor;
    int tamanhovetor;
    if (tamanhoa > tamanhob) tamanhovetor = tamanhoa * 2;
    else tamanhovetor = tamanhob * 2;
    vetor = (int *) malloc (sizeof (int) * tamanhovetor);
    for(int i=0;i<tamanhoa;i++)
        vetor[i*2] = vetora[i];
    for(int i=0;i<tamanhob;i++)
        vetor[(i*2)+1] = vetorb[i];
    return vetor;
}

void intercala_b(int* vetora, int tamanhoa, int* vetorb, int tamanhob, int *saida){
    int tamanhovetor;
    if (tamanhoa > tamanhob) tamanhovetor = tamanhoa * 2;
    else tamanhovetor = tamanhob * 2;
    for(int i=0;i<tamanhovetor;i++) saida[i] = 0;
    for(int i=0;i<tamanhoa;i++)
        saida[i*2] = vetora[i];
    for(int i=0;i<tamanhob;i++)
        saida[(i*2)+1] = vetorb[i];
}

void printVetor(int* vetor, int tamanho){
    printf("[");
    for(int i=0;i<tamanho;i++)
        if(i != tamanho - 1) printf("%d,",vetor[i]);
        else printf("%d",vetor[i]);
    printf("]\n");
}

int main(){
    int v1[3] = {2,4,6};
    int v2[4] = {3,5,7,9};
    int v3[8];
    int *v4;
    v4 = intercala_a(v1, 3, v2, 4);
    printVetor(v4,8);
    intercala_b(v1, 3, v2, 4, v3);
    printVetor(v3,8);
}