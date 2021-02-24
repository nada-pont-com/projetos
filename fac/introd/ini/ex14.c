#include <stdio.h>
#include <stdlib.h>

int main(){
    int base = 1,expoente = 0,expoenteN = 0;
    int potencia = 1;
    printf("Digite a base:\n");
    scanf("%d",&base);
    printf("Digite o expoente:\n");
    scanf("%d",&expoente);
    if(expoente<0){
        expoente = expoente*-1;
        expoenteN = 1;
    }
    for (int i = 0; i < expoente; i++){
        potencia *= base;
    }
    if(expoenteN){
        printf("Resultado: 1/%d",potencia);
    }else
        printf("Resultado: %d",potencia);
    return 0;
}
