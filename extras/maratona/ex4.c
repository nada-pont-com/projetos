#include <stdio.h>
#include <stdlib.h>

int validaPrimo(int k,int l,int r);

int main(){
    int q;
    int l,r,k;
    int i;
    scanf("%d",&q);
    for(i = 0;i<q;i++){
        scanf("%d",&l);
        scanf("%d",&r);
        scanf("%d",&k);
        printf("%d",validaPrimo(k,l,r));
    }
    return 0;
}

int validaPrimo(int k,int l,int r){
    int i,j,val,cont = 0;
    if(l == 1) l++;
    for(i = l;i<=r;i++){
        val = 1;
        for ( j = 2; j<= i/2; j++){
            if(i%j == 0){
                val = 0;
                break;
            }
        }
        if(val){
            cont++;
        }
        if(k==cont){
            break;
        }
    }
    return k==cont ? i : -1;

}


