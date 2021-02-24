#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero;
    do{
        printf("Difite um numero positivo para realizar sua tabuada:\n");
        scanf("%d",&numero);
    } while (numero<0);
    for (int i = 1; i <= 10; i++){
        int resultado = numero*i;
        printf("%d X %d = %d\n",numero,i,resultado);
    }
    return 0;
}
