#include <stdio.h>
#include <stdlib.h>

int primo(int,int);

int main(){
    int num,valida = 1;
    printf("Digite um numero para validar se ele e primo:\n");
    scanf("%d",&num);
    if(num<2){
        printf("nao e primo");
    }else{

        valida = primo(num,2);

        if(valida){
            printf("primo");
        }else{
            printf("nao");
        }
    }
    return 0;
}


int primo(int numero,int n){
    int valor = numero%n;
    if(n==(numero/2)){
        return 1;
    }
    if(valor==0){
        return 0;
    }    
    primo(numero,n+1);
}