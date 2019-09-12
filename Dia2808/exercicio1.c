#include <stdio.h>

void printVetor(int* vetor, int tamanho){
    printf("[");
    for(int i=0;i<tamanho;i++)
        if(i != tamanho - 1) printf("%d,",vetor[i]);
        else printf("%d",vetor[i]);
    printf("]\n");
}

int main(){
    int x[4] = {1,23,431,123};
    int y[5] = {-123,321,1337,-14,8848};
    printVetor(x,4);
    printVetor(y,5);
    return 0;
}