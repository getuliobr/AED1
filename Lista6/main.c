#include <stdio.h>
#include "tad-vetor.h"

void timesTwo(DataType* input){
    *input *= 2;
}

Boolean ehPar(DataType* ptr){
return (*ptr % 2 == 0 ? true : false);
}
Boolean ehImpar(DataType* ptr){
return (*ptr % 2 == 0 ? false : true);
}

int main(){
    Vetor *v = vetor_new();
    vetor_insert(v,1,0);
    vetor_insert(v,2,1);
    vetor_insert(v,3,2);
    vetor_insert(v,4,3);
    vetor_insert(v,5,4);
    vetor_insert(v,6,5);
    vetor_insert(v,7,6);
    vetor_insert(v,8,8);
    vetor_print(v);

    Vetor *teste = vetor_filter(v,ehPar);
    vetor_print(teste);
    vetor_free(teste);
    
    teste = vetor_filter(v,ehImpar);
    vetor_print(teste);    

    vetor_free(teste);
    vetor_free(v);
}