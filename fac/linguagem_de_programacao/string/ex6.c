#include <stdio.h>
#include <stdlib.h>


int cont(char* c);

int palindro(char* c,int n);

int main(int argc, char const *argv[]){
    char c[20];
    printf("digite algo: ");
    gets(c);
    int n = cont(c);
    int a = palindro(c,n);
    if(a){
        printf("true %d",a);
    }else{
        printf("false %d",a);
    }

}

int cont(char* c){
    int i = 0;
    while (c[i] != '\0'){
        i++;
    }
    return i;
}

int palindro(char* c,int n){
    int aux = 0;
    for (int i = 0; i < n; i++){
        n--;
        if(c[i]!=c[n]){
            aux = 1;
            break;
        }
        if(i==n){
            break;
        }
    }
    return aux;
}
