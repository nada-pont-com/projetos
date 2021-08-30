#include <stdio.h>
#include <stdlib.h>

void main(){
    int n = 0,cont = 0;
    printf("Digite o numero de valores de luvas que deseja inserir:\n");
    scanf("%d",&n);
    int vetor[n];
    return 0;
    for (int i = 0; i < n; i++){
        do{
            printf("Digite o tamanho da luva %d:\n",i+1);
            scanf("%d",&vetor[i]);
            if(vetor[i]<0){
                printf("Valor invalido");
            }
        } while (vetor[i]<0);
    }
    for (int i = 0; i < n; i++){
        for (int i2 = i+1; i2 < n; i2++){
            if(vetor[i]==vetor[i2]){
                cont++;
                vetor[i2] = - cont;
                break;
            }
        }    
    }
    printf("%d pares!",cont);
}

/*
 Dado um conjunto de N números inteiros representando o tamanho de luvas, faça um programa para contar o máximo possível de pares de luvas existentes no conjunto. Observe que uma luva só pode ser par de outra luva do mesmo tamanho e só pode fazer parte de um único par. Exemplo: entrada = {6, 5, 2, 3, 5, 2, 2, 1,6}, saída = 2 pares (tamanho 5 e tamanho 2).
*/