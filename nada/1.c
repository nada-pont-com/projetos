#include <stdio.h>
#include <stdlib.h>
void main(){
    int n = 0,k = 0;
    printf("Digite o numero de valores que deseja inserir:\n");
    scanf("%d",&n);
    int vetor[n];
    for (int i = 0; i < n; i++){
        printf("Digite o valor do numero %d:\n",i+1);
        scanf("%d",&vetor[i]);
    }
    printf("Digite o valor para comparar:\n");
    scanf("%d",&k);
    for (int i = 0; i < n; i++){
        for (int i2 = i+1; i2 < n; i2++){
            int soma = vetor[i] + vetor[i2];
            if(soma==k){
                printf("True, pois %d + %d = %d.",vetor[i],vetor[i2],soma);
                exit(0);
            }
        }
    }
    printf("False!");
}
 
 /*
 Faça um programa que, dado um conjunto de números inteiros de tamanho N e um número K, retorne verdadeiro se a soma de qualquer par de números deste conjunto for igual a K. Exemplo: dado {10,15,3,7} e K = 17, a saída deve ser true, pois 10 + 7 é 17.
 */