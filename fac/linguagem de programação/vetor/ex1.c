#include <stdio.h>
#include <stdlib.h>
void main(){
    int num;
    printf("Digite o numero de entradas:\n");
    scanf("%d",&num);
    int vetor[num];
    double vetor2[num];
    for (int i = 0; i < num; i++){
        printf("Digite o %d numero:\n",i+1);
        scanf("%d",&vetor[i]);
    }
    for (int i = 0; i < num; i++){
        printf("Digite o %d numero:\n",i+1);
        scanf("%lf",&vetor2[i]);
    }
    double valor = 0,valor2 = 0;
    for (int i = 0; i < num; i++){
        valor += (vetor2[i]*vetor[i]);
        valor2 += vetor2[i];
    }
    valor = valor/valor2;
    printf("Resultado: %.2lf",valor);
    
}



/*
v1[x],v2[y]

res = ((v1[0] x v2[0])+(v1[1] x v2[1])....+n)/(v2[0]+v2[1]+n)
*/
