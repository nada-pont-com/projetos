#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
    int num;
    float valor = 450;
    scanf("%d",&num);
    for (int i = 0; i < num; i++){
        valor += 550;
        valor += valor*0.55;
    }
    printf("%.2f",valor);
}