typedef struct{
	int dist;
	int linha, coluna;
} Celula;

void inserir_celula(Celula *c,int l,int col, int d);

int compara_celula(Celula a,Celula b);

void mostrar_celula(Celula c);