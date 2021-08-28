#include <stdio.h>
#include <stdlib.h>

int pont(char* c,int n);

int main(int argc, char const *argv[]){
    char c[20];
    printf("digite um numero: ");
    gets(c);
    int a = pont(c,0);
    if(a){
        printf("o numero %s e true",c);
    }else{
        printf("o numero %s e false",c);
    }
    return 0;
}

int pont(char* c,int n){
    if(c[n]=='\0'){
        return 1;
    }else if(c[n]=='.'){
        return 0;
    }else if((c[n]>='0') && (c[n]<='9')){
        return pont(c,n+1);
    }else{
        return 0;
    }
}