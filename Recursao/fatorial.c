#include <stdio.h>

int fatorial(int n){
    if (n <= 0) return 1;
    return n*fatorial(n-1);
}

int main(){
    printf("%d\n", fatorial(0));
}