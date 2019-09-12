#include <stdio.h>

double potencia(int entrada,int elevado){
    double saida = 1;
    int sinal = elevado;
    elevado = (elevado>0) ? elevado : elevado*-1;
    for(int i=0;i<elevado;i++){
        saida *= entrada;
    }
    return (sinal>=0) ? saida : 1/saida;
}

int main(){
    int entrada = 2,
        elevado = 0;
    printf("%f\n",potencia(entrada,elevado));
    return 0;
}