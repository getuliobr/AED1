#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int qtde;
}Pilha;
/* BASE -> TOPO */
Pilha* pilha_criar();
Boolean pilha_push(Pilha* p, Tipo elemento);
Tipo* pilha_pop1(Pilha* p);
Boolean pilha_pop2(Pilha* p, Tipo* end);
void pilha_destruir(Pilha* p);
void pilha_imprimir(Pilha* p);
int pilha_posicao(Pilha* p, Tipo elemento);
int pilha_tamanho(Pilha* p);
//FUNÇÕES ADICIONAIS
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam);
Pilha* pilha_inverter(Pilha* p);
Pilha* pilha_clone(Pilha* p);

Pilha* pilha_criar(){
    Pilha* saida = (Pilha *)malloc(sizeof(Pilha));
    saida->vetor = (Tipo *)calloc(5,sizeof(Tipo));
    saida->tam = 5;
    saida->qtde= 0;
    return saida;
}

void duplicar(Pilha* p){
    Tipo* aux = (Tipo *)calloc(p->tam*2,sizeof(Tipo));
    for(int i=0;i<p->qtde;i++){
        aux[i] = p->vetor[i];
    }
    free(p->vetor);
    p->tam *= 2;
    p->vetor = aux;
}

Boolean pilha_push(Pilha* p, Tipo elemento){
    if(p->qtde==p->tam) return false;//duplicar(p);
    p->vetor[p->qtde++] = elemento;
    return true;
}

Tipo* pilha_pop1(Pilha* p){
    if(p->qtde == 0) return NULL;
    Tipo* saida = (Tipo *)malloc(sizeof(Tipo));
    *saida = p->vetor[p->qtde--];
    return saida;
}

Boolean pilha_pop2(Pilha* p, Tipo* end){
    if(p->qtde == 0) return false;
    *end = p->vetor[p->qtde--];
    return true;
}

void pilha_destruir(Pilha* p){
    free(p->vetor);
    free(p);
}

void pilha_imprimir(Pilha* p){
    printf("[");
    for(int i=0;i<p->qtde;i++){
        printf("%d",p->vetor[i]);
        if(i != p->qtde - 1) printf(",");
    }
    printf("]\n");
}

int pilha_posicao(Pilha* p, Tipo elemento){
    for(int i=0;i<p->qtde;i++)
        if(p->vetor[i]==elemento)
            return i;
    return -1;
}

int pilha_tamanho(Pilha* p){
    return p->qtde;
}

int pilha_pushAll(Pilha* p, Tipo* vetor, int tam){
    for(int i=0;i<tam;i++)
        pilha_push(p,vetor[i]);
    return tam;
}

Pilha* pilha_inverter(Pilha* p){
    Pilha* s = pilha_criar();
    for(int i=p->qtde-1;i>=0;i--)
        pilha_push(s,p->vetor[i]);
    pilha_destruir(p);
    return s;
}

Pilha* pilha_clone(Pilha* p){
    Pilha* s = pilha_criar();
    s = pilha_inverter(pilha_inverter(p));
    return s;
}