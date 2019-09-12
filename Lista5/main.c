#include <stdio.h>
#include "tad-vetor.h"

int main(){
    Vetor *v = vetor_new();
    vetor_insert(v,5,0);
    vetor_insert(v,5,1);
    vetor_insert(v,5,2);
    vetor_insert(v,5,3);
    vetor_insert(v,5,4);
    vetor_insert(v,5,5);
    vetor_insert(v,5,6);
    vetor_print(v);
    vetor_free(v);
}