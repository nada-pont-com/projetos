#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int moda(float*,int);
float mediana(float*,int);
float vari(int,float*,int,float);
float media(int,float*,int);
float potc(float);
void z_score(float,float*,float,int);
void ordenar(float*,int);
void quartil(float*,int);

void main(){
    int n;
    float median = 0,mod,medi = 0;
    printf("Digite o numero de valores:\n");
    scanf("%d",&n);
    float *a = calloc(n,sizeof(float));
    for (int i = 0; i < n; i++){
        printf("Digite o valor %d:\n",i+1);
        scanf("%f",a + i);
    }
    ordenar(a,n);
    printf("\n\n");
    for (int i = 0; i < n; i++){
        printf("valor %d: %f\n",i+1,*(a+i));
    }
    printf("\n\n");
    mod = moda(a,n);
    medi = media(n,a,n);
    median = mediana(a,n);
    float dp = sqrt(vari(n,a,n,medi));
    printf("mediana: %.0f \nmoda: %.0f \nmedia: %0.2f \ndp: %0.2f\n",median,mod,medi,dp);
    quartil(a,n);
    z_score(medi,a,dp,n);
}

void ordenar(float* vetor,int n){
    float aux = 0;
    for (int i = 0; i < n-1; i++){
        for (int i2 = i+1; i2 < n; i2++){
            if(*(vetor+i)>*(vetor+i2)){
                aux = *(vetor+i);
                *(vetor+i) = *(vetor+i2);
                *(vetor+i2) = aux;
            }
        }
    }
}

void quartil(float* vetor,int n){
    int valor;
    valor = (n+1)/4;
    printf("Q1:%.0f\n",*(vetor+valor));
    printf("Q2:%.0f\n",mediana(vetor,n));
    valor = (3*(n+1))/4;
    printf("Q3:%.0f\n",*(vetor+valor));
}

float mediana(float* vetor,int n){
    if(n%2==0){
        n = n/2;
        return (*(vetor+n)+*(vetor+(n+1)))/2;
    }else{
        n = n/2;
        return *(vetor+n);
    }
}

int moda(float* vetor,int n){
    int cont = 0,valor = *vetor;
    for (int i = 0; i < n-1; i++){
        int cont2 = 0;
        for (int i2 = i+1; i2 < n; i2++){
            if(*(vetor+i)==*(vetor+i2)){
                cont2++;
            }
        }
        if(cont2>cont){
            valor = *(vetor+i);
            cont = cont2;
        }
    }
    return valor;
}


float media(int num,float* vetor,int num2){
    if(num==num2){
        return (*(vetor + (num-1)) + media(num-1,vetor,num2))/num;
    }else if(num==0){
        return 0;
    }else{
        return *(vetor + (num-1)) + media(num-1,vetor,num2);
    }
}


float vari(int num,float* vetor,int num2,float medi){
    if(num==num2){
        float a = (potc((*(vetor + (num-1)) - medi))+vari(num-1,vetor,num2,medi))/(num-1);
        return a;
    }else if(num==0){
        return 0;
    }else{
        return potc((*(vetor + (num-1)) - medi))+vari(num-1,vetor,num2,medi);
    }
}

float potc(float base){
    return base*base;
}


void z_score(float medi,float* vetor,float dp,int n){
    float* z = calloc(n,sizeof(float));
    for (int i = 0; i < n; i++){
        *(z+i) = ( *(vetor+i) - medi) / dp;
        printf("\nz %d: %0.2f, valor %d: %.0f",i+1,*(z+i),i+1,*(vetor+i));
        if((*(z+i)>1)||(*(z+i)<-1)){
            printf("Outlier");
        }
    }
    free(z);
}
/*
15
 1100
 1001
 1002
 1004
 1005
 1004
 1000
 1004
 10000
 1300
 1200
 1001
 1009
 1040
 1400
 */