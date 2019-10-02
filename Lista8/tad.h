#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char cod[6];
    char* nome;
    float* preco;
    int qtde;
    int qntdePrecos;
}Produto;

typedef struct{
    char* nome;
    Produto** produtos;
    int qtde;
    int tam;
}Empresa;

Empresa* novaEmpresa(char* nome, Produto* produto);
Produto* novoProduto(char* cod, char* desc, float preco, int qtde);
float mediaDePreco(Empresa* e);
int buscaRemoveDuplicados(Empresa* e, char* cod);

Empresa* novaEmpresa(char* nome, Produto* produto){
    Empresa* saida = (Empresa*)malloc(sizeof(Empresa));
    saida->nome = (char*)calloc((int)strlen(nome),sizeof(char));
    strcpy(saida->nome,nome);
    saida->produtos = (Produto**)calloc(5,sizeof(Produto**));
    saida->produtos[0] = produto;
    saida->qtde = 1;
    saida->tam = 5;
    return saida;
}

Produto* novoProduto(char* cod, char* desc, float preco, int qtde){
    Produto* saida = (Produto*)malloc(sizeof(Produto));
    strcpy(saida->cod,cod);
    saida->nome = (char*)calloc((int)strlen(desc),sizeof(char));
    strcpy(saida->nome,desc);
    saida->preco = (float*)calloc(1,sizeof(float));
    saida->preco[0] = preco;
    saida->qntdePrecos = 1;
    saida->qtde = qtde;
    return saida;
}

float mediaDePreco(Empresa* e){
    float saida = 0;
    int precos = 0,
        qntdePrecos = 0;
    for(int i = 0;i < e->qtde;i++){
        qntdePrecos = e->produtos[i]->qntdePrecos;
        precos+= qntdePrecos;
        for(int j=0;j<qntdePrecos;j++){
            saida += e->produtos[i]->preco[j];
        }
    }
    if(precos == 0) return 0;
    saida = saida/(float)precos;
    return saida;
}

int buscaRemoveDuplicados(Empresa* e, char* cod){
    int removidos = 0;
    int* remover = (int*)calloc(e->qtde,sizeof(int));
    int total = e->qtde;
    for(int i = 0;i < total;i++){
        if(strcmp(e->produtos[i]->cod,cod)==0){
            free(e->produtos[i]);
            remover[removidos++] = i;
        }
    }
    e->qtde = e->qtde-removidos;
    Produto* aux = (Produto*)calloc(e->qtde,sizeof(Produto));
    if(e->qtde != 0){
        for(int i = 0, j = 0;i < total;i++){
            for(int k = 0;k<removidos;k++){
                if(remover[k]==i && i!=(total-1)){
                    aux[j++] = *(e->produtos[++i]);
                    break;
                }
            }
        }
    }
    free(e->produtos);
    free(remover);
    *(e->produtos) = aux;
    return removidos;
}