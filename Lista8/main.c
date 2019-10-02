#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tad.h"

int main(){
    float precos[5] = {12.5,74.58,48,87.8,96};
    Produto* alo = novoProduto("abcde","nao sei",12,1);
    Empresa* e = novaEmpresa("zeedy homens",alo);
    float preco = mediaDePreco(e);
    printf("%.2f\n",preco);
    int removidos = buscaRemoveDuplicados(e,"abcde");
    printf("%d\n",removidos);
    preco = mediaDePreco(e);
    printf("%.2f\n",preco);
}