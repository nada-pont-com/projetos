#include <stdio.h>
#include <stdlib.h>

int main(){
    int num[2],cont = 0;
    for (int i = 0; i < 2; i++){
        do{
            printf("Digite o %d numero positivo:\n",i+1);
            scanf("%d",&num[i]);
        } while (num[i]<0);
    }
    while (num[0]>=num[1]){
        num[0] = num[0] - num[1];
        cont++;
    }
        printf("Resultado: %d\n",cont);
}
