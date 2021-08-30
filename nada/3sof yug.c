#include <stdio.h>
#include <stdlib.h>

int func(int n);

void main(){
    int n;
    printf("Digite o numero de valor:\n");
    scanf("%d",&n);
    func(n);

}

int func(int n){
    int s;
    if(n==1){
        s = 1;
    }else{
        s = n*n  + func(n-1);
    }
    printf("s = %d\n",s);
    return s;
}
/*
3*3 +  (2*2) + 1 


*/