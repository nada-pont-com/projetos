#include <stdio.h>

int tamanhoTita(int g,int p,int m, char iden ){
    if(iden=='M'){
        return m;
    }else if(iden=='P'){
        return p;
    }
    return g;
}

int validaMuro(int* muralha, int x,int k,int *cont, int p,int * i,int *min){
    int j = *min;
    int valida = 1;
    do{
        if(muralha[j]-k < 0){
            if(muralha[j]<p){
                (*min)++;
            }
            if(*i==j){
                (*cont)++;
            }
            j++;
        }else{
            muralha[j] = muralha[j]-k;
            valida = 0;
        }
    } while (valida);
    return j;
}

int main(int argc, char const *argv[]){
    int n,x;
    int g,p,m;
    scanf("%d",&n);
    scanf("%d",&x);
    char tamanhos[n];
    scanf("%s",tamanhos);
    scanf("%d",&p);
    scanf("%d",&m);
    scanf("%d",&g);
    int cont = 0;
    int k;
    int muralha[n];
    int muro = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++){
        muralha[i] = x;
        k = tamanhoTita(g,p,m,tamanhos[i]);

        muro = validaMuro(muralha,x,k,&cont,p,&muro,&j);
    }
    printf("%d",(cont+1));
    return 0;
}
