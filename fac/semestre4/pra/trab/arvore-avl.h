#include <stdlib.h>
#include <stdio.h>

int nrAvl = 0;

typedef struct noAvl {
    struct noAvl* pai;
    struct noAvl* esquerda;
    struct noAvl* direita;
    int valor;
} NoAvl;

typedef struct arvoreAvl {
    struct noAvl* raiz;
} ArvoreAvl;

ArvoreAvl* criarArvoreAvl();
NoAvl* adicionarAvl(ArvoreAvl* arvore, int valor);
void balanceamento(ArvoreAvl*, NoAvl*);
int altura(NoAvl*);
int fb(NoAvl*);
NoAvl* rsd(ArvoreAvl*, NoAvl*);
NoAvl* rse(ArvoreAvl*, NoAvl*);
NoAvl* rdd(ArvoreAvl*, NoAvl*);
NoAvl* rde(ArvoreAvl*, NoAvl*);