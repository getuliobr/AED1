#include <stdio.h>
#include "tad-vetor.h"

int main(){
    Vetor *v = vetor_new();
    vetor_insert(v,5,1);
    vetor_print(v);
    vetor_free(v);
}