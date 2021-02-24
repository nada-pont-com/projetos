#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float* vetor(float media,float* a,int n,int cont);
int media(float media,float* a,int n);

int main(int argc, char const *argv[]){


	int b = 0;
	printf("Insira o tamanho do vetor.\n" );
	scanf("%d",&b);
	float * a = calloc(b,sizeof(float));
	float total = 0;
	for (int i = 0; i < b; ++i){
		printf("Insira um valor:\n" );
		scanf("%f",a+i);
		total+=*(a+i);
	}
	float med = total/b;
	
	int cont = media(med,a,b);

	float* c = vetor(med,a,b,cont); 

	for (int i = 0; i < cont; ++i){
		printf("c = %f\n",*(c+i));
	}
}

int media(float med,float* a,int n){
	int cont = 0;
	for (int i = 0; i < n; ++i){
		if(med<*(a+i)){
			cont++;
		}
	}
	return cont;
}

float* vetor(float media2,float* a,int n,int cont){
	float* vet = calloc(cont,sizeof(float));
	cont = 0;
	for (int i = 0; i < n; ++i){
		if(media2<*(a+i)){
			*(vet+cont) = *(a+i);
			cont++;
		}	
	}
	return vet;
}

