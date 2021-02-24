#include <stdio.h>
#include <stdlib.h>

void trova_valor(float*,float*);

int main(){
	float a = 0,b = 0;
	printf("Insira o valor de a.\n" );
	scanf("%f",&a);
	printf("Insira o valor de b.\n" );
	scanf("%f",&b);


	printf("a = %.2f\nb = %.2f\n", a,b);

	trova_valor(&a,&b);

	printf("a = %.2f\nb = %.2f\n", a,b);


}

void trova_valor(float *a, float *b){
	float aux = *a;
	*a = *b;
	*b = aux;
}