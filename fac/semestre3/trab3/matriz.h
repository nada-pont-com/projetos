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

void inicializa_matriz_esparsa( Matriz_esparsa *m, int colunas, int linhas ){
    inicializa_lista(&(m->cabeca),sizeof(Lista));
    m->colunas = colunas;
    Lista linha;
    for (int i = 0; i < linhas; i++){
        inicializa_lista(&linha,sizeof(entrada_matriz));
        insere_fim(&m->cabeca,&linha);
    }
}

void mostra_matriz_esparsa(Matriz_esparsa m){
    int linhas = conta_elementos(m.cabeca);
    Lista aux;
    entrada_matriz auxVl;
    int j = 0;
    for (int i = 0; i < linhas; i++){
        le_valor(m.cabeca,&aux,i);
        for (; j < conta_elementos(aux); j++){
            le_valor(aux,&auxVl,j);
            for (; j < auxVl.coluna; j++){
                printf("0");
            }
            printf("%d",auxVl.valor);
        }
        for (; j < m.colunas; j++){
            printf("0");
        }
    }   
}

int valida_posicao_matriz_esparsa(int linha,int coluna){
    return !(linha < 0 || coluna < 0);
}

int set_valor_matriz(Matriz_esparsa *m,int linha,int coluna, int valor){
    if(!valida_posicao_matriz_esparsa(linha,coluna)) 
        return ERRO_POS_INVALIDA_Matriz_esparsa;
    if(valor==0)
        return excluir_valor_matriz_esparsa(m,linha,coluna);

    int linhas = conta_elementos(m->cabeca);

    for (; linhas<=linha; linhas++){
        inserir_linha_matriz_esparsa(m);
    }

    int j = 0;
    Lista aux;
    entrada_matriz auxVl;
    le_valor(m->cabeca,&aux,linha);
    
    j = busca_posicao_existente_by_posicao(*m,linha,coluna);
    if(j!=ERRO_POS_VAZIA_Matriz_esparsa){
        le_valor(aux,&auxVl,j);
        auxVl.valor = valor;
        j = modifica_valor(aux,&auxVl,j);
    }else{
        auxVl.coluna = coluna;
        auxVl.valor = valor;
        j = insere_ordem(&aux,&auxVl,comparar_valor_matriz);
    }
    if(j!=1)
        return ERRO_POS_INVALIDA_Matriz_esparsa;
    modifica_valor(m->cabeca,&aux,linha);
    
    return 1;
}

int get_valor_matriz(Matriz_esparsa *m,int linha,int coluna, int *valor){
    if(valida_posicao_matriz_esparsa(linha,coluna))
        return ERRO_POS_INVALIDA_Matriz_esparsa;

    int j = busca_posicao_existente_by_posicao(*m,linha,coluna);
    if(j!=ERRO_POS_VAZIA_Matriz_esparsa){
        Lista aux;
        entrada_matriz auxVl;
        le_valor(m->cabeca,&aux,linha);
        le_valor(aux,&auxVl,j);
        *valor = auxVl.valor;
    }else
        *valor = 0;

    return 1;
}

int comparar_valor_matriz(void *vl1,void *vl2){
    entrada_matriz *valor1 = (entrada_matriz*) vl1,*valor2 = (entrada_matriz*) vl2;
    return valor1->coluna - valor2->coluna;
}

void inserir_linha_matriz_esparsa(Matriz_esparsa *m){
    Lista coluna;
    inicializa_lista(&coluna,sizeof(entrada_matriz));
    insere_fim(&m->cabeca,&coluna);
}

int excluir_valor_matriz_esparsa(Matriz_esparsa *m,int linha,int coluna){
    int j = busca_posicao_existente_by_posicao(*m,linha,coluna);
    entrada_matriz auxVl;
    Lista aux;
    le_valor(m->cabeca,&aux,linha);
    if(j!=ERRO_POS_VAZIA_Matriz_esparsa)
        remove_pos(&aux,&auxVl,j);
    return 1;
}

int busca_posicao_existente_by_posicao(Matriz_esparsa m,int linha,int coluna){

    int j = 0;
    Lista aux;
    entrada_matriz auxVl = {-1,-1};
    int colunas = conta_elementos(aux);
    if(colunas!=0)
        for (; j < colunas && auxVl.coluna<coluna; j++){
            le_valor(aux,&auxVl,j);
            if(coluna==auxVl.coluna){
                return j;
            }
        }
    return ERRO_POS_VAZIA_Matriz_esparsa;
}

int soma_matriz_esparsa(Matriz_esparsa m1,Matriz_esparsa m2,Matriz_esparsa *soma){
    int linhas = conta_elementos(m1.cabeca);
    if(m1.colunas!=m2.colunas || linhas!=conta_elementos(m2.cabeca))
        return 0;
    inicializa_matriz_esparsa(soma,m1.colunas,linhas);
    int valor1,valor2;
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < m1.colunas; j++){
            get_valor_matriz(&m1,i,j,&valor1);
            get_valor_matriz(&m2,i,j,&valor2);
            set_valor_matriz(soma,i,j,valor1+valor2);
        }    
    }
    return 1;   
}