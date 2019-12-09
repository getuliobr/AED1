#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int linha;
    int coluna;
    int valor;
    struct node* direita;
    struct node* baixo;        
    struct node* esquerda;
    struct node* cima;
    
}Node;

typedef struct{
    Node** linhas;    //ponteiro para o vetor cujas células são ponteiros de nós
    Node** colunas;    //ponteiro para o vetor cujas células são ponteiros de nós
    int numLinhas;    //Quantidade de linhas da matriz
    int numColunas;    //Quantidade de colunas da matriz
}Matriz;

Node* node_criar(int linha, int coluna, int valor);
Node** node_criarVetor(int size);
Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas);
int matriz_atribuir(Matriz* m, int linha, int coluna, int valor);
int matriz_acessar(Matriz* m, int linha, int coluna);
void matriz_imprimir(Matriz* m);
void matriz_desalocar(Matriz* m);

Node* node_criar(int linha, int coluna, int valor){
    Node* out = (Node *)malloc(sizeof(Node));
    out->valor = valor;
    out->linha = linha;
    out->coluna = coluna;
    out->esquerda = out;
    out->direita = out;
    out->cima = out;
    out->baixo = out;
    return out;
}

Node** node_criarVetor(int size){
    Node ** out = (Node **)calloc(size, sizeof(Node**));
    for(int i=0;i<size;i++) out[i] = node_criar(-1,-1,0);
    return out;
}

Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas){
    if(qtdeColunas < 0 || qtdeLinhas < 0) return NULL;
    Matriz* out = (Matriz *)malloc(sizeof(Matriz));
    out->numLinhas = qtdeLinhas;
    out->numColunas = qtdeColunas;
    out->linhas = node_criarVetor(qtdeLinhas);
    out->colunas = node_criarVetor(qtdeColunas);
    return out;
}

int matriz_atribuir(Matriz* m, int linha, int coluna, int valor){
    if(linha < 0 || coluna < 0 || m == NULL) return 0;
    Node* sentinela = m->linhas[linha];
    int aux = sentinela->valor;
    Node* no;

    if(coluna >= sentinela->esquerda->coluna){
        if(coluna == sentinela->esquerda->coluna){
            sentinela->esquerda->valor = valor;
            return 1;
        }
        no = node_criar(linha,coluna,valor);
        sentinela->esquerda = sentinela->esquerda->direita = no;
    }else{
        for(int i=0;i<aux;i++){
            if(sentinela->coluna > coluna){
                no = node_criar(linha,coluna,valor);
                sentinela->esquerda = sentinela->esquerda->direita = no;
                break;
            }
            if(sentinela->coluna == coluna){
                sentinela->valor = valor;
                return 1;
            }
            sentinela = sentinela->direita;
        }
    }
    m->linhas[linha]->valor++;
    sentinela = m->colunas[coluna];
    if(linha >= sentinela->cima->linha){
        if(linha == sentinela->cima->linha){
            sentinela->esquerda->valor = valor;
            return 1;
        }
        sentinela->cima = sentinela->cima->baixo = no;
    }else{
        for(int i=0;i<aux;i++){
            if(sentinela->linha > linha){
                sentinela->cima = sentinela->cima->baixo = no;
                break;
            }

            sentinela = sentinela->baixo;
        }
    }
    m->colunas[coluna]->valor++;

    return 1;
}

int matriz_acessar(Matriz* m, int linha, int coluna){
    if(linha < 0 || coluna < 0 || linha >= m->numLinhas || coluna >= m->colunas || m == NULL) return 0;
    Node* aux = m->linhas[linha]->direita;
    for(int i=0;i<m->linhas[linha]->valor;i++){
        if(aux->coluna == coluna) return aux->valor;
        aux = aux->direita;
    }
    return 0;
}

void matriz_imprimir(Matriz* m){
    Node* aux;
    int out;
    for(int i=0;i < m->numLinhas;i++){
        aux = m->linhas[i]->direita;
        for(int j=0;j < m->numColunas;j++){
            out = 0;
            if(aux->coluna==j){
                out = aux->valor;
                aux = aux->direita;
            }
            printf("%d\t",out);
        }
        printf("\n");
    }
}

void matriz_desalocar(Matriz* m){
    Node* aux;
    Node* past;
    for(int i=0;i < m->numLinhas;i++){
        aux = m->linhas[i];
        for(int j=0;j < m->numColunas+1;j++){
            past = aux;
            aux = aux->direita;
            free(past);
        }
    }
    free(m->colunas);
    free(m->linhas);
    free(m);
}