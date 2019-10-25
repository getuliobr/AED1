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

void* funcao1(void* v, int i, int tam){
    char* c = (char*) v + (tam*i);
    return (void*)c;
}

void funcao2(void *a, void *b, int tam){
    char* v1 = (char*) a;
    char* v2 = (char*) b;
    int i;
    for(i=0; i<tam; i++){
        char temp = *(v1 + i);
        *(v1+i) = *(v2+i);
        *(v2+i) = temp;
    }
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
            if (funcaoCompara(v + i*tamElemento, v + (i+1)*tamElemento)>0) {
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
    char v[8] = {'a','b','c','d','e','f','g','h'};
    void* p1 = funcao1(v,3,2);
    void* p2 = funcao1(v,0,5);
    funcao2(p1,p2,2);
    p1 = funcao1(v,5,1);
    p2 = funcao1(v,1,2);

    funcao2(p1,p2,1);
    printf("%c %c\n",*((char*) p1),*((char*) p2));

    printVetorGenerico(v,8,sizeof(char),printChar);
}
