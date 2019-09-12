#include <stdlib.h>
#define TAMANHO_INICIAL 5

typedef struct{
    int* vetor;
    int size;   //tamanho total do vetor
    int length; //qntde de elementos usados
} Vetor;

typedef int DataType;

typedef enum {false, true} Boolean;

Vetor* vetor_new(); // pronto
void vetor_free(Vetor* v); //pronto
void vetor_print(Vetor* m); //pronto
void vetor_doubleSize(Vetor* v);//pronto
Boolean vetor_insert(Vetor* v, DataType element, int index);//pronto
Boolean vetor_add(Vetor* v, DataType element);
DataType vetor_remove1(Vetor* v, int index);
Boolean vetor_remove2(Vetor* v, int index, DataType* ptr);
DataType vetor_shift1(Vetor* v);
Boolean vetor_shift2(Vetor* v, DataType* ptr);
DataType vetor_get1(Vetor* v, int index);
Boolean vetor_get2(Vetor* v, int index, DataType *ptr);
void vetor_set(Vetor* v, int index, DataType valor);
void vetor_map(Vetor* v, void (*funcao)(DataType*));
Vetor* vetor_sub1(Vetor* v, int index);
Vetor* vetor_sub2(Vetor* v, int start, int end);

Vetor* vetor_new(){
    Vetor *vetor = (Vetor *)malloc(sizeof(Vetor));
    vetor->vetor = (DataType *)calloc(TAMANHO_INICIAL,sizeof(DataType));
    vetor->length = 0;
    vetor->size = 5;
    return vetor;
}

void vetor_free(Vetor* v){
    free(v->vetor);
    free(v);
}

void vetor_print(Vetor* m){
    printf("[");
    for(int i=0;i<m->length;i++)
        if(i != m->length - 1) printf("%d,",m->vetor[i]);
        else printf("%d",m->vetor[i]);
    printf("]\n");
}

void vetor_doubleSize(Vetor* v){
    v->size *= 2;
    DataType* vetorAux = (DataType *)calloc(v->size,sizeof(DataType)); 
    for(int i=0;i<v->length;i++)
        vetorAux[i] = v->vetor[i];
    free(v->vetor);
    v->vetor = vetorAux;
}

Boolean vetor_insert(Vetor* v, DataType element, int index){
    if(index>(v->length+1) || index<0) return false;
    if(index==(v->size-1)) vetor_doubleSize(v);
    if(index==v->length) v->length += 1;
    v->vetor[index] = element;
    return true;
}

Boolean vetor_add(Vetor* v, DataType element){
    
    return true;
}