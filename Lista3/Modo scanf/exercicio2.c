#include <stdio.h>

void inverso(int *entrada){
    int u = *entrada%10;
    int saida = u;
    if(*entrada>=10){
        int d = (*entrada%100 - *entrada%10)/10;
        saida = u*10+d;
        if(*entrada>=100){
            int c = (*entrada%1000 - *entrada%100)/100;
            saida = u*100+d*10+c;
            if(*entrada>=1000){
                int m = (*entrada%10000 - *entrada%1000)/1000;
                saida = u*1000+d*100+c*10+m;
            }
        }
    }
    *entrada = saida;
}

int main(){
    int reverter = 1337;
    inverso(&reverter);
    printf("%d\n",reverter);
}