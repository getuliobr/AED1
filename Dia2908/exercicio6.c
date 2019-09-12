#include <stdio.h>
#include <stdlib.h>

char* string_copy(char *string) {
    int tamanho = 0;
    int i;
    while(string[tamanho] != '\0') ++tamanho;
    char *salvar = (char *) malloc (sizeof(char) * tamanho);
    for(i=0; i<tamanho; i++) salvar[i] = string[i];
    salvar[i] = '\0';
    return salvar;
}

int main(){
    char teste[] = "teste 123 teste";
    char *string = string_copy(teste);
    printf("%s\n",string);
}