
#include <stdio.h>
#include <stdlib.h>

float juros(float i,int n,float parc);
float juros2(float i,int n,float parc);
float potc(float base,int n);

int main(){
    float parc = 210,i;
    int n = 24;
    i = 0.006;
    float rest;
    rest = juros(i,n,parc);
    parc = juros2(i,n,parc);
    printf("\nS1 = %.2f\nS2 = %.2f",rest,parc);
    return 0;
}

float juros2(float i,int n,float parc){
    float result = 0;
    for (int cont = 1; cont <= n; cont++){
        float aux = result;
        result = result*(1+i);
        result+= parc;
        printf("S%d = %.2f+210 = %0.2f*(1+%0.4f)+210\n",cont,result-210,aux,i);        
    }
    return result;
}

float juros(float i,int n,float parc){
    if (n==0){
        printf("\n");
        return 0;
    }else{
        return (juros(i,n-1,parc))*(1+i)+parc;
    }
}

float potc(float base,int n){
    //printf("pow: %f\nbase: %f\num------\n",a,base);
    if(n==0){
        return 1;
    }else{  
        return base*potc(base,n-1);
    }
}