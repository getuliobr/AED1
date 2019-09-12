#include <stdio.h>
#include "tad-matriz2.h"

int main(){
    Matriz *matriz1 = matriz_cria(2,2);
    Matriz *matriz2 = matriz_cria(2,2);

    
    matriz_atribui(matriz1,0,0,10);
    matriz_atribui(matriz1,0,1,20);
    matriz_atribui(matriz1,1,0,30);
    matriz_atribui(matriz1,1,1,40);

    matriz_atribui(matriz2,0,0,50);
    matriz_atribui(matriz2,0,1,60);
    matriz_atribui(matriz2,1,0,70);
    matriz_atribui(matriz2,1,1,0);

    printf("%d\n",matriz_acessa1(matriz1,1,1));
    int valor;
    matriz_acessa2(matriz2,1,1,&valor);
    printf("%d\n",valor);

    matriz_imprime(matriz1);
    matriz_imprime(matriz2);

    Matriz *teste = matriz_multiplica(matriz1,matriz2);
    matriz_imprime(teste);
    matriz_destroi(teste);

    teste = matriz_transposta(matriz1);

    matriz_imprime(teste);

    matriz_destroi(matriz1);
    matriz_destroi(matriz2);
    matriz_destroi(teste);
}