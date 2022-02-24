
int nrAvl = 0;

typedef struct no {
  int v;
  int bal;   /* hdir - hesq */
  struct no *esq, *dir;
} No,**ArvoreAvl;

ArvoreAvl criaArvoreAvl();
int insere(ArvoreAvl t, int v);
void mostrarArvoreInOrder(ArvoreAvl t);
