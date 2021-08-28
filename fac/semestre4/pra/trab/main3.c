#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arvore-rubro-negra.c"
#include "arvore-avl.c"
#include "arvore-b.c"

int geraNumRand(int*,int);

int main() {
	

	// ArvoreB* arvoreB = criaArvoreB(2);
	
	
	ArvoreAvl* arvoreAvl = criarArvoreAvl();	
	

	srand(time(NULL));
    int a[] = {20,5,25,3,12,21,28,8,13};
	for (int i = 0; i < 9; i++){
		// adicionaChave(arvoreB,i);
		// insere(arvoreAvl,i);
        adicionarAvl(arvoreAvl,a[i]);
	}
    adicionarAvl(arvoreAvl,6);
}

