#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int pares;
    int* tamanhos;
} Luvas;

Luvas numParesLuvas(int* vetor,int tamanho);
void mostra_vetor(int * vetor, int tamanho);
void mostra_Luvas(Luvas luva);

int compara(const void *a,const void *b){
    return *((int*) a) - *((int*) b);
}

void main(){
    int tamanho = 9;
    printf("Quantos numeros de luvas deseja inserir:\n");
    scanf("%d",&tamanho);

    int vetor[tamanho];
    
    for (int i = 0; i < tamanho; i++){
        printf("luva %d: ",i);
        scanf("%d",vetor+i);
    }
    
    qsort(vetor,tamanho,sizeof(vetor[0]),compara);
    
    Luvas luva = numParesLuvas(vetor,tamanho);
    mostra_Luvas(luva);
}

Luvas numParesLuvas(int* vetor,int n){
    Luvas luvas;
    luvas.pares = 0;
    luvas.tamanhos = calloc(n/2,sizeof(int));

    for(int i = 0;i<n-1;i++){
        if(vetor[i]==vetor[i+1]){
            i++;
            luvas.tamanhos[luvas.pares] = vetor[i];
            luvas.pares++;
        }
    }
    return luvas;
}

void mostra_Luvas(Luvas luva){
    printf("%d Pares",luva.pares);
    
    if(luva.pares==0) return;

    printf("(");
    for (int i = 0; i < luva.pares; i++){
        printf("tamanho %d",luva.tamanhos[i]);
        if(i+1!=luva.pares){
            printf(",");
        }
    }
    printf(")");
    
}

void mostra_vetor(int * vetor,int n){
    for(int i = 0;i<n;i++){
        printf("%d: %d\n",i,vetor[i]);
    }
}