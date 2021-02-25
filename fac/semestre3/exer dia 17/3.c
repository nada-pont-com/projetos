#include <stdio.h>
#include <stdlib.h>
#include "FilaP.h"

void mostra(void*);
void mostra(void *i){
	int *v = i;
	printf("%d", *v);
}

int main(int argc, char const *argv[]){
	printf("ola mundo\n" );
	Fila fila;
	inicializa_fila(&fila,10,sizeof(int));
	for (int i = 0; i < fila.capacidade; ++i){
		inserir(&fila,&i);
	}
	mostra_fila(fila,mostra);
	int i;
	remover(&fila,&i);
	mostra_fila(fila,mostra);
	
	remover(&fila,&i);
	mostra_fila(fila,mostra);

	return 0;
}