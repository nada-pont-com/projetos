#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

// Integrantes : Vinicius Dall Olivo Gonçalves e Ana Luiza Croce de Miranda


void criar(Lista *matrizes);
void mostra_matriz(Lista matrizes);
void modificarMatriz(Lista *matrizes);
void somarMatrizes(Lista *matrizes);
void remover(Lista *matrizes);
int getPosicaoLista(Lista l,char *s);

void main(){

    Lista matrizes;
    inicializa_lista(&matrizes,sizeof(Matriz_esparsa));
    int option = 0;
    do{
        printf("Digite:%s%s%s%s%s%s",
        "\n 1 - Criar uma nova matriz",
        "\n 2 - Mostrar dados de uma matriz",
        "\n 3 - Modificar dados",
        "\n 4 - Somar duas matrizes",
        "\n 5 - Remover Matriz",
        "\n 6 - Sair\n");

        scanf("%d",&option);
        switch (option){
            case 1:
                criar(&matrizes);
                break;
            case 2:
                mostra_matriz(matrizes);
                break;
            case 3:
                modificarMatriz(&matrizes);
                break;
            case 4:
                somarMatrizes(&matrizes);
                break;
            case 5:
                remover(&matrizes);
                break;
            case 6:
                break;
        default:
            printf("Valor invalido\n");
            break;
        }
    } while (option!=6);
}

void criar(Lista *matrizes){
    Matriz_esparsa m1;
    int linha,coluna;
    printf("Digite o numero de linha da matriz:\n");
    scanf("%d",&linha);

    printf("Digite o numero de coluna da matriz:\n");
    scanf("%d",&coluna);

    if(!valida_posicao_matriz_esparsa(linha,coluna)){
        printf("Linha ou Coluna Invalida");
        return;
    }

    inicializa_matriz_esparsa(&m1,linha,coluna);
    insere_fim(matrizes,&m1);
}

void mostra_matriz(Lista matrizes){
    int indice = getPosicaoLista(matrizes,"Digite o numero da matriz deseja ver");
    if(indice==-1) return;
    Matriz_esparsa m1;
    le_valor(matrizes,&m1,indice);
    mostra_matriz_esparsa(m1);
}

void modificarMatriz(Lista *matrizes){
    int indice = getPosicaoLista(*matrizes,"Digite o numero da matriz que deseja modificar");
    if(indice==-1) return;
    Matriz_esparsa m1;
    remove_pos(matrizes,&m1,indice);
    

    int linha,coluna,valor = 0;
    printf("Digite o numero de linha da matriz:\n");
    scanf("%d",&linha);

    printf("Digite o numero de coluna da matriz:\n");
    scanf("%d",&coluna);

    printf("Digite o Valor a ser inserido:\n");
    scanf("%d",&valor);

    if(set_valor_matriz(&m1,linha-1,coluna-1,valor)==ERRO_POS_INVALIDA_Matriz_esparsa){
        printf("Posição Invalida"); 
    }
    insere_pos(matrizes,&m1,indice);
}

void somarMatrizes(Lista *matrizes){
    int indice1 = getPosicaoLista(*matrizes,"Digite o numero da matriz1");
    int indice2 = getPosicaoLista(*matrizes,"Digite o numero da matriz2");
    if(indice1==-1 || indice2==-1) return;
    Matriz_esparsa m1;
    Matriz_esparsa m2;
    le_valor(*matrizes,&m1,indice1);
    le_valor(*matrizes,&m2,indice2);
    
    Matriz_esparsa m3;
    if(!soma_matriz_esparsa(&m1,&m2,&m3)){
        printf("Matrizes com colunas ou linhas diferentes.");
        return;
    }
    insere_fim(matrizes,&m3);
}

void remover(Lista *matrizes){
    int indice = getPosicaoLista(*matrizes,"Digite o numero da matriz que deseja remover");
    if(indice==-1) return;
    Matriz_esparsa m1;
    if(remove_pos(matrizes,&m1,indice)==1){
        desaloca_matriz_esparsa(&m1);
    }else{
        printf("Erro ao remover");
    }
}

int getPosicaoLista(Lista l,char *s){
    int elementos = conta_elementos(l),indice;
    if(elementos==0){
        printf("Lista vazia\n");
        return -1;
    }

    printf("%s: (%d cadastradas)",s,elementos);
    scanf("%d",&indice);
    indice--;
    if(indice<elementos && indice>=0){
        return indice;
    }else
        printf("Valor invalido.\n");

    return -1;
}
