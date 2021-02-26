#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #include "Celula.h"
#include "Fila.h"
#include "MatrizDinamica.h"

void mostra_c(void*);
void mostra_i(void*);
void mostra_celula(void * celula);

void faz(int l,int c, int d,MatrizDinamica *,MatrizDinamica *,Fila *,Celula);
void moldaCaminho(MatrizDinamica *caminho,Celula fim,MatrizDinamica *caminhoFinal);
void posicaoValida(Celula *c,MatrizDinamica m,char*);


int main(int argc, char const *argv[]){
	MatrizDinamica caminho;
	MatrizDinamica visao;
	int aux,l = 10,c = 20;
	inicializa_matriz(&caminho,l,c,sizeof(char*));
	inicializa_matriz(&visao,l,c,sizeof(int));
	srand(time(NULL));
	// mostra_matriz(caminho,mostra_c);
	for (int i = 0; i < l; ++i){
		for (int j = 0; j < c; ++j){
			char a[5] = {' ','\0'};
			if((rand() % 100) < 20){
				strcpy(a,"[ ]");
			}
			modifica_matriz(&caminho,i,j,&a);
		}
	}
	mostra_matriz(caminho,mostra_c);

	Fila fila;
	inicializa_fila(&fila,10,sizeof(Celula));

	int achou = 0;
	Celula C;
	
	Celula A;
	Celula B;
	char a[5];
	posicaoValida(&A,caminho,a);
	posicaoValida(&B,caminho,a);
	
	compara_celula(B,A);

	posicaoValida(&B,caminho,a);

	printf("Inicio:\n");
	mostrar_celula(A);
	printf("Fim:\n");
	mostrar_celula(B);

	inserir(&fila,&A);
	int dist = 0;
	while(!fila_vazia(fila) && !achou){
		remover(&fila,&C);
		// mostra_fila(fila,mostra_celula);
		if(compara_celula(C,B)){
			achou = 1;
		}else{

			l = C.linha;
			c = C.coluna;
			dist = C.dist;
			for (int i = -1; i <= 1; i+=2){
				faz(l+i,c,dist+1,&caminho,&visao,&fila,A);
				faz(l,c+i,dist+1,&caminho,&visao,&fila,A);
			}
		}
	}

	mostra_matriz(visao,mostra_i);

	moldaCaminho(&visao,B,&caminho);

	mostra_matriz(caminho,mostra_c);


	return 0;
}

void posicaoValida(Celula *cel,MatrizDinamica m, char *aux){
	int l = (rand() % m.linhas),c = (rand() % m.colunas);
	get_valor_matriz(&m,l,c,aux);

	if(strcmp(aux," ")){
		posicaoValida(cel,m,aux);
	}else{
		inserir_celula(cel,l,c,0);
	}
}

void faz(int l,int c, int dist,MatrizDinamica *caminho,MatrizDinamica *visao,Fila *fila,Celula inicio){
	int aux,val;
	char *aux2 = malloc(sizeof(char)*3);
	get_valor_matriz(caminho,l,c,aux2);
	val = get_valor_matriz(visao,l,c,&aux);
	
	if(val==1 && !strcmp(aux2," ") && aux==0 && (l!=inicio.linha || c!=inicio.coluna)){
		modifica_matriz(visao,l,c,&dist);
		// printf("%d\n", dist);
		get_valor_matriz(visao,l,c,&dist);
		// printf("%d\n", dist);
		Celula C;
		inserir_celula(&C,l,c,dist);
		inserir(fila,&C);
	}
	free(aux2);
}

void mostra_celula(void * celula){
	Celula *v = celula;
	printf("dist: %d\n", v->dist);
	printf("linha: %d\n", v->linha);
	printf("coluna: %d\n", v->coluna);
}

void moldaCaminho(MatrizDinamica *caminho, Celula fim, MatrizDinamica *caminhoFinal){
	int dist,l = fim.linha,c = fim.coluna;
	int aux;
	Celula auxC;
	Fila fila;
	inicializa_fila(&fila,100,sizeof(Celula));

	get_celula_matriz(caminho,fim.linha,fim.coluna,&auxC);
	inserir(&fila,&auxC);
	int d_e,c_b,direcao;
	char *a = malloc(sizeof(char)*5);
	
	strcpy(a," F ");
	printf("l:%d || c:%d\n",l,c );

	modifica_matriz(caminhoFinal,l,c,a);

	while(!fila_vazia(fila)){
		// printf("\n\n");
		// mostra_fila(fila,mostra_celula);
		remover(&fila,&auxC);
		dist = auxC.dist;
		l = auxC.linha;
		c = auxC.coluna;

		d_e = 0;
		c_b = 0;
		// printf("dist: %d\n", dist);
		for (int i = -1; i <= 1; i+=2){

			aux = get_celula_matriz(caminho,l+i,c,&auxC);
			// printf("dist: %d || aux: %d\n", auxC.dist,aux);
			if(auxC.dist==(dist-1) && aux==1){
				get_valor_matriz(caminhoFinal,l+i,c,a);
				if(!(strcmp(a," "))){
					inserir(&fila,&auxC);
					c_b += !!i;
				}
			}
			
			aux = get_celula_matriz(caminho,l,c+i,&auxC);
			// printf("dist: %d || aux: %d\n", auxC.dist,aux);

			if(auxC.dist==(dist-1) && aux==1){
				get_valor_matriz(caminhoFinal,l,c+i,a);
				if(!(strcmp(a," "))){
					inserir(&fila,&auxC);
					d_e += !!i;
				}
			}
		}
		get_valor_matriz(caminhoFinal,l,c,a);
		aux = strcmp(a," F ");
		strcpy(a," a ");
		if(d_e==1 && c_b==1){
			strcpy(a," + ");
		}else if (c_b==1){
			strcpy(a," | ");
		}else{
			strcpy(a," - ");
		}
		if((d_e!=0 || c_b!=0) && aux){
			modifica_matriz(caminhoFinal,l,c,a);
		}
		// printf("%d;%d\n",d_e,c_b);
	}

	printf("l:%d || c:%d\n",l,c );
	strcpy(a," I ");
	modifica_matriz(caminhoFinal,l,c,a);

	free(a);
}


void mostra_i(void *i){
	int *v = i;
	printf("%5d", *v);
}

void mostra_c(void *i){
	char *v = i;
	printf("%3s", v);
}