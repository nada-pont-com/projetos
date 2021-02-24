#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int value = 1,num,valor;
    int maior = 101,menor = -1;
    srand(time(NULL));
    num = rand()%101;
    printf("Mentalize um numero de 0 a 100\n");
    do{
        printf("O numero %d e:\n1 - menor\n2 - maior\n3 - o numero\n",num);
        scanf("%d",&valor);
        printf("\n\n");
        if(valor == 3){
            printf("Resposta correta!");
            break;
        }if(valor == 2)
            menor = num;
        else
            maior = num;
        srand(time(NULL));
        num = (rand()%(maior-menor))+ menor;
    } while (value);
    return 0;
}

/*
int main(){
    int value = 1,valor,contador = 0;
    int maior = 100,menor = 0;
    int num = (maior + menor)/2;
    printf("Mentalize um numero de 0 a 100\n");
    while (1){
        printf("O numero %d e:\n1 - menor\n2 - maior\n3 - o numero\n",num);
        scanf("%d",&valor);
        if(valor == 3){
            printf("Resposta correta em %d tentativas!\n", contador);
            break;
        }if(valor == 2)
            menor = num + 1;
        else
            maior = num - 1;
        num = (maior + menor)/2;
        contador++;
    }
}
*/