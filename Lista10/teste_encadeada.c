#include<stdio.h>
#include "Pilha_encadeada.h"



void teste1(){
    Pilha* p = pilha_criar();
    printf("%d\n",pilha_push(p, 10));
    printf("%d\n",pilha_push(p, 20));
    printf("%d\n",pilha_push(p, 30));
    pilha_imprimir(p); // [30,20,10] (topo -> base)
    p = pilha_inverter(p);
    pilha_imprimir(p); // [10,20,30] (topo -> base)
    p = pilha_inverter(p);
    pilha_imprimir(p); // [10,20,30] (topo -> base)
}

int main(){
    teste1();
}