#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cont_quadrado(int limt_l,int limt_r);

int main(){
    int quest,valida,limt_l,limt_r;
    int i = 0;
    scanf("%d",&quest);


    for (i = 0; i < quest; i++){
        scanf("%d",&limt_l);
        scanf("%d",&limt_r);
        printf("%d",cont_quadrado(limt_l,limt_r));
    }
    return 0;
}

int cont_quadrado(int limt_l,int limt_r){
    int i;
    double vl;
    int cont = 0,valida;
    for ( i = limt_l; i <= limt_r; i++){
        vl = sqrt(i);
        valida = (int) vl;
        if(valida == vl){
            cont++;
        }
    }
    return cont;
}