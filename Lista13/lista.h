#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;


typedef struct no{
    Tipo dado;
    struct no* prox;
    struct no* ant;
}No;

typedef struct{
    No* primeiro;
    No* ultimo;
    int qtde;
}Lista;


Lista* lista_criar(); //pronto
No* no_criar(Tipo dado, No* ant, No* prox); //pronto
void lista_destruir(Lista* l); //pronto

No* achar_posicao(Lista* l, int posicao); //pronto

void lista_inserir(Lista* l, Tipo elemento, int posicao); //pronto
void lista_inserir_fim(Lista* l, Tipo elemento); //pronto

int* lista_remover1(Lista* l, int posicao); //pronto
Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco); //pronto
Boolean lista_remover_elemento(Lista* l, Tipo elemento); //pronto


Boolean lista_buscar(Lista* l, int posicao, int* endereco); //pronto
Boolean lista_contem(Lista* l, Tipo elemento); //pronto
int lista_posicao(Lista* l, Tipo elemento); //pronto

int lista_tamanho(Lista* l);
void lista_imprimir(Lista* l); //pronto

Lista* lista_criar(){
    Lista* out = (Lista *)malloc(sizeof(Lista));
    out->primeiro = NULL;
    out->ultimo = NULL;
    out->qtde = 0;
    return out;
}

void lista_destruir(Lista* l){
    No* aux = l->primeiro;
    No* antigo;
    while(aux != NULL){
        if(aux->ant != NULL)
            free(aux->ant);
        aux = aux->prox;
    }
    free(l);
}

No* no_criar(Tipo dado, No* ant, No* prox){
    No* out = (No*)malloc(sizeof(No));
    out->dado = dado;
    out->ant = ant;
    out->prox = prox;
    return out;
}

No* achar_posicao(Lista* l, int posicao){
    No* aux = l->primeiro;
    if(posicao <= (l->qtde/2)){
        aux = l->primeiro;
        for(int i=0;i<posicao;i++) aux = aux->prox;
    }else{
        aux = l->ultimo;
        for(int i=l->qtde-1;i>posicao;i--) aux = aux->ant;
    }
    return aux;
}

void inserirElemento(Lista* l, int posicao, Tipo elemento){
    No* aux = achar_posicao(l,posicao);
    No* add = no_criar(elemento,aux->ant,aux);
    aux->ant = aux->ant->prox = add;
}

void lista_inserir(Lista* l, Tipo elemento, int posicao){
    if(posicao<0 || posicao>l->qtde || l==NULL) return;

    if(l->qtde==0)              l->primeiro = l->ultimo = no_criar(elemento,NULL,NULL);
    else if(posicao == 0)       l->primeiro = l->primeiro->ant = no_criar(elemento,NULL,l->primeiro);
    else if(posicao == l->qtde) l->ultimo = l->ultimo->prox = no_criar(elemento,l->ultimo,NULL);
    else                        inserirElemento(l, posicao, elemento);

    l->qtde++;
}

void lista_inserir_fim(Lista* l, Tipo elemento){
    lista_inserir(l, elemento, l->qtde);
}

void lista_imprimir(Lista* l){
    No* aux = l->primeiro;
    printf("[");
    for(int i=0;i<l->qtde;i++){
        printf("%d",aux->dado);
        if(i != l->qtde - 1) printf(",");
        aux = aux->prox;
    }
    printf("]\n");
}

int* lista_remover1(Lista* l, int posicao){
    if(posicao<0 || posicao>(l->qtde-1) || l==NULL || l->qtde == 0) return NULL;
    No* aux = achar_posicao(l, posicao);
    int* saida = (int*)malloc(sizeof(int));
    *saida = aux->dado;
    if(l->qtde == 1) l->ultimo = l->primeiro = NULL;
    if(posicao != 0 && posicao != l->qtde-1){
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }
    if(posicao==0){
        l->primeiro = aux->prox;
        aux->prox->ant = NULL;
    }
    if(posicao==l->qtde-1){
        l->ultimo = aux->ant;
        aux->ant->prox = NULL;
    }
    free(aux);
    l->qtde--;
    return saida;
}

Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco){
    if(posicao<0 || posicao>(l->qtde-1) || l==NULL || l->qtde == 0) return false;
    No* aux = achar_posicao(l, posicao);
    *endereco = aux->dado;
    if(l->qtde == 1) l->ultimo = l->primeiro = NULL;
    if(posicao != 0 && posicao != l->qtde-1){
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }
    if(posicao==0){
        l->primeiro = aux->prox;
        aux->prox->ant = NULL;
    }
    if(posicao==l->qtde-1){
        l->ultimo = aux->ant;
        aux->ant->prox = NULL;
    }
    free(aux);
    l->qtde--;
    return true;
}


Boolean lista_remover_elemento(Lista* l, Tipo elemento){
    No* aux = l->primeiro;
    for(int i=0;i<l->qtde-1;i++){
        if(elemento == aux->dado){
            lista_remover1(l,i);
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

Boolean lista_buscar(Lista* l, int posicao, int* endereco){
    if(posicao<0 || posicao>(l->qtde-1) || l==NULL || l->qtde == 0) return false;
    *endereco = (achar_posicao(l,posicao))->dado;
    return true;
}

Boolean lista_contem(Lista* l, Tipo elemento){
    No* aux = l->primeiro;
    for(int i=0;i<l->qtde-1;i++){
        if(elemento == aux->dado)
            return true;
        aux = aux->prox;
    }
    return false;
}

int lista_posicao(Lista* l, Tipo elemento){
    No* aux = l->primeiro;
    for(int i=0;i<l->qtde-1;i++){
        if(elemento == aux->dado)
            return i;
        aux = aux->prox;
    }
    return -1;
}

int lista_tamanho(Lista* l){
    return l->qtde;
}