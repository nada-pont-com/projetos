#include <stdio.h>
#include <stdlib.h>

float resultado(float i,int n,float parc);
float potc(float base,int n);

int main(){
    float parc,i;
    int n;
    printf("i:");
    scanf("%f",&i);    
    printf("n:");
    scanf("%d",&n);    
    printf("parc:");
    scanf("%f",&parc);    
    i = resultado(i,n,parc);
    printf("%f",i);
    return 0;
}

float resultado(float i,int n,float parc){
    if (n==0){
        printf("\n");
        return 0;
    }else{
        printf("%0.2f/(1+%0.4f)^%d +",parc,i,n);
        return (parc/potc(1+i,n)) + resultado(i,n-1,parc);
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