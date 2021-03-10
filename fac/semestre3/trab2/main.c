#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #include "Celula.h"
#include "Fila.h"
#include "MatrizDinamica.h"

void mostra_c(void*);
void mostra_i(void*);
void mostra_celula(void * celula);

int validaNumero(char *);
void validaInsert(char *texto,int *resp);
void preencheLinhaColuna(int *l,int *c);
int insert(MatrizDinamica *m,int l,int c,char *temp);
int pegaPosicaoIniFim(FILE *arquivo,Celula *ini,Celula *fim,MatrizDinamica caminho);
void getPosicao(Celula *a,int l,int c);

void faz(int l,int c, int d,MatrizDinamica *,MatrizDinamica *,Fila *,Celula);
void moldaCaminho(MatrizDinamica *caminho,Celula fim,MatrizDinamica *caminhoFinal);
void posicaoValida(Celula *c,MatrizDinamica m,char*);
int validaPosicao(Celula *cel,MatrizDinamica m, char *aux);
int pegaDadosArquivo(FILE *arquivo,MatrizDinamica *caminho);

int main(int argc, char const *argv[]){
	MatrizDinamica caminho;
	MatrizDinamica visao;
	
	int aux,l,c,n = 0;
	int opcao;

	char auxChar[5];

	Fila fila;
	inicializa_fila(&fila,30,sizeof(Celula));

	Celula C;
	Celula A;
	Celula B;
	int achou = 0;
	char a[5];

	int valida;
	srand(time(NULL));

	do{
		valida = 0;
		do{
			validaInsert("Preencher o mapa:\n1 - Manual\n2 - Automatico\n3 - Arquivo texto\n",&opcao);
			/*opcao = 1;
			printf("Preencher o mapa:\n1 - Manual\n2 - Automatico\n3 - Arquivo texto\n");
		    gets(auxChar);
		    aux = validaNumero(auxChar);
		    if(aux){
		        opcao = atoi(auxChar);
		    }else
		    	printf("Digite um valor valido\n");*/
		} while (opcao>3 || opcao<1);

		if(opcao==2){
			preencheLinhaColuna(&l,&c);
			inicializa_matriz(&caminho,l,c,sizeof(char*));
			inicializa_matriz(&visao,l,c,sizeof(int));

			// mostra_matriz(caminho,mostra_c);
			for (int i = 0; i < l; ++i){
				for (int j = 0; j < c; ++j){
					char a[5] = {' ','\0'};
					if((rand() % 100) < 20){
						strcpy(a,"[ ]");
					}
					modifica_matriz(&caminho,i,j,&a);
				}
			}
			posicaoValida(&A,caminho,a);
			posicaoValida(&B,caminho,a);
			
			if(compara_celula(B,A)){
				posicaoValida(&B,caminho,a);
			}
		}else if(opcao == 3){
	    	FILE *arquivo = NULL;

			do{
				aux = 1;
				printf("Digite o nome do arquivo. Ex: arquivo\n");
			    gets(auxChar);
			    
			    char nameFile[strlen(auxChar)+4]; 
			    strcpy(nameFile,auxChar);
			    strcat(nameFile,".txt");

		        arquivo = fopen(nameFile,"r");

		        if(arquivo==NULL){
		        	/*do{
			        	printf("Arquivo não encontrado.\n1 - Tentar novamente\n2 - Trocar opção\n");
			        	gets(auxChar);
			        	aux = validaNumero(auxChar);
			        	if(aux){
			        		opcao = atoi(auxChar);
			        	}
		        	} while (!aux);*/
		        	validaInsert("Arquivo não encontrado.\n1 - Tentar novamente\n2 - Trocar opção\n",&opcao);

		        	if(opcao == 1){
		        		aux = 0;
		        	}else
		        		valida = 1;
		        }
			} while (!aux);

			if(!(feof(arquivo))){
				char texto[20];
				char *temp;
				fgets(texto,20,arquivo);
	        	temp = strtok(texto, " ");
				
	        	aux = validaNumero(temp);
	        	printf("%s\n", temp);
	        	if(!aux){
	        		valida = 1;
	        	}else{
	        		l = atoi(temp);
	        		if(l<1){
	        			valida = 1;
	        		}
	        	}

	        	temp = strtok(0, " ");
	        	aux = validaNumero(temp);
	        	printf("%s\n", temp);
	        	printf("%d\n", strlen(temp));
	        	printf("%d\n", aux);
	        	if(!aux || valida){
	        		valida = 1;
	        	}else{
	        		c = atoi(temp);
	        		if(l<1){
	        			valida = 1;
	        		}
	        	}

	        	printf("l:%d || c:%d\n",l,c );

			}else{
				valida = 1;
			}
			
			if(!valida){
				inicializa_matriz(&caminho,l,c,sizeof(char*));
				inicializa_matriz(&visao,l,c,sizeof(int));
			}

			if(!valida && !pegaDadosArquivo(arquivo,&caminho)){
				printf("Erro ao tenar inserir dados no mapa.\n");
				valida = 1;
			}

			pegaPosicaoIniFim(arquivo,&A,&B,caminho);


		}else{
			preencheLinhaColuna(&l,&c);
			inicializa_matriz(&caminho,l,c,sizeof(char*));
			inicializa_matriz(&visao,l,c,sizeof(int));
			printf("Coloque 0 para paredes e 1 para o caminho:\n");	
			for (int i = 0; i < l; ++i){
				for (int j = 0; j < c; ++j){
					do{
						printf("Valor da linha %d e coluna %d\n", i+1, j+1);
						int vl;
						gets(auxChar);
						aux = validaNumero(auxChar);
						if(aux){
							vl= atoi(auxChar);
							if(vl==0 || vl==1){
								strcpy(auxChar, vl ? " " : "[ ]");
								modifica_matriz(&caminho,i,j,auxChar);
							}else{
								aux = 0;
							}
						}else
							printf("Valor invado\n" );
					} while (!aux);
				}
			}
			do{
				printf("Inicio do caminho:\n");
				getPosicao(&A,l,c);

				printf("posição final do caminho:\n");
				getPosicao(&B,l,c);
				
				if(aux = compara_celula(A,B)){
					printf("Valor iniciol igual ao final\n");
				}
			} while (aux);
			
		}
	}while(valida);
	mostra_matriz(caminho,mostra_c);

	// printf("Inicio:\n");
	// mostrar_celula(A);
	// printf("Fim:\n");
	// mostrar_celula(B);

	inserir(&fila,&A);
	int dist = 0;
	while(!fila_vazia(fila) && !achou){
		remover(&fila,&C);
		// mostra_fila(fila,mostra_celula);
		if(compara_celula(C,B)){
			achou = 1;
		}else{

			l = C.linha;
			c = C.coluna;
			dist = C.dist;
			for (int i = -1; i <= 1; i+=2){
				faz(l+i,c,dist+1,&caminho,&visao,&fila,A);
				faz(l,c+i,dist+1,&caminho,&visao,&fila,A);
			}
		}
	}
	
	if(achou){
		printf("A distancia do ponto A(%d,%d) ate o ponto B(%d,%d) e %d\n",A.linha,A.coluna,B.linha,B.coluna,dist);

		moldaCaminho(&visao,B,&caminho);
		mostra_matriz(caminho,mostra_c);
	}else{
		printf("Nao tem caminho possivel do ponto A(%d,%d) ate o ponto B(%d,%d)\n",A.linha,A.coluna,B.linha,B.coluna);
	}

	return 0;
}

