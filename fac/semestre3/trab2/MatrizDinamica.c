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
		// p->dados[i] = malloc( sizeof(void*) * c);
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
	printf(" + ");	
	for( j = 0; j < m.colunas ; j++ ){
		printf("%2d ", j);
	}
	printf("\n");
	for( i = 0 ; i < m.linhas; i++ ){
		printf("%2d ", i);
		for( j = 0; j < m.colunas ; j++ ){
			mostra(m.dados[i] + (j * m.tamInfo));
			// printf("%4d ", m.dados[i][j]);
		}
		printf(" | \n");
	}
	printf("\n");
}

void desaloca_matriz( MatrizDinamica *p ){
	int i;
	for( i = 0 ; i < p->linhas ; i++ )
		free( p->dados[i] );
		
	free( p->dados );
}

int modifica_matriz( MatrizDinamica *p, int lin, int col, void *valor){
	if( lin >= p->linhas || col > p->colunas || lin < 0 || col < 0)
		return ERRO_COORDENADA_INVALIDA;

	memcpy( p->dados[lin] + (col * p->tamInfo),valor,p->tamInfo);

		
	// p->dados[lin][col] = valor;
	return 1; // Sucesso.
}

int posicao_valida_matriz(MatrizDinamica p,int lin, int col){
	return lin >= p.linhas || col > p.colunas || lin < 0 || col < 0 ? ERRO_COORDENADA_INVALIDA : 1;
}

int get_celula_matriz( MatrizDinamica *p, int lin, int col, Celula *c){
	if( lin >= p->linhas || col > p->colunas || lin < 0 || col < 0)
		return ERRO_COORDENADA_INVALIDA;
	get_valor_matriz(p,lin,col,&c->dist);
	// printf("testes: %d\n",c->dist);
	inserir_celula(c,lin,col, c->dist);
	return 1; // Sucesso.
}

int get_valor_matriz( MatrizDinamica *p, int lin, int col, void *info){
	if( lin >= p->linhas || col > p->colunas  || lin < 0 || col < 0)
		return ERRO_COORDENADA_INVALIDA;
	memcpy(info,p->dados[lin] + (col * p->tamInfo),p->tamInfo);

	return 1;
}


int compara_matrizes( MatrizDinamica a, MatrizDinamica b ){
	if( a.linhas != b.linhas || a.colunas != b.colunas )
		return 0; // Falso, pois t�m dimens�es diferentes.
	
	int i, j;
	for( i = 0 ; i < a.linhas; i++ )
		for( j = 0; j < a.colunas ; j++ )
			// if( a.dados[i][j] != b.dados[i][j] )
				return 0; // Falso, pois h� pelo menos um valor diferente.
	
	return 1; // Verdadeiro, pois � tudo igual (dimens�es e valores)
}


