#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"

void inicializa_fila( Fila *p, int c, int t ){
	p->dados = malloc( sizeof(void *) * c );
	p->capacidade = c;
	p->inicio = p->n = 0;
	p->tamInfo = t;
}

void desaloca_fila( Fila *p ){
	if( !fila_vazia( *p ) ){
		int cont, i;
		for( cont = 0, i = p->inicio ; cont < p->n ; cont++, i = ( i + 1 ) % p->capacidade ){
			free( p->dados[i] ); // libera memória dos dados em si...
		}
	}
	free( p->dados );
}

int fila_vazia( Fila f ){
	return f.n == 0;
}

int fila_cheia( Fila f ){
	return f.n == f.capacidade;
}

int inserir( Fila *p, void *info ){
	if( fila_cheia( *p ) )
		return ERRO_FILA_CHEIA;
	
	int fim = ( p->inicio + p->n ) % p->capacidade;
	p->dados[fim] = malloc(p->tamInfo);
	memcpy(p->dados[fim],info,p->tamInfo);
	// p->dados[fim] = info;
	p->n++;
	return 1; // Sucesso
}

int remover( Fila *p, void *info){
	if( fila_vazia( *p ) )
		return ERRO_FILA_VAZIA;
	
	// *info = p->dados[p->inicio];
	memcpy(info,p->dados[p->inicio],p->tamInfo);
	p->inicio = ( p->inicio + 1 ) % p->capacidade;
	p->n--;
	return 1; // Sucesso	
}

void mostra_fila( Fila f, void (*mostra) (void*) ){
	if( fila_vazia( f ) )
		printf("\nFila vazia!\n");
	else{
		printf("\nDados da Fila:\n");
		int cont, i;
		for( cont = 0, i = f.inicio ; cont < f.n ; cont++, i = ( i + 1 ) % f.capacidade ){
			printf("[%d] ", i);
			mostra(f.dados[i]);
			printf("\n");
		}
		printf("\n");
	}
}


