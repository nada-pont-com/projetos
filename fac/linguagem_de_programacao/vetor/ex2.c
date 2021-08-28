#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float media(int num,float vetor[],int aux);
float vari(int num,float vetor[],int aux,float medi);
float potc(float base);

void main(){
    int num;
    float medi = 0;
    printf("Digite o numero de entradas:\n");
    scanf("%d",&num);
    float vetor[num];
    for (int i = 0; i < num; i++){
        printf("Digite o %d numero:\n",i+1);
        scanf("%f",&vetor[i]);
    }
    medi = media(num,vetor,num);
    float varian = vari(num,vetor,num,medi);
    float desv = sqrt(varian);
    printf("Media: %f\nDesvio Padrão: %f\nVairiancia: %f",medi,desv,varian);
}


float media(int num,float vetor[],int aux){
    if(num==aux){
        return (vetor[num-1] + media(num-1,vetor,aux))/num;
    }else if(num==0){
        return 0;
    }else{
        return vetor[num-1] + media(num-1,vetor,aux);
    }
}


float vari(int num,float vetor[],int aux,float medi){
    if(num==aux){
        float a = (potc((vetor[num-1] - medi))+vari(num-1,vetor,aux,medi))/num;
        //printf("vetor: %f\nm: %f\num",vetor[num-1],medi);
        //printf("vari: %f\num-----\num",a);
        return a;
    }else if(num==0){
        return 0;
    }else{
        return potc((vetor[num-1] - medi))+vari(num-1,vetor,aux,medi);
    }
}

float potc(float base){
    //printf("pow: %f\nbase: %f\num------\n",a,base);
    return base*base;
}

/*
int x1,x2,m,n = 2;
m = (x1+x2)/n
dp = [((x1-m)^2 + (x2-m)^2)/n]^(1/2)
1.55 1.70 1.80
*/