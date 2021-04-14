#include "matriz.h"

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
    int j = 0,j2 = 0;
    for (int i = 0; i < linhas; i++){
        le_valor(m.cabeca,&aux,i);
        //mostra_lista();
        for (j2 = 0,j = 0; j < conta_elementos(aux); j++,j2++){
            le_valor(aux,&auxVl,j);
            for (; j2 < auxVl.coluna; j2++){
                printf(" 0 ");
            }
            printf(" %d ",auxVl.valor);
        }
        for (; j2 < m.colunas; j2++){
            printf(" 0 ");
        }
        printf("\n");
    }   
}

void desaloca_matriz_esparsa(Matriz_esparsa *m){
    int linhas = conta_elementos(m->cabeca);
    Lista aux;
    for (int i = 0; i < linhas; i++){
        le_valor(m->cabeca,&aux,i);
        desaloca_lista(&aux);
    }
    desaloca_lista(&(m->cabeca));
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
    int valida = 0;
    if(m->colunas<=coluna || linhas<=linha)
        valida = 1;
    
    for (; linhas<=linha; linhas++){
        inserir_linha_matriz_esparsa(m);
    }

    if(m->colunas<=coluna){
        m->colunas = coluna+1;
    }

    int j = 0;
    Lista aux;
    entrada_matriz auxVl;
    le_valor(m->cabeca,&aux,linha);
    if(!valida)
        j = busca_posicao_existente_by_posicao(*m,linha,coluna);
    else
        j = ERRO_POS_VAZIA_Matriz_esparsa;
    
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
    if(!valida_posicao_matriz_esparsa(linha,coluna))
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
    entrada_matriz *valor1 = vl1, *valor2 = vl2;    
    return valor1->coluna - valor2->coluna;
}

void inserir_linha_matriz_esparsa(Matriz_esparsa *m){
    Lista coluna;
    inicializa_lista(&coluna,sizeof(entrada_matriz));
    insere_fim(&(m->cabeca),&coluna);
}

int excluir_valor_matriz_esparsa(Matriz_esparsa *m,int linha,int coluna){
    int j = busca_posicao_existente_by_posicao(*m,linha,coluna);
    entrada_matriz auxVl;
    Lista aux;
    le_valor(m->cabeca,&aux,linha);

    if(j!=ERRO_POS_VAZIA_Matriz_esparsa){
        remove_pos(&aux,&auxVl,j);
        modifica_valor(m->cabeca,&aux,linha);
    }
    return 1;
}

int busca_posicao_existente_by_posicao(Matriz_esparsa m,int linha,int coluna){

    int j = 0;
    Lista aux;
    entrada_matriz auxVl = {-1,-1};
    le_valor(m.cabeca,&aux,linha);
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

int soma_matriz_esparsa(Matriz_esparsa *m1,Matriz_esparsa *m2,Matriz_esparsa *soma){
    int linhas = conta_elementos(m1->cabeca);
    if(m1->colunas!=m2->colunas || linhas!=conta_elementos(m2->cabeca))
        return 0;
    inicializa_matriz_esparsa(soma,m1->colunas,linhas);

    int valor1 = 0,valor2 = 0;
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < m1->colunas; j++){
            get_valor_matriz(m1,i,j,&valor1);
            get_valor_matriz(m2,i,j,&valor2);
            if(valor1+valor2==0) continue;
            set_valor_matriz(soma,i,j,valor1+valor2);
        }    
    }
    return 1;   
}