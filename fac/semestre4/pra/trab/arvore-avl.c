#include "arvore-avl.h"


ArvoreAvl* criarArvoreAvl() {
    ArvoreAvl *arvore = malloc(sizeof(ArvoreAvl));
    arvore->raiz = NULL;
  
    return arvore;
}

int vazia(ArvoreAvl* arvore) {
    return arvore->raiz == NULL;
}

NoAvl* adicionarNoAvl(NoAvl* no, int valor) {
    if (valor > no->valor) {
        if (no->direita == NULL) {
            // printf("Adicionando %d\n",valor);
            NoAvl* novo = malloc(sizeof(NoAvl));
            
            novo->direita = NULL;
            novo->esquerda = NULL;
            novo->pai = NULL;

            novo->valor = valor;
            novo->pai = no;

            no->direita = novo;
				
            return novo;
        } else {
            return adicionarNoAvl(no->direita, valor);
        }
    } else {
        if (no->esquerda == NULL) {
            // printf("Adicionando %d\n",valor);
            NoAvl* novo = malloc(sizeof(NoAvl));
            
            novo->direita = NULL;
            novo->esquerda = NULL;
            novo->pai = NULL;

			novo->valor = valor;
            novo->pai = no;
			
            no->esquerda = novo;
			
            return novo;
        } else {
            return adicionarNoAvl(no->esquerda, valor);
        }
    }
}

NoAvl* adicionarAvl(ArvoreAvl* arvore, int valor) {
    if (arvore->raiz == NULL) {
        nrAvl++;

        // printf("Adicionando %d\n",valor);
        NoAvl* novo = malloc(sizeof(NoAvl));
        novo->valor = valor;
        
        novo->direita = NULL;
        novo->esquerda = NULL;
        novo->pai = NULL;

        arvore->raiz = novo;
			
        return novo;
    } else {
        NoAvl* no = adicionarNoAvl(arvore->raiz, valor);
        balanceamento(arvore, no);
        
        return no;
    }
}

void remover(ArvoreAvl* arvore, NoAvl* no) {
    if (no->esquerda != NULL) {
        remover(arvore, no->esquerda); 
    }
  
    if (no->direita != NULL) {
        remover(arvore, no->direita);
    }
  
    if (no->pai == NULL) {
        arvore->raiz = NULL;
    } else {
        if (no->pai->esquerda == no) {
            no->pai->esquerda = NULL;
        } else {
            no->pai->direita = NULL;
        }
    }

    free(no);
}

NoAvl* localizarAvl(NoAvl* no, int valor) {
    if (no->valor == valor) {
        return no;
    } else {
        if (valor < no->valor) {
            if (no->esquerda != NULL) {
                return localizarAvl(no->esquerda, valor);
            }
        } else {
            if (no->direita != NULL) {
                return localizarAvl(no->direita, valor);
            }
        }
    }

    return NULL;
}

void percorrerProfundidadeInOrderAvl(NoAvl* no, void (*callback)(int)) {
    if (no != NULL) {
        percorrerProfundidadeInOrderAvl(no->esquerda,callback);
        callback(no->valor);
        percorrerProfundidadeInOrderAvl(no->direita,callback);
    }
}

void percorrerProfundidadePreOrderAvl(NoAvl* no, void (*callback)(int)) {
    if (no != NULL) {
        callback(no->valor);
        percorrerProfundidadePreOrderAvl(no->esquerda,callback);
        percorrerProfundidadePreOrderAvl(no->direita,callback);
    }
}

void percorrerProfundidadePosOrderAvl(NoAvl* no, void (callback)(int)) {
    if (no != NULL) {
        percorrerProfundidadePosOrderAvl(no->esquerda,callback);
        percorrerProfundidadePosOrderAvl(no->direita,callback);
        callback(no->valor);
    }
}

void visitarAvl(int valor){
    printf("%d ", valor);
}

void balanceamento(ArvoreAvl* arvore, NoAvl* no) {
    while (no != NULL) {
        nrAvl++;
        int fator = fb(no);

        if (fator > 1) { //árvore mais pesada para esquerda
            //rotação para a direita
            if (fb(no->esquerda) > 0) {
                // printf("RSD(%d)\n",no->valor);
                rsd(arvore, no); //rotação simples a direita, pois o FB do filho tem sinal igual
            } else {
                // printf("RDD(%d)\n",no->valor);
                rdd(arvore, no); //rotação dupla a direita, pois o FB do filho tem sinal diferente
            }
        } else if (fator < -1) { //árvore mais pesada para a direita
            //rotação para a esquerda
            if (fb(no->direita) < 0) {
                // printf("RSE(%d)\n",no->valor);
                rse(arvore, no); //rotação simples a esquerda, pois o FB do filho tem sinal igual
            } else {
                // printf("RDE(%d)\n",no->valor);
                rde(arvore, no); //rotação dupla a esquerda, pois o FB do filho tem sinal diferente
            }
        }

        no = no->pai; 
    }
}

int altura(NoAvl* no){
    int esquerda = 0,direita = 0;

    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }
  
    return esquerda > direita ? esquerda : direita; //max(esquerda,direita)
}

int fb(NoAvl* no) {
    nrAvl++;
    int esquerda = 0,direita = 0;
  
    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }
  
    return esquerda - direita;
}

NoAvl* rse(ArvoreAvl* arvore, NoAvl* no) {
    nrAvl++;
    NoAvl* pai = no->pai;
    NoAvl* direita = no->direita;
  
    no->direita = direita->esquerda;
    no->pai = direita;

    direita->esquerda = no;
    direita->pai = pai;

    if (pai == NULL) {
        arvore->raiz = direita;
    } else {
        if (pai->esquerda == no) {
            pai->esquerda = direita;
        } else {
            pai->direita = direita;
        }
    }

    return direita;
}

NoAvl* rsd(ArvoreAvl* arvore, NoAvl* no) {
    nrAvl++;
    NoAvl* pai = no->pai;
    NoAvl* esquerda = no->esquerda;
  
    no->esquerda = esquerda->direita;
    no->pai = esquerda;
  
    esquerda->direita = no;
    esquerda->pai = pai;

    if (pai == NULL) {
        arvore->raiz = esquerda;
    } else {
        if (pai->esquerda == no) {
            pai->esquerda = esquerda;
        } else {
            pai->direita = esquerda;
        }
    }

    return esquerda;
}

NoAvl* rde(ArvoreAvl* arvore, NoAvl* no) {
    no->direita = rsd(arvore, no->direita);
    return rse(arvore, no);
}

NoAvl* rdd(ArvoreAvl* arvore, NoAvl* no) {
    no->esquerda = rse(arvore, no->esquerda);
    return rsd(arvore, no);
}
