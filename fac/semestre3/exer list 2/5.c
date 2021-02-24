#include <stdio.h>
#include <stdlib.h>

void leDados(int *,int n);
void mostraDados(int *,int n);
void uniaoDados(int *vetorA,int *vetorB,int nA,int nB,int *vetorC);

int main(){
	int s1,s2,s3;
	
	printf("Insira o tamanho do vetor 1.\n" );
	scanf("%d",&s1);

	printf("Insira o tamanho do vetor 2.\n" );
	scanf("%d",&s2);
	s3 = s1+s2;
	int* vetorA = calloc(s1,sizeof(int));
	int* vetorB = calloc(s2,sizeof(int));
	int* vetorC = calloc(s3,sizeof(int));

	printf("\n\nLeitura de dados do Vetor 1: \n\n");
	leDados(vetorA,s1);

	printf("\n\nLeitura de dados do Vetor 2: \n\n");
	leDados(vetorB,s2);

	printf("\nVetor 1: \n");
	mostraDados(vetorA,s1);	
	
	printf("\nVetor 2: \n");
	mostraDados(vetorB,s2);	



	uniaoDados(vetorA,vetorB,s1,s2,vetorC);

	printf("\nUniao: \n");
	mostraDados(vetorC,s3);	
}

void uniaoDados(int *vetorA,int *vetorB,int nA,int nB,int *vetorC){
	int cont = 0;
	for (int i = 0; i < (nA+nB); ++i){
		if(i<nA){
			vetorC[i] = vetorA[i];
		}else{
			vetorC[i] = vetorB[i-nA];
		}
	}
}


void leDados(int *vetor,int n){
	int valida = 0;
	for (int i = 0; i < n; ++i){
		do{
			valida = 0;
			printf("Digite %d valor: \n", (i+1) );
			scanf("%d",&vetor[i]);
			for (int j = 0; j < i; ++j){
				if(vetor[j]==vetor[i]){
					valida = 1;
				}
			}
		}while(valida==1);
	}
}

void mostraDados(int *vetor,int n){
    for (int i = 0; i < n; i++){
        printf("Valor na possicao %d:  %d\n",i+1,vetor[i]);
    }
}