#include <stdio.h>

int maior(int* vetor, int tamanho){
    if(tamanho < 0) return -1;
    int maior = vetor[tamanho-1];
    for(int i=0;i<tamanho;i++){
        if(vetor[i] > vetor[maior]) maior = i;
    }
    return maior;
}

int main(){
    int x[4] = {1,23,431,123};
    printf("%d\n",maior(x,4));
    return 0;
}