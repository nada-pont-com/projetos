#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, maior = 0, menor,soma = 0;
    printf("Digite um numero de valores:\n");
    scanf("%d",&num);
    int valores[num];
    for (int i = 0; i < num; i++){
        printf("Digite o %dº: ",i+1);
        scanf("%d",&valores[i]);
        soma += valores[i]; 
    }
    menor = valores[0];
    for (int i = 0; i < num; i++){
        if(valores[i]<menor){
            menor = valores[i];
        }
        if(valores[i]>maior)
            maior = valores[i];
    }
    float media = soma/num;
    printf("Maior valor: %d\nMenor valor: %d\nMedia: %.2f",maior,menor,media);
    
}