#include <stdio.h>
#include <stdlib.h>

int main(){
    /*  Ex1*/
    int idade;
    printf("Digite sua idade!");
    scanf("%d",&idade);
    if(idade<18){
	    printf("Menor de idade!");
    }else{
	    printf("Maior de idade!");
    }

}