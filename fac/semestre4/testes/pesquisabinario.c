#include <stdio.h>
#include <stdlib.h>

int pesquisaBinariaRecursiva (int chave, int v[], int inicio, int fim);

int main(){
    printf("teste");
    int vetor[500000];
    for (int i = 0; i < 50; i++){
        vetor[i] = rand()%10000;
    }
    printf("teste %d",pesquisaBinariaRecursiva(250,vetor,0,50));
    return 0;
}

int pesquisaBinariaRecursiva (int chave, int v[], int inicio, int fim){
    int meio = (inicio + fim )/2;
    if(inicio>fim){
        return -1;
    }
    if (chave== v[meio]){
        return meio;
    }else if (chave< v[meio]){
        return pesquisaBinariaRecursiva(chave, v , inicio, meio-1);
    }else { 
        return pesquisaBinariaRecursiva(chave, v, meio+1,fim);
    }
}
