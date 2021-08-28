#include <stdio.h>
#include <stdlib.h>

int fat(int n){
    if(n>2){
        return n*fat(n-1);
    }else{
        return n;
    }
}

int main(int argc, char const *argv[]){
    int n = 0 ;
    printf("ola numb  ");
    scanf("%d",&n);
    int r = fat(n);
    printf("Resu: %d",r);
    return 0;
}