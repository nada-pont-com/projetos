#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaP.h"

void inicializa_fila( Fila *p, int c, int t ){
	// p->dados = malloc( sizeof(void *) * c );
	p->p1 = malloc( sizeof(Pilha*) );
	p->p2 = malloc( sizeof(Pilha*) );
	inicializa_pilha(p->p1,c,t);
	inicializa_pilha(p->p2,c,t);
	p->capacidade = c;
	p->inicio = p->n = 0;
	p->tamInfo = t;
}

void desaloca_fila( Fila *p ){
	desaloca_pilha(p->p1);
	desaloca_pilha(p->p2);
}

int fila_vazia( Fila f ){
	return pilha_vazia(*f.p1); // f.n == 0;
}

int fila_cheia( Fila f ){
	return pilha_cheia(*f.p1); //f.n == f.capacidade;
}

int inserir( Fila *p, void *info ){
	if( fila_cheia( *p ) )
		return ERRO_FILA_CHEIA;
	
	// int fim = ( p->inicio + p->n ) % p->capacidade;
	// p->dados[fim] = malloc(p->tamInfo);
	// memcpy(p->dados[fim],info,p->tamInfo);
	// p->dados[fim] = info;
	empilha(p->p1,info);
	p->n++;
	return 1; // Sucesso
}

int remover( Fila *p, void *info){
	if( fila_vazia( *p ) )
		return ERRO_FILA_VAZIA;
	
	// *info = p->dados[p->inicio];
	void * aux = malloc(p->tamInfo);
	troca(p->p1,p->p2,p->n,aux);	
	
	desempilha(p->p2,aux);
	memcpy(info,aux,p->tamInfo);

	troca(p->p2,p->p1,p->n-1,aux);

	free(aux);
	p->n--;

	return 1; // Sucesso
}

void troca(Pilha *p1,Pilha *p2,int n,void * aux){
	for (int i = 0; i <= n; i++){
		desempilha(p1,aux);
		empilha(p2,aux);
	}
}

void mostra_fila( Fila f, void (*mostra) (void*) ){
	if( fila_vazia( f ) )
		printf("\nFila vazia!\n");
	else{
		printf("\nDados da Fila:\n");
		int i;
		void *aux = malloc(f.tamInfo);
		troca(f.p1,f.p2,f.n,aux);
		for( i = 0; i < f.n ; i++){
			printf("[%d] ", i);
			desempilha(f.p2,aux);
			mostra(aux);
			empilha(f.p1,aux);
			// mostra(f.dados[i]);
			printf("\n");
		}
		printf("\n");
	}
}