int nrRub = 0;

enum coloracao { Vermelho, Preto };
typedef enum coloracao Cor;

typedef struct noRub {
    struct noRub* pai;
    struct noRub* esquerda;
    struct noRub* direita;
    Cor cor;
    int valor;
} NoRubNg;

typedef struct arvore {
    struct noRub* raiz;
    struct noRub* nulo; 
} Arvore;

NoRubNg* criarNo(Arvore*, NoRubNg*, int);
void balancear(Arvore*, NoRubNg*);
void rotacionarEsquerda(Arvore*, NoRubNg*);
void rotacionarDireita(Arvore*, NoRubNg*);

Arvore* criar();
int vaziaRub(Arvore*);
NoRubNg* adicionarRubNg(Arvore*, int);
NoRubNg* localizarRub(Arvore* arvore, int valor);