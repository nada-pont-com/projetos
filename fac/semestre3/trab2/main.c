#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Fila.h"
#include "MatrizDinamica.h"

void mostra(void*);

int main(int argc, char const *argv[]){
	MatrizDinamica caminho;
	MatrizDinamica visao;
	inicializa_matriz(&caminho,5,5,sizeof(int));
	inicializa_matriz(&visao,5,5,sizeof(int));

	Fila fila;
	inicializa_fila(&fila,10,sizeof(Celula));

	int achou = 0;
	int aux;
	Celula c;
	Celula A;
	inserir_celula(&A,0,0,0);
	Celula B;
	inserir_celula(&A,4,4,0);
	inserir(&fila,&A);
	int dist = 0;
	while(fila_vazia(fila) && !achou){
		remover(&fila,&c);
		if(compara_celula(c,B)){
			achou = 1;
		}else{
			for (int i = -1; i <= 1; i+=2){
				get_valor_matriz(&p,c.linha)
			}
		}
	}
	return 0;
}

void mostra(void *i){
	int *v = i;
	printf("%d", *v);
}