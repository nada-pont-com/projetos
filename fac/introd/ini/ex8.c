#include <stdio.h>
#include <stdlib.h>
/*
int main(){
    int num;
    printf("digite quantos valores voce quer comparar:\n");
    scanf("%d",&num);
    int armz[2] = {0,0};
    int vetor [num];
    for(int i=0;i<num;i++){
        printf("digite os valores:\n ");
        scanf("%d",&vetor[i]);
    }
    armz[0]=vetor[0];

    for (int i = 1; i < num; i++){    
        if((vetor[i]>armz[0])||(vetor[i]>armz[1])){
            armz[1]=armz[0];
            armz[0]=vetor[i];
        }
    }

    printf("Os maiores valores sao %d e %d\n",armz[0],armz[1]);
}
*/

int main(){
    int num,quanti;
    printf("digite quantos valores voce quer comparar:\n");
    scanf("%d",&quanti);

    printf("digite os valores:\n ");
    scanf("%d",num);

    int maior1 = num;
    int maior2 = quanti == 1 ? num : 0;
    for(int i=1;i<quanti;i++){
        printf("digite os valores:\n ");
        scanf("%d",num);
        if(num>maior1){
            maior2 = maior1;
            maior1 = num;
        }else if(num>maior2){
            maior2 = num;
        }
    }
    printf("1° maior numero é %d\n",maior1);
    printf("1° maior numero é %d\n",maior2);
}