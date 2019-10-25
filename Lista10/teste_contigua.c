#include<stdio.h>
#include "Pilha_contigua.h"



void teste1(){
    Pilha* p = pilha_criar();
    printf("%d\n",pilha_push(p, 10));
    printf("%d\n",pilha_push(p, 20));
    printf("%d\n",pilha_push(p, 30));
    pilha_imprimir(p); // [10,20,30] (base -> topo)
    p = pilha_inverter(p);
    pilha_imprimir(p); // [30,20,10] (base -> topo)
    p = pilha_inverter(p);
    pilha_imprimir(p); // [10,20,30] (base -> topo)
}

int main(){
    teste1();
}