void preencheLinhaColuna(int *l,int *c){
	char auxChar[5];
	int aux;
	do{
		printf("Qual o numero de linhas do mapa:\n");
	    gets(auxChar);
	    aux = validaNumero(auxChar);
	    if(aux){
	        *l = atoi(auxChar);
	    }else
			printf("Digite um valor valido\n");
	} while (!aux);

	do{
		printf("Qual o numero de colunas do mapa:\n");
	    gets(auxChar);
	    aux = validaNumero(auxChar);
	    if(aux){
	        *c = atoi(auxChar);
	    }else
	    	printf("Digite um valor valido\n");
	} while (!aux);
}

int pegaDadosArquivo(FILE *arquivo,MatrizDinamica *caminho){
	int l = 0,aux = 1,vl,c = 0;
    char texto[50];
    char *temp;
    int cont = 0;
	while ((l==caminho->linhas && c==caminho->linhas) &&  !(feof(arquivo)) && aux && posicao_valida_matriz(*caminho,l,c)!=ERRO_COORDENADA_INVALIDA){
        fgets(texto,20,arquivo);
        // printf("Texto : %s\n", texto);
        temp = strtok(texto, " ");
        cont = 0;
        c = 0;
    	aux = insert(caminho,l,c,temp);

        while((temp = strtok(0, " ")) != 0 && aux){
        	c++;
        	aux = insert(caminho,l,c,temp);
        }
        l++;
	}

	// mostra_matriz(*caminho,mostra_c);

	return aux;
}

