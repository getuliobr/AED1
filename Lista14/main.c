#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    int* saida;
    Lista* teste = lista_criar();
    lista_inserir(teste,6,0);
    lista_inserir(teste,5,0);
    lista_inserir(teste,4,0);
    lista_inserir(teste,3,0);
    lista_inserir(teste,2,0);
    lista_inserir(teste,1,0);
    lista_inserir(teste,7,5);


    //lista_inserir(teste,8,4);
    lista_imprimir(teste);
}