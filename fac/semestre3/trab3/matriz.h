#include <stdio.h>
#include <string.h>
#include "Lista.h"

#define ERRO_POS_INVALIDA_Matriz_esparsa -2
#define ERRO_POS_VAZIA_Matriz_esparsa -1

typedef struct{
    Lista cabeca;
    int colunas;
} Matriz_esparsa;


typedef struct{
   int valor;
   int coluna; 
} entrada_matriz;

//desaloca_lista(&linha);

void inicializa_matriz_esparsa( Matriz_esparsa *m, int colunas, int linhas );

void mostra_matriz_esparsa(Matriz_esparsa m);

void desaloca_matriz_esparsa(Matriz_esparsa *m);

int valida_posicao_matriz_esparsa(int linha,int coluna);

int set_valor_matriz(Matriz_esparsa *m,int linha,int coluna, int valor);

int get_valor_matriz(Matriz_esparsa *m,int linha,int coluna, int *valor);

int comparar_valor_matriz(void *vl1,void *vl2);

void inserir_linha_matriz_esparsa(Matriz_esparsa *m);

int excluir_valor_matriz_esparsa(Matriz_esparsa *m,int linha,int coluna);

int busca_posicao_existente_by_posicao(Matriz_esparsa m,int linha,int coluna);

int soma_matriz_esparsa(Matriz_esparsa *m1,Matriz_esparsa *m2,Matriz_esparsa *soma);