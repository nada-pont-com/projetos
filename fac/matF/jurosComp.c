
#include <stdio.h>
#include <stdlib.h>

float potc(float base,int n);

int main(){
    float S;
    int tempo;
    float i,capit;
    scanf("%f",&i);
    scanf("%f",&capit);
    scanf("%d",&tempo);
    S = capit * potc(1+i,tempo);
    printf("%f /// %f",S,potc(1+i,tempo));
    return 0;
}


float potc(float base,int n){
    if(n==0){
        return 1;
    }else{  
        return base*potc(base,n-1);
    }
}

