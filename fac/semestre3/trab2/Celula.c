#include "celula.h"
#include <stdio.h>

void inserir_celula(Celula *c,int l,int col, int d){
	c->linha = l;
	c->coluna = col;
	c->dist = d;
}

int compara_celula(Celula a,Celula b){
	return (a.linha==b.linha && b.coluna==a.coluna);
}

void mostrar_celula(Celula c){
	printf("dist: %d\n", c.dist);
	printf("linha: %d\n", c.linha);
	printf("coluna: %d\n", c.coluna);
}