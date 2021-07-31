typedef struct arvore {
    struct no* raiz;
} Arvore;

typedef struct no {
    struct no* pai;      //ponteiro para o nó pai
    struct no* esquerda; //ponteiro para o nó filho a esquerda
    struct no* direita;  //ponteiro para o nó filho a direita
    int valor;           //conteúdo de um nó arbitrário da árvore
} No;


Arvore* criar();
No* adicionar(Arvore* arvore, int valor);
void remover(Arvore* arvore, No* no);
No* busca(No* no,int valor);
void inOrder(No* no);
void posOrder(No* no);
void preOrder(No* no);


