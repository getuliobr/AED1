#include "matriz.h"

int main(){
    Matriz* m = matriz_criar(4,4);
    for(int i=0;i<4;i++){
        matriz_atribuir(m,2,i,1+5*i);
        for(int j=0;j<4;j++){
            printf("%d\n",matriz_acessar(m,2,j));
        }
        printf("---------------------------------------\n");
    }

    matriz_atribuir(m,1,1,5);

    matriz_imprimir(m);
    matriz_desalocar(m);
}