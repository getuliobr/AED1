#include <stdio.h>

double potencia(int entrada,int elevado){
    double saida = 1;
    for(int i=0;i<elevado;i++){
        saida *= entrada;
    }
    return saida;
}

int main(){
    int entrada = 2,
        elevado = 0;
    printf("%f\n",potencia(entrada,elevado));
    return 0;
}