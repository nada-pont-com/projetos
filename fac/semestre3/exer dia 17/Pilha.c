#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

void inicializa_pilha( Pilha *p, int c,int t ){
	p->dados = malloc( sizeof(void *) * c );
	p->capacidade = c;
	p->topo = -1;
	p->tamInfo = t;
}

int pilha_vazia( Pilha p ){
	return p.topo == -1;
}

int pilha_cheia( Pilha p ){
	return p.topo == p.capacidade - 1;
}

int empilha( Pilha *p, void* info ){
	if( pilha_cheia( *p ) )
		return ERRO_PILHA_CHEIA;
	
	p->topo++;
	p->dados[p->topo] = malloc(p->tamInfo);
	memcpy(p->dados[p->topo],info,p->tamInfo);

	return 1; // Sucesso	
}

int desempilha( Pilha *p, void *info ){
	if( pilha_vazia( *p ) )
		return ERRO_PILHA_VAZIA;
	
	memcpy(info,p->dados[p->topo],p->tamInfo);
	free(p->dados[p->topo]);
	// *info = p->dados[p->topo];
	p->topo--;
	return 1; // Sucesso
}

int le_topo( Pilha p, void *info ){
	if( pilha_vazia( p ) )
		return ERRO_PILHA_VAZIA;
	
	memcpy(info,p.dados[p.topo],p.tamInfo);
		
	// *info = p.dados[p.topo];
	return 1; // Sucesso
}

/*void mostra_pilha( Pilha p ){
	if( pilha_vazia( p ) )
		printf("Pilha vazia!\n\n");
	else{
		int i;
		printf("Dados da pilha:\n");
		for( i = 0; i <= p.topo ; i++ )
			printf("%d\n", p.dados[i]);
		printf("\n");
	}
}*/

void mostra_pilha( Pilha p, void (*mostra) (void*)  ){
	if( pilha_vazia( p ) )
		printf("Pilha vazia!\n\n");
	else{
		int i;
		printf("Dados da pilha:\n");
		for( i = 0; i <= p.topo ; i++ )
			mostra(p.dados[i]);
			// printf("%c\n", p.dados[i]);
		printf("\n");
	}
}

void desaloca_pilha( Pilha *p ){
	for (int i = 0; i <= p->topo; i++){
		free(p->dados[i]);	
	}
	free( p->dados );
}