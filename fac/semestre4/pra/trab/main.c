#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arvore-rubro-negra.h"
#include "avl_arvore.h"
// #include "arvore-avl.h"
#include "arvore-b.h"

int geraNumRand(int*,int);

int main() {
	FILE* b_ordenado = fopen("b_ordenado.txt","w");
	FILE* avl_ordenado = fopen("avl_ordenado.txt","w");
	FILE* rubro_ng_ordenado = fopen("rubro_negra_ordenado.txt","w");

	FILE* b_rand = fopen("b_rand.txt","w");
	FILE* avl_rand = fopen("avl_rand.txt","w");
	FILE* rubro_ng_rand = fopen("rubro_negra_rand.txt","w");

	ArvoreB* arvoreB = criaArvoreB(4);
	Arvore* arvoreRubro = criar();
	ArvoreAvl arvoreAvl = criaArvoreAvl();

	ArvoreB** arvoresB = malloc(sizeof(ArvoreB*)*10);
	
	// ArvoreAvl** ar voresAvl = malloc(sizeof(ArvoreAvl*)*10);
	ArvoreAvl* arvoresAvl = malloc(sizeof(ArvoreAvl)*10);

	Arvore** arvoresRub = malloc(sizeof(Arvore*)*10);
	int** nrValores = calloc(10,sizeof(int*));


	for (int i = 0; i < 10; i++){
		arvoresAvl[i] = criaArvoreAvl();
		arvoresB[i] = criaArvoreB(4);
		arvoresRub[i] = criar();
		nrValores[i] = calloc(1000,sizeof(int));
	}

	int nrB_ord = 0,nrAvl_ord = 0,nrRub_ord = 0;

	int* nrB_rand = calloc(10,sizeof(int));
	int* nrAvl_rand = calloc(10,sizeof(int));
	int* nrRub_rand = calloc(10,sizeof(int));


	srand(time(NULL));

	for (int i = 0; i < 1000; i++){
		adicionaChave(arvoreB,i);
		nrB_ord += nrB;
		adicionarRubNg(arvoreRubro,i);
		nrRub_ord += nrRub;
		insere(arvoreAvl,i);
		nrAvl_ord += nrAvl;

		fprintf(b_ordenado,"numero: %d - trabalho: %d\n",i,nrB_ord);
		fprintf(avl_ordenado,"numero: %d - trabalho: %d\n",i,nrAvl_ord);
		fprintf(rubro_ng_ordenado,"numero: %d - trabalho: %d\n",i,nrRub_ord);
		nrB   = 0;
		nrRub = 0;
		nrAvl = 0;

		for (int j = 0; j < 10; j++){
			int nr = geraNumRand(nrValores[j],i);
			nrValores[j][i] = nr;
			adicionaChave(arvoresB[j],nr);
			nrB_rand[j] += nrB;
			adicionarRubNg(arvoresRub[j],nr);
			nrRub_rand[j] += nrRub;
			insere((arvoresAvl[j]),nr);
			nrAvl_rand[j] += nrAvl;
			
			nrB   = 0;
			nrRub = 0;
			nrAvl = 0;

			fprintf(b_rand,"numero: %d - teste:%d - trabalho: %d\n",nr,j,nrB_rand[j]);
			fprintf(rubro_ng_rand,"numero: %d - teste:%d - trabalho: %d\n",nr,j,nrRub_rand[j]);
			fprintf(avl_rand,"numero: %d - teste:%d - trabalho: %d\n",nr,j,nrAvl_rand[j]);
		}
		
	}
}

int geraNumRand(int* vls,int i){
	int vl = rand() % 10000;
	for(int j = 0;j<i;j++){
		if(vl==vls[j]){
			return geraNumRand(vls,i);
		}
	}
	return vl;
}

