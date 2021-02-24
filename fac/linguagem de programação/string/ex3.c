#include <stdio.h>
#include <stdlib.h>

void masc(char* c,int n);

int main(int argc, char const *argv[]){
    char c[20];
    printf("digite: ");
    gets(c);
    masc(c,0);
    printf("%s",c);
    return 0;
}

void masc(char* c,int n){
    if((c[n]=='\0') || (n==21)){
        return;
    }else{
        if((c[n]>96) && (c[n]<123)){
            int i = c[n];
            i -= 32;
            c[n] = i;
        }
        masc(c,n+1);
    }
}

/*
65, A
90, Z
97, a
122, z
*/ 