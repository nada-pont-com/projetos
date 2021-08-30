#include <stdio.h>
#include <stdlib.h>

int divi(int n,int n2){
    if(n>=n2){
        return 1+divi(n-n2,n2);
    }else{
        return 0;
    }
}

void main(int argc, char const *argv[]){
    int n1 = 0 ,n2 = 0;
    printf("ola numb 1 ");
    scanf("%d",&n1);
    printf("ola numb 2 ");
    scanf("%d",&n2);
    int r = divi(n1,n2);
    printf("Resu: %d",r);
}
