#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 5

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int inicio;
    int fim;
}Fila;


Fila* fila_criar();
void fila_destruir(Fila* f);
void duplicarTamanho(Fila* f);
void metadeTamanho(Fila* f);
Boolean fila_inserir(Fila* f, Tipo elemento);
Tipo* fila_remover1(Fila* f);
Boolean fila_remover2(Fila* f, Tipo* endereco);
Boolean fila_primeiro(Fila* f, Tipo* endereco);
int fila_tamanho(Fila* f);
int fila_contem(Fila* f, Tipo elemento);
void fila_imprimir(Fila* f);


Fila* fila_criar(){
    Fila* saida = (Fila *)malloc(sizeof(Fila));
    Tipo* vetor = (Tipo *)calloc(5,sizeof(Tipo));
    saida->tam = TAMANHO;
    saida->vetor = vetor;
    saida->inicio = 0;
    saida->fim = 0;
    return saida;
}

void fila_destruir(Fila* f){
    free(f->vetor);
    free(f);
}

void duplicarTamanho(Fila* f){
    Tipo* vetor = (Tipo *)calloc(f->tam*2,sizeof(Tipo));
    int j = 0;
    for(int i=f->inicio;i<f->fim;i++,j++)
        vetor[j] = f->vetor[i%f->tam];
    free(f->vetor);
    f->tam *= 2;
    f->vetor = vetor;
    f->inicio = 0;
    f->fim = j;
}

void metadeTamanho(Fila* f){
    if(f->tam = 5) return;
    int tam = 0, j = 0;
    if ((f->tam/2) < TAMANHO) tam = TAMANHO;
    else tam = f->tam/2;
    Tipo* vetor = (Tipo *)calloc(tam,sizeof(Tipo));
    for(int i=f->inicio;i<f->fim;i++,j++)
        vetor[j] = f->vetor[i%f->tam];
    free(f->vetor);
    f->tam = tam;
    f->vetor = vetor;
    f->inicio = 0;
    f->fim = j;
}

Boolean fila_inserir(Fila* f, Tipo elemento){
    if((f->inicio%f->tam == f->fim%f->tam) && (f->inicio != f->fim)) duplicarTamanho(f);
    int i=f->inicio;
    for(i=f->inicio;i<f->fim;i++){
        if(elemento>f->vetor[i%f->tam])
            break;
    }
    for(int j=f->fim;j>i;j--){
        f->vetor[j%f->tam] = f->vetor[(j-1)%f->tam];
    }
    f->vetor[i%f->tam] = elemento;
    f->fim++;
    return true;
}

Tipo* fila_remover1(Fila* f){
    if(f->fim == f->inicio) return NULL;
    Tipo* saida = (Tipo *)malloc(sizeof(Tipo));
    *saida = f->vetor[f->inicio++%f->tam];
    if((f->fim-f->inicio) < f->tam*0.25) metadeTamanho(f);
    return saida;
}

Boolean fila_remover2(Fila* f, Tipo* endereco){
    if(f->fim == f->inicio) return false;
    *endereco = f->vetor[f->inicio++%f->tam];
    if((f->fim-f->inicio) < f->tam*0.25) metadeTamanho(f);
    return true;
}

Boolean fila_primeiro(Fila* f, Tipo* endereco){
    if(f->fim == f->inicio) return false;
    *endereco = f->vetor[f->inicio%f->tam];
    return true;
}

int fila_tamanho(Fila* f){
    return f->fim-f->inicio;
}

int fila_contem(Fila* f, Tipo elemento){
    for(int i=f->inicio;i<f->fim;i++)
        if(f->vetor[i%f->tam] == elemento)
            return i;
    return -1;
}

void fila_imprimir(Fila* f){
    printf("[");
    for(int i=f->inicio;i<f->fim;i++)
        if(i != f->fim - 1) printf("%d,",f->vetor[i%f->tam]);
        else printf("%d",f->vetor[i%f->tam]);
    printf("]\n");
}