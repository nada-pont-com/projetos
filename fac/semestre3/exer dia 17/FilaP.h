#define ERRO_FILA_VAZIA -1
#define ERRO_FILA_CHEIA -2
#include "pilha.h"

typedef struct{
	Pilha *p1;
	Pilha *p2;
	int tamInfo,capacidade,n,inicio;
}Fila;

void inicializa_fila( Fila *p, int c , int t);
void desaloca_fila( Fila *p );
int fila_vazia( Fila f );
int fila_cheia( Fila f );
int inserir( Fila *p, void *info);
int remover( Fila *p, void *info);
void troca(Pilha *p1,Pilha *p2,int n,void * aux);
void mostra_fila( Fila f, void (*mostra) (void*));

