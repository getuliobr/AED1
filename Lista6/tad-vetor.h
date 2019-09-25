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
void usedSpace(Vetor* v);
void vetor_free(Vetor* v); //pronto
void vetor_print(Vetor* m); //pronto
void vetor_doubleSize(Vetor* v);//pronto
Boolean vetor_insert(Vetor* v, DataType element, int index);//pronto
Boolean vetor_add(Vetor* v, DataType element);//pronto
DataType vetor_remove1(Vetor* v, int index);//pronto
Boolean vetor_remove2(Vetor* v, int index, DataType* ptr);//pronto
DataType vetor_shift1(Vetor* v);//pronto
Boolean vetor_shift2(Vetor* v, DataType* ptr);//pronto
DataType vetor_get1(Vetor* v, int index);//pronto
Boolean vetor_get2(Vetor* v, int index, DataType *ptr);//pronto
DataType* vetor_get3(Vetor* v, int index);//pronto
Boolean vetor_set(Vetor* v, int index, DataType valor);//pronto
void vetor_map(Vetor* v, void (*funcao)(DataType*));//pronto
Vetor* vetor_sub1(Vetor* v, int index);//pronto
Vetor* vetor_sub2(Vetor* v, int start, int end);//pronto
int vetor_size(Vetor* v);//pronto
Vetor* vetor_filter(Vetor* v, Boolean (*funcao)(DataType*));//pronto
void vetor_sort(Vetor* v);
void vetor_genericSort(Vetor* v, int (*pfuncao)(DataType* a, DataType* b));

Vetor* vetor_new(){
    Vetor *vetor = (Vetor *)malloc(sizeof(Vetor));
    vetor->vetor = (DataType *)calloc(TAMANHO_INICIAL,sizeof(DataType));
    vetor->length = 0;
    vetor->size = TAMANHO_INICIAL;
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
    int index = v->length++;
    if(index==(v->size-1)) vetor_doubleSize(v);
    v->vetor[index] = element;
    return true;
}

void usedSpace(Vetor* v){
    if(v->length < v->size/4){
        if(v->size > TAMANHO_INICIAL){
            int size = v->size/2;
            v->size = size;
        }
        DataType* vetorAux = (DataType *)calloc(v->size,sizeof(DataType)); 
        for(int i=0;i<v->length;i++)
            vetorAux[i] = v->vetor[i];
        free(v->vetor);
        v->vetor = vetorAux;
    }
}

DataType vetor_remove1(Vetor* v, int index){
    if(index < 0 || index >= v->length || v->length == 0) return -9995;
    DataType ptr = v->vetor[index];
    v->length--;
    for(int i=index;i<v->length;i++){
        v->vetor[i] = v->vetor[i + 1];
    }
    usedSpace(v);
    return ptr;
}

Boolean vetor_remove2(Vetor* v, int index, DataType* ptr){
    if(index < 0 || index > v->length || v->length == 0) return false;
    *ptr = v->vetor[index];
    v->length--;
    for(int i=index;i<v->length;i++){
        v->vetor[i] = v->vetor[i + 1];
    }
    usedSpace(v);
    return true;
}

DataType vetor_shift1(Vetor* v){
    int index = 0;
    if(v->length == 0) return -9995;
    DataType ptr = v->vetor[index];
    v->length--;
    for(int i=index;i<v->length;i++){
        v->vetor[i] = v->vetor[i + 1];
    }
    usedSpace(v);
    return ptr;
}

Boolean vetor_shift2(Vetor* v, DataType* ptr){
    int index = 0;
    if(v->length == 0) return false;
    *ptr = v->vetor[index];
    v->length--;
    for(int i=index;i<v->length;i++){
        v->vetor[i] = v->vetor[i + 1];
    }
    usedSpace(v);
    return true;
}

DataType vetor_get1(Vetor* v, int index){
    if(index < 0 || index > v->length || v->length == 0) return -9995;
    return v->vetor[index];
}

Boolean vetor_get2(Vetor* v, int index, DataType *ptr){
    if(index < 0 || index > v->length || v->length == 0) return false;
    *ptr = v->vetor[index];
    return true;
}

DataType* vetor_get3(Vetor* v, int index){
    DataType* saida;
    if(index < 0 || index > v->length || v->length == 0) saida = &v->vetor[v->length-1];
    else saida = &v->vetor[index];
    return saida;
}

Boolean vetor_set(Vetor* v, int index, DataType valor){
    if(index < 0 || index > v->length || v->length == 0) return false;
    v->vetor[index] = valor;
    return true;
}

void vetor_map(Vetor* v, void (*funcao)(DataType*)){
    for(int i=0;i<v->length;i++){
        funcao(&v->vetor[i]);
    }
}

Vetor* vetor_sub1(Vetor* v, int index){
    if(index<0) index += v->length;
    Vetor* saida = vetor_new();
    for(int i=index;i<v->length && index != (v->length-1);i++){
        vetor_add(saida,v->vetor[i]);
    }
    return saida;
}

Vetor* vetor_sub2(Vetor* v, int start, int end){
    if(start<0) start += v->length;
    if(end<0) end += v->length;
    Vetor* saida = vetor_new();
    for(int i=start;i<=end && start != (v->length-1);i++){
        vetor_add(saida,v->vetor[i]);
    }
    return saida;
}

int vetor_size(Vetor* v){
    return v->size;
}

Vetor* vetor_filter(Vetor* v, Boolean (*funcao)(DataType*)){
    Vetor* out = vetor_new();
    for(int i=0;i<v->length;i++){
        if(funcao(&(v->vetor[i]))) vetor_add(out,v->vetor[i]);
    }
    return out;
}

void vetor_sort(Vetor* v){
    for(int fim=v->length-1;fim>0;fim--){
        Boolean troca = false;
        for(int i=0;i<fim;i++){
            if(v->vetor[i] > v->vetor[i+1]){
                DataType aux = v->vetor[i];
                v->vetor[i] = v->vetor[i+1];
                v->vetor[i+1] = aux;
                troca = true;
            }
        }
        if(!troca) return;
    }
}