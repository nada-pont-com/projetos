#include <stdio.h>
#include <stdlib.h>
#include "arvore.c"

int main() {
    Arvore *a = criar();

    adicionar(a,4);
    adicionar(a,2);
    adicionar(a,8);
    adicionar(a,1);
    adicionar(a,3);
    adicionar(a,6);
    adicionar(a,9);
    adicionar(a,5);
    adicionar(a,7);
    
    printf("pre: ");
    preOrder(a->raiz);
    printf("\n");
    printf("in:  ");
    inOrder(a->raiz);
    printf("\n");
    printf("pos: ");
    posOrder(a->raiz);
    printf("\n");
}