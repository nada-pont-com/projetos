#include <stdio.h>
#include <stdlib.h>

void leDados(int *,int n);
void mostraDados(int *,int n);
int uniaoDados(int *vetorA,int *vetorB,int nA,int nB,int *vetorC);
int interseccaoDados(int *vetorA,int *vetorB,int nA,int nB,int *vetorC);
int diferencaDados(int *vetorA,int *vetorB,int nA,int nB,int *vetorC);

int main(){
	int s1,s2,s3;

	scanf("%d",&s1);
	scanf("%d",&s2);

	int vetorA[100];
	int vetorB[100];
	int vetorC[200];

	leDados(vetorA,s1);
	leDados(vetorB,s2);

	// mostraDados(vetorA,s1);
	// mostraDados(vetorB,s2);	
	

	s3 = uniaoDados(vetorA,vetorB,s1,s2,vetorC);

	printf("\nUniao: \n");
	mostraDados(vetorC,s3);	

	s3 = interseccaoDados(vetorA,vetorB,s1,s2,vetorC);
	
	printf("\ninterseccao: \n");
	mostraDados(vetorC,s3);

	printf("\nDiferenca: \n");
	s3 = diferencaDados(vetorA,vetorB,s1,s2,vetorC);

	mostraDados(vetorC,s3);




}

int uniaoDados(int *vetorA,int *vetorB,int nA,int nB,int *vetorC){
	int cont = 0;
	for (int i = 0; i < nA+nB; ++i){
		if(i<nA){
			vetorC[cont] = vetorA[i];
			cont++;
		}else{
			int valor = 0;
			for (int j = 0; j < nA; ++j){
				if(vetorA[j] == vetorB[i-nA]){
					valor = 1;
					break;
				}
			}
			if(valor==1){
				continue;
			}
			vetorC[cont] = vetorB[i-nA];
			cont++;
		}
	}

	return cont;
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

int interseccaoDados(int *vetorA,int *vetorB,int nA,int nB,int *vetorC){
	int cont = 0;
	for (int i = 0; i < nA; ++i){
		for (int j = 0; j < nB; ++j){
			if(vetorA[i]==vetorB[j]){
				vetorC[cont] = vetorA[i];
				cont++;
			}
		}
	}
	return cont;
}


int diferencaDados(int *vetorA,int *vetorB,int nA,int nB,int *vetorC){
	int cont = 0;
	for (int i = 0; i < nA; ++i){
		int valor = 0;
		for (int j = 0; j < nB; ++j){
			if(vetorB[j] == vetorA[i]){
				valor = 1;
				break;
			}
		}
		if(valor==1){
			continue;
		}
		vetorC[cont] = vetorA[i];
		cont++;
	}

	for (int i = 0; i < nB; ++i){
		int valor = 0;
		for (int j = 0; j < nA; ++j){
			if(vetorA[j] == vetorB[i]){
				valor = 1;
				break;
			}
		}
		if(valor==1){
			continue;
		}
		vetorC[cont] = vetorB[i];
		cont++;
	}

	return cont;

}


void mostraDados(int *vetor,int n){
    for (int i = 0; i < n; i++){
        printf("valor %d %d\n",i+1,vetor[i]);
    }
}