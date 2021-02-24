#include <stdio.h>
#include <stdlib.h>

float* clone(float*,int);

int main(int argc, char const *argv[]){
	int b = 0;
	printf("Insira o tamanho do vetor.\n" );
	scanf("%d",&b);
	float * a = calloc(b,sizeof(float));
	for (int i = 0; i < b; ++i){
		printf("Insira um valor:\n" );
		scanf("%f",a+i);
	}

	float *c = clone(a,b);
	printf("&a = %p\n", a);
	printf("&c = %p\n", c);
	for (int i = 0; i < b; ++i){
		printf("c = %f na posi i = %d, a = %f\n",*(c+i) ,i,*(a+i));
	}
	return 0;
}

float* clone(float *a, int b){
	float *vetor = calloc(b,sizeof(float));
	for (int i = 0; i < b; ++i){
		*(vetor+i) = *(a+i);
	}
	return vetor;
}