#include <stdio.h>
#include "tad-vetor.h"

int main(){
    Vetor *v = vetor_new();
    vetor_print(v);
    vetor_free(v);
}