#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float media(int num,float* vetor,int aux);
float vari(int num,float* vetor,int aux,float medi);
float potc(float base);

int main(){
    int n;
    float medi = 0,var;
    printf("Digite o numero de valores:\n");
    scanf("%d",&n);
    float *a = calloc(n,sizeof(float));
    for (int i = 0; i < n; i++){
        printf("Digite o valor %d:\n",i+1);
        scanf("%f",a + i);
    }
    medi = media(n,a,n);
    var = vari(n,a,n,medi);
    free(a);
    float dp = sqrt(var);
    printf("Media: %f, Varianca: %f, Desvio padrao: %f",medi,var,dp);
}

float media(int num,float* vetor,int aux){
    if(num==aux){
        return (*(vetor + (num-1)) + media(num-1,vetor,aux))/num;
    }else if(num==0){
        return 0;
    }else{
        return *(vetor + (num-1)) + media(num-1,vetor,aux);
    }
}


float vari(int num,float* vetor,int aux,float medi){
    if(num==aux){
        float a = (potc((*(vetor + (num-1)) - medi))+vari(num-1,vetor,aux,medi))/(num-1);
        return a;
    }else if(num==0){
        return 0;
    }else{
        return potc((*(vetor + (num-1)) - medi))+vari(num-1,vetor,aux,medi);
    }
}

float potc(float base){
    return base*base;
}