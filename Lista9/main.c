#include <stdio.h>
#include "tad-vetor.h"



int main(){
    Vetor *teste = vetor_load("saida.bin");
    /*Vetor *teste = vetor_new();
    vetor_add(teste,5);
    vetor_add(teste,5);
    vetor_add(teste,5);
    vetor_save(teste,"saida.bin");*/
    vetor_print(teste);
    vetor_free(teste);
}