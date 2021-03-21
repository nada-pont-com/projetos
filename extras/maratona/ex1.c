#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,b,p;

    scanf("%d",&n);

    b = (n*n)/2;
    p = (n*n)/2;
    
    if(p%2 != 0){
        p--;
    }
    if(b%2 != 0){
        b--;
    }
    if(n%2 != 0 ) b++;
    printf("%d casas brancas e %d casas pretas",b,p);

    return 0;
}