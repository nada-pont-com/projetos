#include <stdio.h>
#include <stdlib.h>

void calc(float,float*,float*);

int main(int argc, char const *argv[]){
	float raio = 0,perimetro = 0, area = 0;
	printf("Insira o valor do raio.\n" );
	scanf("%f",&raio);
	if(raio <= 0){
		printf("Nao e posivel calcular a area e perimetro! Raio invalido\n");
		return 0;
	}
	calc(raio,&perimetro,&area);

	printf("a = %.2f\nb = %.2f\n", perimetro,area);
}

void calc(float r,float *perimetro, float *area){
	float pi = 3.1415;
	*perimetro = 2*pi*r;
	*area = pi*r*r;
}