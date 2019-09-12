#include <stdio.h>
#include "tad-vetor.h"

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
    vetor_free(v);
}