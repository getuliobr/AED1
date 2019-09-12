#include <stdio.h>

char qualConceito(float nota){
    char conceito;
    if(nota<6)
        conceito = 'I';
    else if(nota<7)
        conceito = 'C';
    else if(nota<9)
        conceito = 'B';
    else conceito = 'A';
    return conceito;
}

int main(){
    float nota = 9.9;
    printf("%c\n",qualConceito(nota));
    return 0;
}