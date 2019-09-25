#include <stdio.h>
#include "tad-vetor.h"

void timesTwo(DataType* input){
    *input *= 2;
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
    vetor_add(v,1);
    vetor_add(v,2);
    vetor_add(v,3);
    vetor_add(v,4);
    vetor_add(v,5);
    vetor_add(v,6);
    vetor_add(v,7);
    vetor_add(v,8);
    vetor_print(v);
    printf("%d\n",vetor_remove1(v,0));
    printf("%d\n",vetor_remove1(v,0));
    printf("%d\n",vetor_shift1(v));
    printf("%d\n",vetor_shift1(v));
    DataType* teste = vetor_get3(v,-10);
    printf("%d\n",*teste);
    vetor_map(v,timesTwo);
    vetor_print(v);
    vetor_print(vetor_sub1(v,-2));
    vetor_print(vetor_sub2(v,-3,-1));
    vetor_free(v);
}