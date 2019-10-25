#include <stdio.h>
#include "igor.h"

int main(){
    Fila* vetor;
    Tipo saida;
    vetor = fila_criar();
    fila_inserir(vetor,1);
    fila_imprimir(vetor);
    fila_inserir(vetor,2);
    fila_imprimir(vetor);
    fila_inserir(vetor,3);
    fila_imprimir(vetor);
    fila_inserir(vetor,4);
    fila_imprimir(vetor);
    fila_inserir(vetor,5);
    fila_imprimir(vetor);
    fila_inserir(vetor,6);
    fila_imprimir(vetor);
    saida = *fila_remover1(vetor);
    saida = *fila_remover1(vetor);
    saida = *fila_remover1(vetor);
    saida = *fila_remover1(vetor);
    saida = *fila_remover1(vetor);

    printf("%d\n",saida);
    fila_imprimir(vetor);
}