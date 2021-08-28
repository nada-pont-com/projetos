#include <stdio.h>
#include <stdlib.h>

int fibi(int n){
    if(n>2){
        return fibi(n-1) + fibi(n-2);
    }else{
        return 1;
    }
}


int main(int argc, char const *argv[]){
    int n = 0 ;
    printf("ola numb  ");
    scanf("%d",&n);
    int r = fibi(n);
    printf("Resu: %d",r);
    return 0;
}
