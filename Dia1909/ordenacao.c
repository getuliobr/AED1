#include <stdio.h>
#include <stdlib.h>

void printVetorGenerico(void* vetor, int tamanho,int tamanhoTipo, void (*print)(void* a)){
    printf("[");
    for(int i=0;i<tamanho;i++)
        if(i != tamanho - 1){
            print(vetor + i*tamanhoTipo);
            printf(",");
        }
        else print(vetor + i*tamanhoTipo);
    printf("]\n");
}

void printInt(void *a){
    printf("%d",*((int*)a));
}

void printChar(void *a){
    printf("%c",*((char*)a));
}

void trocaInt(void* a, void* b){
    int* x = (int*)a;
    int* y = (int*)b;
    int temp = *x;
    *x = *y;
    *y = temp;
}

void trocaChar(void* a, void* b){
    char* x = (char*)a;
    char* y = (char*)b;
    char temp = *x;
    *x = *y;
    *y = temp;
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

/**************************************
 * BUBBLE SORT GENÉRICO
 * ************************************/

void bubble_generico(void* v, int n, int tamElemento, int (*funcaoCompara)(void* a, void* b), void (*troca)(void* a, void* b)){
    int i, fim;
    for (fim = n-1; fim>0; fim--) {
        int houve_troca = 0;
        for (i=0; i<fim; i++){
            if (funcaoCompara(v + i*tamElemento, v + (i+1)*tamElemento)) {
                troca(v + i*tamElemento, v + (i+1)*tamElemento);
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

    bubble_generico(v1, 8, sizeof(int), comparaInt, trocaInt);
    printVetorGenerico(v1,8,sizeof(int),printInt);
    bubble_generico(vet_char, 5, sizeof(char), comparaChar, trocaChar);
    printVetorGenerico(vet_char,5,sizeof(char),printChar);
}