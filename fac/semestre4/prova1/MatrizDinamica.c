#include "MatrizDinamica.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void inicializa_matriz( MatrizDinamica *p, int l, int c, int t ){
	p->linhas = l;
	p->colunas = c;
	p->tamInfo = t;
	
	p->dados =  malloc( sizeof(void**) * l);
	int i;//, j;
	
	for( i = 0 ; i < l ; i++ ){
		p->dados[i] = calloc( c , t);
		/*
		p->dados[i] = malloc( sizeof(int) * c );
		for( j = 0 ; j < c ; j++)
			p->dados[i][j] = 0;
		*/
	}
}

void mostra_matriz( MatrizDinamica m,void (*mostra) (void*) ){
	int i, j;
	
	printf("Dados da matriz (%dx%d):\n", m.linhas, m.colunas);
	printf("  + ");	
	for( j = 0; j < m.colunas ; j++ ){
		printf("%2d ", j+1);
	}
	printf("\n");
	for( i = 0 ; i < m.linhas; i++ ){
		printf("%3d", i+1);
		for( j = 0; j < m.colunas ; j++ ){
			mostra(m.dados[i] + (j * m.tamInfo));
			// printf("%4d ", m.dados[i][j]);
		}
		printf(" | \n");
	}
	printf("\n");
}


int posicao_valida_matriz(MatrizDinamica p,int lin, int col){
	return lin >= p.linhas || col > p.colunas || lin < 0 || col < 0 ? ERRO_COORDENADA_INVALIDA : 1;
}



