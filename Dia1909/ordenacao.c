#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int cod;
    char nome[30];
    double preco;
}Produto;

void printVetorGenerico(void* vetor, int tamanho,int tamanhoTipo, void (*print)(void* a)){
    printf("[");
    for(int i=0;i<tamanho;i++){
        print(vetor + i*tamanhoTipo);
        if(i != tamanho - 1) printf(",");
    }
    printf("]\n");
}

void printInt(void *a){
    printf("%d",*((int*)a));
}

void printChar(void *a){
    printf("%c",*((char*)a));
}

void printProduto(void *a){
    Produto* produto = (Produto*)a;
    printf("{\"cod\":%d ,\"nome\":%s ,\"preco\":%.2f}",produto->cod,produto->nome,produto->preco);
}

/**************************************
 * FUNÇÕES GENÉRICAS DE COMPARACAO
 * ************************************/

int comparaInt(void* a, void* b){
    int* x = (int*)a; //100
    int* y = (int*)b; //104
    if(*x > *y) return 1;
    else return 0;
}
int comparaChar(void* a, void* b){
    char* x = (char*)a; //100
    char* y = (char*)b; //104
    if(*x > *y) return 1;
    else return 0;
}
int comparaProdutoPreco(void* a, void* b){
    Produto* x = (Produto*)a; //100
    Produto* y = (Produto*)b; //104
    if(x->preco > y->preco) return 1;
    else return 0;
}
/**************************************
 * BUBBLE SORT GENÉRICO
 * ************************************/

void trocaGenerica(void* a, void* b, int tamElemento){
    void* temp = malloc(tamElemento);
    memcpy(temp,a,tamElemento);
    memcpy(a,b,tamElemento);
    memcpy(b,temp,tamElemento);
    free(temp);
}

void bubble_generico(void* v, int n, int tamElemento, int (*funcaoCompara)(void* a, void* b)){
    int i, fim;
    for (fim = n-1; fim>0; fim--) {
        int houve_troca = 0;
        for (i=0; i<fim; i++){
            if (funcaoCompara(v + i*tamElemento, v + (i+1)*tamElemento)) {
                trocaGenerica(v + i*tamElemento, v + (i+1)*tamElemento,tamElemento);
                houve_troca = 1;
            }
        }
        if (houve_troca == 0) return;
    }
}

/**************************************
 * MAIN
 * ************************************/

int main(){
    int v1[8] = {25,25,37,12,57,86,33,92};
    char vet_char[5] = {'d','a', 'e', 'a', 'c'};
        Produto vp[5] = { // 300
        {5,"555",5.5},
        {1,"111",1.1},
        {4,"444",4.4},
        {3,"333",3.3},
        {2,"222",2.2}
    };

    bubble_generico(v1, 8, sizeof(int), comparaInt);
    printVetorGenerico(v1,8,sizeof(int),printInt);
    bubble_generico(vet_char, 5, sizeof(char), comparaChar);
    printVetorGenerico(vet_char,5,sizeof(char),printChar);
    bubble_generico(vp,5,sizeof(Produto),comparaProdutoPreco);
    printVetorGenerico(vp,5,sizeof(Produto),printProduto);
}
