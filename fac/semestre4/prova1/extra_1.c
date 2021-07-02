#include <stdio.h>
#include <stdlib.h>

int numParesLuvas(int* vetor,int tamanho);
void mostra_vetor(int * vetor, int tamanho);

int compara(const void *a,const void *b){
    return *((int*) a) - *((int*) b);
}


int numParesLuvas(int* vetor,int n){
    
    int pares = 0;

    for(int i = 0;i<n-1;i++){
        if(vetor[i]==vetor[i+1]){
            i++;
            pares++;
        }
    }
    return pares;
}

void main(){
    int tamanho = 0;
    printf("Quantos numeros de luvas\n");
    scanf("%d",&tamanho);

    int vetor[tamanho];
    
    for (int i = 0; i < tamanho; i++){
        printf("%d: ",i);
        scanf("%d",vetor+i);
    }
    
    qsort(vetor,tamanho,sizeof(vetor[0]),compara);
    
    tamanho = numParesLuvas(vetor,tamanho);
    printf("%d pares",tamanho);
}