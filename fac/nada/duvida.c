

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(char* string,char* string2);

int cont(char* c){
    int i = 0;
    while (c[i] != '\0'){
        i++;
    }
    return i;
}

int main(){
    char string[100];
    strcpy(string,"vaca 1231 412 vaca 12312 tusa algoritmo ritmo2");
    func(string,"o2");
    printf("\nnao achou!");
}



void func(char* string,char* string2){
    int cont1 = cont(string);
    int cont2 = cont(string2);
    for(int i = 0;i<cont1;i++){
        if(i>(cont1-cont2)){
            break;
        }
        for(int i2 = 0;i2 < cont2;i2++){
            if(string[i+i2] == string2[i2]){
                if(i2 == cont2-1){
                    printf("acho!");
                    exit(0);
                }
            }else{
                break;
            }
        }
    }
}