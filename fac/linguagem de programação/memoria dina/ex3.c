#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    float resu = 0,soma;
    printf("Digite o numero de valores:\n");
    scanf("%d",&n);
    int *a = calloc(n,sizeof(int));
    int *b = calloc(n,sizeof(int));
    for (int i = 0; i < n; i++){
        printf("Digite o valor do dado %d:\n",i+1);
        scanf("%d",a + i);
    }
    for (int i = 0; i < n; i++){
        printf("Digite o valor do peso %d:\n",i+1);
        scanf("%d",b + i);
    }
    for (int i = 0; i < n; i++){
        resu += (*(a+i)) * (*(b+i));
        soma += *(b+i);
    }
    resu /= soma;
    printf("Resultado: %0.2f",resu); 
}




