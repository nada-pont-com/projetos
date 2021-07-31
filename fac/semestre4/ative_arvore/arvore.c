#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


Arvore* criar() {
    Arvore *a = (Arvore*) malloc(sizeof(Arvore));
    a->raiz = NULL;
    return a;
}

int vazia(Arvore *a) {
    return a->raiz == NULL;
}

No* adicionar(Arvore* arvore, int valor) {
    No *no = (No*) malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    // printf("valor");


    if(arvore->raiz == NULL){
        arvore->raiz = no;
    }else{
        no->pai = busca(arvore->raiz,valor);
        if(valor > no->pai->valor){
            no->pai->direita = no;
        }else{
            no->pai->esquerda = no;
        }
    }
    // percorrer(arvore->raiz);
    return no;
}

void remover(Arvore* arvore, No* no) {
    if (no->esquerda != NULL)
        remover(arvore, no->esquerda);  
  
    if (no->direita != NULL)
        remover(arvore, no->direita);
  
    if (no->pai == NULL) {
        arvore->raiz = NULL;
    } else {
        if (no->pai->esquerda == no)
            no->pai->esquerda = NULL;
        else
            no->pai->direita = NULL;
    }
    
    free(no);
}

No* busca(No* no,int valor){
    if(valor > (no->valor)){
        if(no->direita!=NULL){
            return busca(no->direita,valor);
        }
    }else{
        if(no->esquerda!=NULL){
            return busca(no->esquerda,valor);
        }
    }
    return no;
}

void preOrder(No* no) { 
    if (no != NULL) {
        printf("%d ", no->valor);
        
        preOrder(no->esquerda);
        
        preOrder(no->direita);
    }
}

void posOrder(No* no) { 
    if (no != NULL) {
        
        posOrder(no->esquerda);

        posOrder(no->direita);
        
        printf("%d ", no->valor);
    }
}

void inOrder(No* no) { 
    if (no != NULL) {
        inOrder(no->esquerda);
        
        printf("%d ", no->valor);
        
        inOrder(no->direita);
    }
}

