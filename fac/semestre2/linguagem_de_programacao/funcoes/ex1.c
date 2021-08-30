#include <stdio.h>
#include <stdlib.h>

int muti(int n,int m2){
    if (n==0){
        return 0;
    }else{
        return m2 + muti(n-1,m2);
    }   
}

int main(int argc, char const *argv[]){
    int n1 = 0 ,n2 = 0;
    printf("ola numb 1 ");
    scanf("%d",&n1);
    printf("ola numb 2 ");
    scanf("%d",&n2);
    int r = muti(n1,n2);
    printf("Resu: %d",r);
    return 0;
}
