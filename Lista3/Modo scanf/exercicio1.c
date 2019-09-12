#include <stdio.h>

void potencia(double* entrada,int elevado){
    double saida = 1;
    int sinal = elevado;
    elevado = (elevado>0) ? elevado : elevado*-1;
    for(int i=0;i<elevado;i++){
        saida *= *entrada;
    }
    *entrada = (sinal>=0) ? saida : 1/saida;
}

int main(){
    double  entrada = 2,
            elevado = 10;
    potencia(&entrada,elevado);
    printf("%f\n",entrada);
    return 0;
}
