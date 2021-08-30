#include <stdio.h>
#include <stdlib.h>

int contSpace(char*,int);

int main(int argc, char const *argv[]){
    char c[20];
    printf("digite: ");
    gets(c);
    printf("%d",contSpace(c,0));
    return 0;
}

int contSpace(char* c,int n){
    if(c[n]=='\0'){
        return 0;
    }else if((c[n]==' ') && (c[n+1]!=' ')){
        return 1 + contSpace(c,n+1);
    }else{
        return contSpace(c,n+1);
    }
}