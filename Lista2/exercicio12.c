#include <stdio.h>

void main(){
    short int i1=100,i2=200,i3=300;
    short int* v2[] = {&i1,&i2,&i3};
    
    printf("%d\n",**(v2 + 0));
    printf("%d\n",**(v2 + 1));
    printf("%d\n",**(v2 + 2));
    printf("%d\n",sizeof(v2));
}
