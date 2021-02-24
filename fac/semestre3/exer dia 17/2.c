#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Fila.h"

void inverteFila(Fila*);

int main(int argc, char const *argv[]){
	Fila fila;
	inicializa_fila(&fila,10);
	for (int i = 0; i < fila.capacidade; ++i){
		inserir(&fila,i+1);
	}
	mostra_fila(fila);
	inverteFila(&fila);
	mostra_fila(fila);

	return 0;
}