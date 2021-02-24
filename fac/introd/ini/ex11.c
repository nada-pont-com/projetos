#include <stdio.h>
#include <stdlib.h>

int main(){
    int num,valida = 1;
    printf("Digite um numero para validar se ele e primo:\n");
    scanf("%d",&num);
    for (int i = 2; i < num; i++){
        int valor = num%i;
        if(valor==0 ){
            valida = 0;
            break;
        }
    }
    if(valida){
        printf("primo");
    }else
        printf("nao");
    return 0;
}
