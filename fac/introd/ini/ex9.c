#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    int fib = 0,aux1 = 1,aux2;
    printf("Digite um numero para a fazer a serie de fibonacci:\n");
    scanf("%d",&num);
    for (int i = 0; i < num; i++){
        aux2 = fib;
        fib = fib + aux1;
        aux1 = aux2;
    }
        printf("Fibonacci do termo %d e %d ",num,fib);
}
/*
fib = fib aux
 1  =  0 + 1
 1  =  1 + 0
 2  =  1 + 1
fib = fib aux
 3  =  2 + 1
fib = fib aux
 5  =  3 + 2
*/