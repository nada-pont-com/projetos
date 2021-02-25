#include "celula.h"

void inserir_celula(Celula *c,int l,int c, int d){
	c->linha = l;
	c->coluna = c;
	c->dist = d;
}

int compara_celula(Celula a,Celula b){
	return (a.linha==b.linha && b.coluna==a.coluna);
}