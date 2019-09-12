#include <stdio.h>
#include <string.h>
int extenso(int dia, int mes, int ano, char *saida){
    char extenso[100];
    char anos[9];
    char *dias[] = {"nada","um","dois","tres","quatro","cinco","seis","sete","oito","nove","dez","onze","doze","treze","catorze","quinze","dezesseis","dezessete","dezoito","dezenove","vinte","vinte e um","vinte e dois","vinte e tres","vinte e quatro","vinte e cinco","vinte e seis","vinte e sete","vinte e oito","vinte e nove","trinta","trinta e um"};
    char *meses[] = {"nada","janeiro","fevereiro","marco","abril","maio","junho","julho","agosto","setembro","outubro","novembro","dezembro"};
    
    if(dia<1 || dia>31) return 0;
    if(mes<1 || mes>12) return 0;
    
    
    strcat(extenso,dias[dia]);
    strcat(extenso," de ");
    strcat(extenso,meses[dia]);
    strcat(extenso," de ");
    sprintf(anos, "%d", ano);
    strcat(extenso,anos);
    //printf("%s\n",extenso)
    strcpy(saida,extenso);
    return 1;
}

void main(){
    char saida[100];
    extenso(10,2,2019,&saida);
    printf("%s\n",saida);
}