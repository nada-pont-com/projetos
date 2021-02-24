#include <stdio.h>
#include <stdlib.h>

int main(){
/*  Ex4*/
    int lados[3], exist[3];
    int i,valida = 1;
    for(i=0;i<3;i++){
		printf("Digite o lado%d do triangulo",i+1);
		scanf("%d",&lados[i]);
    }
    exist[0] = lados[1]-lados[2];
    exist[1] = lados[0];
    exist[2] = lados[2]+lados[1];
    if(exist[0]<0)
		exist[0] *= -1;
    if(exist[0]<exist[1]){
		if(!(exist[1]<exist[2]))
	    	valida = 0;
	}else
		valida = 0;
	if (valida){
		if(lados[1]==lados[2]){
			if (lados[2]==lados[3]){
				printf("O triangulo e equilatero.");
			}else{
				printf("O triangulo e isosceles.");
			}
		}else if(lados[3]==lados[2]){
			printf("O tringulo e isosceles.");
		}else{
			printf("O triangulo e escaleno.");
		}
	}else{
		printf("O tringulo não existe.");
	}
}
