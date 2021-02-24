#include <stdio.h>
#include <stdlib.h>

void max_min(int *vetor,int capacidade,int *min,int *max);

int main(int argc, char const *argv[]){
	int capacidade = 0, min = 0,max = 0;

	printf("Insira o tama	nho do vetor:\n");
	scanf("%d",&capacidade);
	if(capacidade<=0){
		printf("Valor invalido\n");
		return 0;
	}
	int vetor[capacidade];

	for (int i = 0; i < capacidade; ++i){
		printf("Insira o valor do vetor:\n" );
		scanf("%d",&vetor[i]);
	}
	
	max_min(vetor,capacidade,&max,&min);

	printf("max = %d\nmin = %d",max,min);
}

void max_min(int *vetor,int capacidade,int *max,int *min){
	*min = vetor[0];
	*max = vetor[0];
	for (int i = 0; i < capacidade; ++i){
		if(*min>vetor[i])
			*min = vetor[i];
		if(*max<vetor[i])
			*max = vetor[i];
	}
}