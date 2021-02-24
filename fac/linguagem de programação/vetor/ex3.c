#include <stdio.h>
#include <stdlib.h>

void main(){
    int num = 0;
    printf("Digite o numero de entradas:\n");
    scanf("%d",&num);
    int vetor[num];
    for (int i = 0; i < num; i++){
        printf("Digite o %d numero:\n",i+1);
        scanf("%d",&vetor[i]);
    }
    for (int i = 0; i < num; i++){
        printf(" %d, ",vetor[i]);
    }
        printf("\n\n");

    int aux;
    for (int i = 0; i < num; i++){
        for (int i2 = 0; i2 < num; i2++){
            if(i==i2){
                continue;
            }
            printf("vetori: %d, vetori2: %d \n\n",vetor[i],vetor[i2]);
            if(vetor[i]<vetor[i2]){
                aux = vetor[i];
                vetor[i] = vetor[i2];
                vetor[i2] = aux;
            }
        }
    }
    
    for (int i = 0; i < num; i++){
        printf(" %d, ",vetor[i]);
    }

}

int mediana(int vetor[],int num){
    if((num%2)==0){
        num /=2;
        return (vetor[num]+vetor[num+1])/2;
    }else{
        num /=2;
        return vetor[num];
    }    
}

int moda(int vetor[],int num){
    int valor[2] = {0,0}, aux = 0;
    for (int i = 0; i < num; i++){
        for (int i2 = 0; i2 < num; i2++){
            if(i==i2){
                continue;
            }
            if(vetor[i]==vetor[i2]){
                aux++;
                for (int i3 = i2; i3 < num; i3++){
                    if(vetor[i]==vetor[i3]){
                        aux++;
                    }
                }
                if(aux>valor[1]){
                    valor[0] = vetor[i];
                    valor[1] = aux;
                }
            }
        }
    }
}

