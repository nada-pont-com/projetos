#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num,valor;
    srand(time(NULL));
    valor = rand()%101;
    do{
        printf("Digite um numero de 0 a 100:\n");
        scanf("%d",&num);
        if(num<valor)
            printf("o numero e maior do que %d\n\n",num);
        else if(num>valor)
            printf("O numero e menor do que %d\n\n",num);
    } while (valor!=num);
    printf("O numero certo e %d",valor);
    return 0;
}
