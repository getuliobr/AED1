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
    vetor_add(v,0);
    vetor_add(v,6);
    vetor_add(v,1);
    vetor_add(v,5);
    vetor_add(v,3);
    vetor_add(v,8);
    vetor_add(v,4);
    vetor_add(v,2);
    vetor_print(v);
    vetor_sort(v);
    vetor_print(v);

    Vetor *teste = vetor_filter(v,ehPar);
    vetor_print(teste);
    vetor_free(teste);
    
    teste = vetor_filter(v,ehImpar);
    vetor_print(teste);    

    vetor_free(teste);
    vetor_free(v);
}