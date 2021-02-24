#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inver(char* c,int n,int n2){
    if(n>n2){
        char axu = c[n];
        c[n] = c[n2];
        c[n2] = axu;
        return inver(c,n-1,n2+1);
    }
}

int main(int argc, char const *argv[]){
    char c[10];
    printf("digite: ");
    fflush(stdin);
    sscanf(fgets(c,10,stdin),"%[^/0]s",c);
    fflush(stdin);
    //printf("%d\n%s\n",strlen(c),c);
    inver(c,strlen(c)-1,0);
    printf("Resu: %s",c);
    return 0;
}