int pegaPosicaoIniFim(FILE *arquivo,Celula *ini,Celula *fim,MatrizDinamica caminho){
	int aux = 1;
	char* temp;
	char texto[20];
	while ( !(feof(arquivo)) && aux){
		fgets(texto,20,arquivo);

        temp = strtok(texto, " ");

		aux = validaNumero(temp);
		
		temp = strtok(0, " ");
		
		if(!aux || (aux && atoi(temp)<0)){
			
		}
	}
}

int insert(MatrizDinamica *caminho,int l,int c,char *temp){
	char texto[20];
	int vl,aux;
	aux = validaNumero(temp);
	// printf("temp :%s\naux:%d\nextra: %d\n", temp,aux,atoi(temp));

	if(!aux || (aux && (atoi(temp)<0 || atoi(temp)>1))){
		aux = 0;
		// printf("ola\n");
		return 0;
	}
	vl = atoi(temp);
	strcpy(texto, vl ? " " : "[ ]");
	// printf("Texto :%s\nVl:%d\n", texto,vl);
	// printf("linha :%d\ncoluna:%d\n", l,c);
	aux = modifica_matriz(caminho,l,c,&texto);
	// printf("\n\n");
	return 1;
}

void posicaoValida(Celula *cel,MatrizDinamica m, char *aux){
	int l = (rand() % m.linhas),c = (rand() % m.colunas);
	get_valor_matriz(&m,l,c,aux);

	if(strcmp(aux," ")){
		posicaoValida(cel,m,aux);
	}else{
		inserir_celula(cel,l,c,0);
	}
}

void faz(int l,int c, int dist,MatrizDinamica *caminho,MatrizDinamica *visao,Fila *fila,Celula inicio){
	int aux,val;
	char *aux2 = malloc(sizeof(char)*4);
	get_valor_matriz(caminho,l,c,aux2);
	val = get_valor_matriz(visao,l,c,&aux);
	
	if(val==1 && !strcmp(aux2," ") && aux==0 && (l!=inicio.linha || c!=inicio.coluna)){
		modifica_matriz(visao,l,c,&dist);
		// printf("%d\n", dist);
		// get_valor_matriz(visao,l,c,&dist);
		// printf("%d\n", dist);
		Celula C;
		inserir_celula(&C,l,c,dist);
		inserir(fila,&C);
	}
	free(aux2);
}

