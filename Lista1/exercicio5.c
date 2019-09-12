#include <stdio.h>

int saque(int valor,int* saida){
    int cedulas[6] = {0};
    int atual=valor;
    if(valor%10==1||valor%10==3||valor<0) return 0;
    cedulas[0] = atual/100;
    atual = atual - cedulas[0]*100;
    cedulas[1] = atual/50;
    atual = atual - cedulas[1]*50;
    cedulas[2] = atual/20;
    atual = atual - cedulas[2]*20;
    cedulas[3] = atual/10;
    atual = atual - cedulas[3]*10;
    if(atual%2==1){
        cedulas[4] = atual/5;
        atual = atual - cedulas[4]*5;
        cedulas[5] = atual/2;
        atual = atual - cedulas[4]*2;
    }else{
        cedulas[5] = atual/2;
        atual = atual - cedulas[5]*2;
    }
    for(int i=0;i<6;i++) saida[i] = cedulas[i];
    return 1;
}

void printar(int *cedulas){
    printf("100 reais: %d\n",cedulas[0]);
    printf("50 reais: %d\n",cedulas[1]);
    printf("20 reais: %d\n",cedulas[2]);
    printf("10 reais: %d\n",cedulas[3]);
    printf("5 reais: %d\n",cedulas[4]);
    printf("2 reais: %d\n",cedulas[5]);
}

void main(){
    int valor[6];
    saque(558,&valor);
    printar(&valor);
    saque(132,&valor);
    printar(&valor);
}