#include <stdio.h>
#include <stdlib.h>

int main(){
    int num = 0;
    do{
        printf("Digite um numero positivo");
        scanf("%d",&num);
    } while (num<0);
    for (int i = 0; i <= num; i+=2){
        printf("%d, ",i);
    }  
}
