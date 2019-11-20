#include <stdio.h>
#include "FilaHeap.h"
#include<time.h>


FilaPrioridade* criarAleatorio(int elementos){
    FilaPrioridade* fila = fila_criar(elementos);
    srand(time(NULL));
    for(int i=0;i<elementos;i++){
        fila_inserir(fila,(rand()*elementos)%(elementos/10));
    }
    return fila;
}
void medeTempo(int n){
    Tipo s;

    clock_t inicio, fim, total; 
    inicio = clock();
    FilaPrioridade* fila = criarAleatorio(n);
    fim = clock();
    total = fim - inicio;
    double tempoExecutado = ((double)total)/CLOCKS_PER_SEC; // in seconds
    printf("Inserir %d elementos: %f segundos\n", n, tempoExecutado);
    inicio = clock();
    for(int i=0;i<n;i++) fila_remover(fila,&s);
    fim = clock();
    total = fim - inicio;
    tempoExecutado = ((double)total)/CLOCKS_PER_SEC; // in seconds
    printf("Remover %d elementos: %f segundos\n", n, tempoExecutado);
}


int main(){
    unsigned long int n = 100000;
    int carga = 10;
    medeTempo(100);
    medeTempo(1000);
    medeTempo(10000);
    medeTempo(100000);
    medeTempo(1000000);
    medeTempo(10000000);
    medeTempo(100000000);
    
}