#include <stdio.h>
#include <stdlib.h>

void inc_dec(int*,int*);

int main(int argc, char const *argv[]){
	int a = 0,b = 0;
	printf("Insira o valor de a.\n" );
	scanf("%d",&a);
	printf("Insira o valor de b.\n" );
	scanf("%d",&b);

	inc_dec(&a,&b);

	printf("a = %d\nb = %d", a,b);
	return 0;
}

void inc_dec(int *a, int *b){
	(*a)++;
	(*b)--;
}