#include <stdio.h>
#include <stdlib.h>

int main(){
    /*  Ex3*/
    int cli;
    printf("Escolha uma das condicoes climaticas que se encontra a dia de hoje:\n1- sol\n2- nuvens\n3- chuva\n");
    scanf("%d",&cli);
    switch(cli){
    case 1:
        printf("Umidade esta?\n1- Elevada\n2- Normal\n");
        scanf("%d",&cli);
        if(cli==1){
            printf("Nao e favoravel jogar tenis hoje!");
        }else{
            printf("Sim, e favoravel jogar tenis hoje!");
        }
    break;
    case 2:
        printf("Nao e favoravel jogar tenis hoje!");
    break;
    case 3:
        printf("Vento esta?\n1- Forte\n2- Fraco\n");
        scanf("%d",&cli);
        if(cli==1){
            printf("Nao e favoravel jogar tenis hoje!");
        }else{
            printf("Sim, e favoravel jogar tenis hoje!");
        }
    break;
    default:
        printf("Valor invalido!");
    break;
    }

}