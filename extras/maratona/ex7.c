#include <stdio.h>
#include <stdlib.h>

int main(){
    int q,d1,d2;
    int g,p,m;
    scanf("%d",&d1);
    scanf("%d",&d2);
    scanf("%d",&q);
    int i;
    int d_d1[d1];
    int d_d2[d2];
    int v[q];
    for ( i = 0; i < d1; i++){
        scanf("%d",d_d1 + i);
    }

    for ( i = 0; i < d2; i++){
        scanf("%d",d_d2 + i);
    }

    for (i = 0; i < q; i++){
        scanf("%d",v + i);
    }
    int j,k;
    int* r = (int*) calloc(q,sizeof(int));
    for ( i = 0; i < d1; i++){
        for ( j = 0; j < d2; j++){
            for (k = 0; k < q; k++){
                if(v[k]==(d_d2[j]+d_d1[i])){
                    r[k]++;
                }
            }
        }
    }
    
    for (i = 0; i < q; i++){
        printf("%d\n",r[i]);
    }

    return 0;
}
