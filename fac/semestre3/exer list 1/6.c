#include <stdio.h>
#include <stdlib.h>

void max_vetor(float *,int,int *,float *);

int main(int argc, char const *argv[]){
	int capacidade = 0, posi = 0;

	printf("Insira o tamanho do vetor:\n");
	scanf("%d",&capacidade);
	if(capacidade<=0){
		printf("Valor invalido\n");
		return 0;
	}
	float vetor[capacidade],max = 0;

	for (int i = 0; i < capacidade; ++i){
		printf("Insira o valor do vetor:\n" );
		scanf("%f",vetor + i);
	}
	
	max_vetor(vetor,capacidade,&posi,&max);

	printf("max = %.2f\nposicao = %d",max,posi);
}

void max_vetor(float *vetor,int capacidade,int *posi,float *max){
	*max = vetor[0];
	for (int i = 0; i < capacidade; ++i){
		if(*max<vetor[i]){
			*max = vetor[i];
			*posi = i;
		}
	}
}