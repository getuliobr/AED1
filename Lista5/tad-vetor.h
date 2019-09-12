#include <stdlib.h>
#define TAMANHO_INICIAL 5

typedef struct{
    int* vetor;
    int size;   //tamanho total do vetor
    int length; //qntde de elementos usados
} Vetor;

typedef int DataType;

typedef enum {false, true} Boolean;

Vetor* vetor_new();
void vetor_free(Vetor* v);
void vetor_print(Vetor* m);
Boolean vetor_insert(Vetor* v, DataType element, int index);
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