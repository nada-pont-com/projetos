#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arvore-rubro-negra.c"
#include "arvore-avl.c"
#include "arvore-b.c"

int geraNumRand();

int main() {
	FILE* b_ordenado = fopen("b_ordenado.txt","w");
	FILE* avl_ordenado = fopen("avl_ordenado.txt","w");
	FILE* rubro_ng_ordenado = fopen("rubro_negra_ordenado.txt","w");

	FILE* b_rand = fopen("b_rand.txt","w");
	FILE* avl_rand = fopen("avl_rand.txt","w");
	FILE* rubro_ng_rand = fopen("rubro_negra_rand.txt","w");

	ArvoreB* arvoreB = criaArvoreB(4);
	Arvore* arvoreRubro = criar();
	ArvoreAvl* arvoreAvl = criarArvoreAvl();
	ArvoreB** arvoresB = malloc(sizeof(ArvoreB*)*10);
	ArvoreAvl** arvoresAvl = malloc(sizeof(ArvoreAvl*)*10);
	Arvore** arvoresRub = malloc(sizeof(Arvore*)*10);
	for (int i = 0; i < 10; i++){
		arvoresAvl[i] = criarArvoreAvl();
		arvoresB[i] = criaArvoreB(4);
		arvoresRub[i] = criar();
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
		adicionarAvl(arvoreAvl,i);
		nrAvl_ord += nrAvl;

		fprintf(b_ordenado,"numero: %d - trabalho: %d\n",i,nrB_ord);
		fprintf(avl_ordenado,"numero: %d - trabalho: %d\n",i,nrAvl_ord);
		fprintf(rubro_ng_ordenado,"numero: %d - trabalho: %d\n",i,nrRub_ord);
		nrB   = 0;
		nrRub = 0;
		nrAvl = 0;

		for (int j = 0; j < 10; j++){
			int nr = geraNumRand();
			adicionaChave(arvoresB[j],nr);
			nrB_rand[j] += nrB;
			adicionarRubNg(arvoresRub[j],nr);
			nrRub_rand[j] += nrRub;
			adicionarAvl(arvoresAvl[j],nr);
			nrAvl_rand[j] += nrAvl;

			nrB   = 0;
			nrRub = 0;
			nrAvl = 0;

			fprintf(b_rand,"numero: %d - teste:%d - trabalho: %d\n",i,j,nrB_rand[j]);
			fprintf(rubro_ng_rand,"numero: %d - teste:%d - trabalho: %d\n",i,j,nrRub_rand[j]);
			fprintf(avl_rand,"numero: %d - teste:%d - trabalho: %d\n",i,j,nrAvl_rand[j]);
		}
	}
}

int geraNumRand(){
	return rand() % 10000;
}

