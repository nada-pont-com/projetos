#include <stdio.h>
#include <stdlib.h>

void max_matriz(float (*)[4],int *,float *,int *);

int main(int argc, char const *argv[]){
	int l = 0,c = 0;

	float matriz[3][4],max = 0;

	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 4; ++j){
			printf("Insira o valor da matriz[%d][%d]:\n",i ,j);
			scanf("%f",&matriz[i][j]);
		}
	}
	
	max_matriz(matriz,&l,&max,&c);

	printf("max = %.2f\nlinha: %d coluna; %d",max,l,c);
}

void max_matriz(float (*matriz)[4],int *linha,float *max, int * coluna){
	*max = matriz[0][0];
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 4; ++j){
			if(*max<matriz[i][j]){
				*max = matriz[i][j];
				*linha = i;
				*coluna = j;
			}
		}
	}
}