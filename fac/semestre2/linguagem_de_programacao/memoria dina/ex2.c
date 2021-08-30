#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,menor = 0,maior = 0,soma = 0;
    printf("Digite o numero de valores:\n");
    scanf("%d",&n);
    int *a = calloc(n,sizeof(int));
    for (int i = 0; i < n; i++){
        printf("Digite o valor %d:\n",i+1);
        scanf("%d",a + i);
    }
    menor = maior = *a;
    for (int i = 0; i < n; i++){
        if(*(a+i) > maior){
            maior = *(a + i);
        }
        if(*(a+i) < menor){
            menor = *(a+i);
        }
    }
    free(a);
    soma = menor + maior;
    printf("menor: %d, maior: %d, soma: %d",menor,maior,soma);
    return 0;
}
