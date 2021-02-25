#define ERRO_PILHA_VAZIA - 1
#define ERRO_PILHA_CHEIA - 2

typedef struct{
	void **dados;
	int topo;
	int capacidade;
	int tamInfo;
}Pilha;

void inicializa_pilha( Pilha *p, int c,int t );
int pilha_vazia( Pilha p );
int pilha_cheia( Pilha p );
int empilha( Pilha *p, void *info );
int desempilha( Pilha *p, void *info );
int le_topo( Pilha p, void *info );
void mostra_pilha( Pilha p , void (*mostra) (void*) );
void desaloca_pilha( Pilha *p);