#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void organiza(int* vetor,int, int* vp,int* vn);
void mostrar(char* msg,int *vetor,int);

int main(int argc, char const *argv[]){
	int b = 0;
	printf("Insira o tamanho do vetor.\n" );
	scanf("%d",&b);

	int * a = calloc(b,sizeof(int));

	// float total = 0;
	int p = 0,n = 0;
	for (int i = 0; i < b; ++i){
		printf("Insira um valor:\n" );
		scanf("%d",a+i);
		if(*(a+i)>0)
			p++;
		else if(*(a+i)<0)
			n++;
	}
	int* vp = calloc(p,sizeof(int));
	int* vn = calloc(n,sizeof(int));

	organiza(a,b,vp,vn);
	mostrar("Vetor inicial: ",a,b);
	mostrar("Vetor positivo: ",vp,p);
	mostrar("Vetor negativo: ",vn,n);
	return 0;
}

void mostrar(char* msg,int *vetor,int n){
	printf("%s",msg);
    for (int i = 0; i < n; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n\n");
}

void organiza(int* vetor,int cont, int* vp,int* vn){
	int p = 0,n = 0;
	for (int i = 0; i < cont; ++i){
		if(*(vetor+i)>0){
			*(vp+p) = *(vetor+i);
			p++;
		}else if(*(vetor+i)<0){
			*(vn+n) = *(vetor+i);
			n++;
		}
	}
}