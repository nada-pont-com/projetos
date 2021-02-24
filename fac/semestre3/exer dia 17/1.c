#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Fila.h"

void inverteFila(Fila*);
void mostra(void*);

int main(int argc, char const *argv[]){
	Fila fila;
	inicializa_fila(&fila,10,sizeof(int));
	for (int i = 0; i < fila.capacidade; ++i){
		inserir(&fila,&i);
	}
	mostra_fila(fila,mostra);
	inverteFila(&fila);
	mostra_fila(fila,mostra);

	return 0;
}

void mostra(void *i){
	int *v = i;
	printf("%d", *v);
}

void inverteFila(Fila *fila){
	int aux;
	Pilha pilha;
	int n = fila->n;
	inicializa_pilha(&pilha,n);

	for (int i = 0; i < n; ++i){
		remover(fila,&aux);
		empilha(&pilha,aux);
	}
	for(int i = 0; i < n; ++i){
		desempilha(&pilha,&aux);
		inserir(fila,&aux);
	}
}