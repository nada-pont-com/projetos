#include <stdio.h>
#include <stdlib.h>

void calc_hora(int *hora,int *min);

int main(int argc, char const *argv[]){
	int min = 0,hora = 0;
	printf("Insira o valor em minutos:\n" );
	scanf("%d",&min);
	
	calc_hora(&hora,&min);

	printf("hora: %d\nmin: %d\n", hora,min);
}

void calc_hora(int *hora,int *min){
	*hora = *min / 60;
	*min = *min % 60;
}