#include "celula.h"
#define ERRO_COORDENADA_INVALIDA -1

typedef struct{
	void **dados;
	int linhas, colunas,tamInfo;
} MatrizDinamica;

void inicializa_matriz( MatrizDinamica *p, int l, int c,int t);
void mostra_matriz( MatrizDinamica m ,void (*mostra) (void*));
void desaloca_matriz( MatrizDinamica *p );
int modifica_matriz( MatrizDinamica *p, int lin, int col, void *valor);
int get_celula_matriz( MatrizDinamica *p, int lin, int col, Celula *c);
int get_valor_matriz( MatrizDinamica *p, int lin, int col, void *info);
int compara_matrizes( MatrizDinamica a, MatrizDinamica b );
int posicao_valida_matriz(MatrizDinamica p,int lin, int col);

