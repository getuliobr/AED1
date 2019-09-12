#include <stdio.h>

char qualConceito(float nota, char* saida){
    char conceito;
    if(nota < 0 || nota > 10) return -1;
    if(nota<6) conceito = 'I';
    else if(nota<7) conceito = 'C';
    else if(nota<9) conceito = 'B';
    else conceito = 'A';
    *saida = conceito;
    return 0;
}

int main(){
    float nota = 9.9;
    char conceito;
    qualConceito(nota,&conceito);
    printf("%c\n",conceito);
    return 0;
}