void moldaCaminho(MatrizDinamica *caminho, Celula fim, MatrizDinamica *caminhoFinal){
	int dist,l = fim.linha,c = fim.coluna;
	int aux;
	Celula auxC;
	Fila fila;
	inicializa_fila(&fila,100,sizeof(Celula));

	get_celula_matriz(caminho,fim.linha,fim.coluna,&auxC);
	inserir(&fila,&auxC);
	int d_e,c_b,direcao;
	char *a = malloc(sizeof(char)*5);
	
	strcpy(a," F ");
	printf("l:%d || c:%d\n",l,c );

	modifica_matriz(caminhoFinal,l,c,a);

	while(!fila_vazia(fila)){
		// printf("\n\n");
		// mostra_fila(fila,mostra_celula);
		remover(&fila,&auxC);
		dist = auxC.dist;
		l = auxC.linha;
		c = auxC.coluna;

		d_e = 0;
		c_b = 0;
		// printf("dist: %d\n", dist);
		for (int i = -1; i <= 1; i+=2){

			aux = get_celula_matriz(caminho,l+i,c,&auxC);
			// printf("dist: %d || aux: %d\n", auxC.dist,aux);
			if(auxC.dist==(dist-1) && aux==1){
				get_valor_matriz(caminhoFinal,l+i,c,a);
				if(!(strcmp(a," "))){
					inserir(&fila,&auxC);
					c_b += !!i;
				}
			}
			
			aux = get_celula_matriz(caminho,l,c+i,&auxC);
			// printf("dist: %d || aux: %d\n", auxC.dist,aux);

			if(auxC.dist==(dist-1) && aux==1){
				get_valor_matriz(caminhoFinal,l,c+i,a);
				if(!(strcmp(a," "))){
					inserir(&fila,&auxC);
					d_e += !!i;
				}
			}
		}
		get_valor_matriz(caminhoFinal,l,c,a);
		aux = strcmp(a," F ");
		strcpy(a," a ");
		if(d_e==1 && c_b==1){
			strcpy(a," + ");
		}else if (c_b==1){
			strcpy(a," | ");
		}else{
			strcpy(a," - ");
		}
		if((d_e!=0 || c_b!=0) && aux){
			modifica_matriz(caminhoFinal,l,c,a);
		}
		// printf("%d;%d\n",d_e,c_b);
	}

	printf("l:%d || c:%d\n",l,c );
	strcpy(a," I ");
	modifica_matriz(caminhoFinal,l,c,a);

	free(a);
}

int validaNumero(char *numero){
	if(strlen(numero)==0) return 0;
    for (int i = 0; i < strlen(numero); i++){
        if((i==0) && ((numero[i]=='-') || (numero[i]=='+'))){
            continue;
        }
        if( !( (numero[i]>='0') && (numero[i]<='9') ) && (numero[i]==' ' && (i+1)== strlen(numero))){
        	// printf("%d:%d:%c\n",i,numero[i],numero[i]);
            return 0;
        }
    }
    return 1;
}

void getPosicao(Celula *a,int l,int c){
	int aux;
	char auxChar[5];
	do{
		printf("Digite uma linha:\n");
		gets(auxChar);
		aux = validaNumero(auxChar);
		if(aux){
			a->linha= atoi(auxChar);
		}
	} while (!aux || a->linha<0 || a->linha>l);

	do{
		printf("Digite uma coluna:\n");
		gets(auxChar);
		aux = validaNumero(auxChar);
		if(aux){
			a->coluna= atoi(auxChar);
		}
	} while (!aux || a->coluna<0 || a->coluna>c);
}

void validaInsert(char *texto,int *resp){
	char auxChar[5];
	int aux;
	do{
		*resp = 1;
		printf("%s",texto);
	    gets(auxChar);
	    aux = validaNumero(auxChar);
	    if(aux){
	        *resp = atoi(auxChar);
	    }else
	    	printf("Digite um valor valido\n");
	} while (!aux);
}

void mostra_celula(void * celula){
	Celula *v = celula;
	mostrar_celula(*v);
	// printf("dist: %d\n", v->dist);
	// printf("linha: %d\n", v->linha);
	// printf("coluna: %d\n", v->coluna);
}

void mostra_i(void *i){
	int *v = i;
	printf("%3d", *v);
}

void mostra_c(void *i){
	char *v = i;
	printf("%3s", v);
}