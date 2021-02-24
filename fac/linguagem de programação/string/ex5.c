#include <stdio.h>
#include <stdlib.h>

int func(char* c,char* c2,int n,int n2);

int main(int argc, char const *argv[]){
    char c[20];
    gets(c);
    char c2[20];
    gets(c2);
    int a = func(c,c2,0,0);   
    if(a){
        printf("true %d",a);
    }else{
        printf("false %d",a);
    }
}

int func(char* c,char* c2,int n,int n2){
    if(c[n]=='\0'){
        if(c2[n2]=='\0'){
            return 1;
        }
        return 0;
    }else if(c[n]==c2[n2]){
        return func(c,c2,n+1,n2+1);
    }else if(c2[n2]=='\0'){
        return 1;
    }else {
        return func(c,c2,n-n2+1,0);
    }
}