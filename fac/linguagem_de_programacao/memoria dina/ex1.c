#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void realloc2(size_t size,void* a);
void main(){
    int n;
    printf("Digite o numero de valores:\n");
    scanf("%d",&n);
    int* a = calloc(n,sizeof(int));
    for (int i = 0; i < n; i++){
        //printf("Digite o valor %d:\n",i+1);
        a[i] = i + 1;
        //scanf("%d",a + i);
        printf("Endereco %p:\n",a+i);
        printf("valor: %d\n",*(a+i));
    }
    n = n *2;
    realloc2(sizeof(int)*n,a);
    printf("\n\n");
     n /= 2;
    for (int i = 0; i < n; i++){
        printf("Endereco: %p\n",a+i);
        printf("valor: %d\n",*(a+i));
    }
    
    free(a);
}

void realloc2(size_t size,void* a){    
    void* b = calloc(0,size);
    memcpy(b,a,sizeof(*a));
    a = calloc(0,size);
    memcpy(a,b,sizeof(*a));    
    free(b);
}