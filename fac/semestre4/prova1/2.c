#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERRO_COORDENADA_INVALIDA -1
typedef struct{
	void **dados;
	int linhas, colunas,tamInfo;
} MatrizDinamica;
void mostra(void *a){
    printf("%3d",*(int*) a);
}
int min(int a,int b){
    return a>b? b : a;
}
int set_valor_matriz( MatrizDinamica *p, int lin, int col, void *valor){
	if( lin >= p->linhas || col > p->colunas || lin < 0 || col < 0)
		return ERRO_COORDENADA_INVALIDA;
	memcpy( p->dados[lin] + (col * p->tamInfo),valor,p->tamInfo);
	return 1;
}
int get_valor_matriz( MatrizDinamica *p, int lin, int col, void *info){
	if( lin >= p->linhas || col > p->colunas  || lin < 0 || col < 0)
		return ERRO_COORDENADA_INVALIDA;
	memcpy(info,p->dados[lin] + (col * p->tamInfo),p->tamInfo);
	return 1;
}
void inicializa_matriz( MatrizDinamica *p, int l, int c, int t ){
	p->linhas = l;
	p->colunas = c;
	p->tamInfo = t;
	
	p->dados =  malloc( sizeof(void**) * l);
	int i;
	
	for( i = 0 ; i < l ; i++ ){
		p->dados[i] = calloc( c , t);
	}
}
void desaloca_matriz( MatrizDinamica *p ){
	int i;
	for( i = 0 ; i < p->linhas ; i++ )
		free( p->dados[i] );		
	free( p->dados );
}
void main(){
    char A[100];
    char B[100];
    strcpy(A,"143456");
    strcpy(B,"123456");
    int m = strlen(A);
    int n = strlen(B);
    if(m<n){
        printf("primeira string menor que a Segunda.");
        return;
    }
    MatrizDinamica Matriz;
    inicializa_matriz(&Matriz,m,n,sizeof(int));

    for (int i = 0; i < m; i++){
        set_valor_matriz(&Matriz,i,0,&i);
    }
    for (int j = 0; j < n; j++){
        set_valor_matriz(&Matriz,0,j,&j);
    }
    int valor,c,aux;
    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            c = (A[i]==B[j]) ? 0 : 1;

            get_valor_matriz(&Matriz,i-1,j-1,&valor);
            aux = valor+c;

            get_valor_matriz(&Matriz,i-1,j,&valor);
            aux = min(aux,valor+1);

            get_valor_matriz(&Matriz,i,j-1,&valor);

            valor = min(aux,valor+1);
            set_valor_matriz(&Matriz,i,j,&valor);
        }
    }
    get_valor_matriz(&Matriz,m,n,&valor);
    free(&Matriz);
    printf("%d",valor);
}