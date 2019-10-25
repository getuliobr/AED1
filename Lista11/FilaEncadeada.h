#include <stdio.h>
#include <stdlib.h>



typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

/**
 * Registro utilizado para acomodar cada elemento da pilha (Nó).
 */
typedef struct no{
    Tipo dado;
    struct no* prox;
}No;

/**
 * Estrutura usada para representar e armazenar a FILA com alocação encadeada.
 */
typedef struct{
    No* prim;
    No* ult;
    int qtde;
}Fila;


Fila* fila_criar();//pronto
void fila_destruir(Fila* f);//pronto
Boolean fila_inserir(Fila* f, Tipo elemento);//pronto
Tipo* fila_remover1(Fila* f);//pronto
Boolean fila_remover2(Fila* f, Tipo* endereco);//pronto
Boolean fila_primeiro(Fila* f, Tipo* endereco);//pronto
int fila_tamanho(Fila* f);//pronto
int fila_contem(Fila* f, Tipo elemento);//pronto
void fila_imprimir(Fila* f);

Fila* fila_criar(){
    Fila* saida = (Fila *)malloc(sizeof(Fila));
    saida->prim = NULL;
    saida->ult = NULL;
    saida->qtde = 0;
    return saida;
}

void fila_destruir(Fila* f){
    No* temp;
    No* aux;
    temp = f->prim;
    while(temp != NULL){
        aux = temp;
        temp = temp->prox;
        free(aux);
    }
    free(f);
}

Boolean fila_inserir(Fila* f, Tipo elemento){
    No* out = (No *)malloc(sizeof(No));
    out->dado = elemento;
    out->prox = NULL;
    if(f->ult != NULL) f->ult->prox = out;
    f->ult = out;
    if(f->prim == NULL) f->prim = out;
    f->qtde++;
    return true;
}

Tipo* fila_remover1(Fila* f){
    if(f->prim == NULL) return NULL;
    Tipo* saida = (Tipo *)malloc(sizeof(Tipo));
    No* aux = f->prim;
    *saida = aux->dado;
    f->prim = aux->prox;
    free(aux);
    f->qtde--;
    return saida;
}

Boolean fila_remover2(Fila* f, Tipo* endereco){
    if(f->prim == NULL) return false;
    No* aux = f->prim;
    *endereco = aux->dado;
    f->prim = aux->prox;
    free(aux);
    f->qtde--;
    return true;
}

Boolean fila_primeiro(Fila* f, Tipo* endereco){
    if(f->prim == NULL) return false;
    *endereco = f->prim->dado;
    return false;
}

int fila_tamanho(Fila* f){
    return f->qtde;
}

int fila_contem(Fila* f, Tipo elemento){
    int i = 0;
    No* aux = f->prim;
    while(aux != NULL){
        if(aux->dado == elemento) return i;
        aux = aux->prox;
        i++;
    }
    return -1;
}

void fila_imprimir(Fila* f){
    No* aux = f->prim;
    printf("[");
    for(int i=0;i<f->qtde;i++){
        printf("%d",aux->dado);
        if(i != f->qtde - 1) printf(",");
        aux = aux->prox;
    }
    printf("]\n");
}