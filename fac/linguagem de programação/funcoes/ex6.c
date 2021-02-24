#include <stdio.h>
#include <stdlib.h>

int mdc(int x,int y){
    int resto;
    if(y!=0){
        resto = x % y;
        x = y;
        y = resto;
        mdc(x,y);
    }else{
        return x;
    }
}

int main(int argc, char const *argv[]){
    int x = 0 ,y = 0;
    printf("ola numb 1 ");
    scanf("%d",&x);
    printf("ola numb 2 ");
    scanf("%d",&y);
    if(x<y){
        int aux = x;
        x = y;
        y = aux;
    }
    int r = 0;
    if((x % y) == 0){
        r= y;
    }else{
        r = mdc(x,y);
    }
    printf("Resu: %d",r);
    return 0;
}