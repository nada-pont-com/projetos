#include <stdio.h>
#include <stdlib.h>

int main(){
    int num[2],resultado = 0;
    for (int i = 0; i < 2; i++){
        do{
            printf("Digite o %d numero positivo:\n",i+1);
            scanf("%d",&num[i]);
        } while (num[i]<0);
    }
    for (int i = 0; i < num[0]; i++){
        resultado = resultado + num[1];
    }
    printf("Resultado: %d\n",resultado);
    return 0;
}
