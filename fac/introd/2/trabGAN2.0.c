#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Declaração das funções do codigo
void menos(float**,int,int,int);
void dividi(float**,int,int);
void mostra(float**);
void resolucao(float**, int);
void organiza(float**);
void validaSistema(float**);
int validaZero(float**,int);
//Cria as variaveis 'i' e 'j'
int i /*Linhas*/,j /*Colunas*/;
/*
Pega os dados necessarios para a execução
*/
void main(){
    setlocale(LC_ALL,"");
    //Pede a entrada do numero de equações
    printf("Insira no numero equações: ");
    //Pega o numero digitado e salva na variavel i(linhas)
    scanf("%d",&i);
    //Pede a entrada do numero de variaveis
    printf("Insira no numero variaveis: ");
    //Pega o numero digitado e salva na variavel j(colunas)
    scanf("%d",&j);
    //Verifica se i e j são maires que 0;
    if((i>0)&&(j>0)){
        //Acresenta a coluna dos resultados da equação do sistema linear
        j++;
        //Criaçã da variavel 'matriz', mas de forma dinamica para conseguir enviar como argumento nas funções
        float ** matriz = calloc(i,(sizeof(float*)));
        float  * buf = calloc(i*j,(sizeof(float)));
        for(int i2=0; i2<i; i2++){
            matriz[i2] = &buf[j*i2];
        }
        //Diminui o valor das colunas para ajudar na execução das estruturas de repetoção quando não querer pegar o resultado das equações lineares
        j--;
        //Estrutura de repetiçã que pede os valores de cada valor da matriz.
        for (int linha = 0; linha < i; linha++){ // Estrutura de repetição que viaja por todas as linhas
            for (int coluna = 0; coluna <= j; coluna++){//c<=j para entrar na colunas dos resultados // Estrutura de repetição que viaja por todas as colunas
                if(coluna!=j){
                    //Pede a entrada do valor referente a posição da matriz (os coeficientes)
                    printf("Insira o valor do coeficiente da %dº variavel da %dº equação: ",coluna+1,linha+1);
                }else{
                    //Pede a entrada do valor referente a posição da matriz (os resultados)
                    printf("Insira o valor do resultado da %dº equação: ",linha+1);
                }
                //Pega o valor digitado e salva na variavel matriz na linha i e coluna j
                scanf("%f",&matriz[linha][coluna]);
            }
        }
        //Chama a função que resolve a matriz, '0' é a linha inicial
        resolucao(matriz,0);
        //Chama a função que organiza a função em escada
        organiza(matriz);
        //Chama a função que mostra a matriz
        mostra(matriz);
        //Chama a função diz se é tem resolução
        validaSistema(matriz);
        free(matriz);
        free(buf);
    }
}

/*
organiza a matriz em ordem escada.
*/
void organiza(float** matriz){
    //Estrutura de repetição que viaja por todas as linhas
    for (int linha = 0; linha < i; linha++){    
        //Chama função que retorna 1(verdadeiro) ou 0(falso)
        if(validaZero(matriz,linha)){
        //Estrutura de repetição que viaja por todas as colunas da matriz
            for(int coluna = 0;coluna<=j;coluna++){
                int num = matriz[i-1][coluna];
                matriz[i-1][coluna] = matriz[linha][coluna];
                matriz[linha][coluna] = num;
            }
        }
    }
    //Estrutura de repetição que serve para repetir o processo de organização, numero de linhas-1
	for(int i2 = 0;i2<i-1;i2++){
		for(int linha = 0;linha<i;linha++){
            //Estrutura de repetição que viaja por todas as colunas dos coeficientes
			for(int coluna = 0;coluna<j;coluna++){
                //Verifica se o valor da matriz é igual a '1'
				if(matriz[linha][coluna]==1){
                    //Estrutura de repetição que viaja da linha da matriz[linha][coluna]=1 mais '1' até a ultima linha posivel
					for(int linha2 = linha+1;linha2<i;linha2++){
                        //Estrutura de repetição que viaja da coluna inicial até a coluna da matriz[linha][coluna] = 1 menos '1'
						for(int coluna2 = 0;coluna2<coluna;coluna2++){
							//Verifica se o valor da matriz é igual a '1' em linha2 e coluna2
                            if((matriz[linha2][coluna2]==1)){
                                //Estrutura de repetição que viaja por todas as colunas para tocar as linha de lugar. Ex: ln <-> lm
								for(int coluna3 = 0;coluna3<=j;coluna3++){
                                    //Variavel auxiliar
									int num = matriz[linha2][coluna3];
									matriz[linha2][coluna3] = matriz[linha][coluna3];
									matriz[linha][coluna3] = num;
								}
                                //Finaliza a execução da estrutura de repetição de coluna2
                                break;
							}
						}
					}
				}
			}
		}
	}
}

/*
Resulve a matriz > não necessariamente deixa em modo escada
*/
void resolucao(float** matriz,int linha){
    //Verifica se linha é igual i(numero maximo de linhas)
    if(linha==i){
        //retorna;
        return;
    }
    //Estrutura de repetição que viaja por todas as colunas dos coeficientes
    for (int coluna = 0; coluna < j; coluna++){
        //verifica se o valor da matriz[linha][coluna] !=(diferente) '0'
        if(matriz[linha][coluna]!=0){
            //Chama função que divide a linha, para gerar um pivo;
            dividi(matriz,linha,coluna);
            //Finaliza a estrutura de repetição
            break;
        }
    }
    //Estrutura de repetição que viaja por todas as colunas dos coeficientes
    for (int coluna = 0; coluna < j; coluna++){
        //Verifica se o  valor da matriz[linha][coluna] = '1'
        if(matriz[linha][coluna]==1){
            //Estrutura de repetição que viaja por todas as linhas
            for (int linha2 = 0; linha2 < i; linha2++){
                //Verifica se matriz[linha2][coluna] é diferente de 1 e se linha2 é diferente de linha
                if((matriz[linha2][coluna]!=0)&&(linha2!=linha)){
                    //Chama a função que subtrai um linha da outra. Ex: ln -> ln -k*lm
                    menos(matriz,linha2,linha,coluna);
                }
            }
            //Finaliza a estrutura de repetição
            break;
        }
    }
    //Chama a função e acresenta em 1 o numero da linha
    return resolucao(matriz,linha+1);
}

//Função que subtrar um linha da outra
void menos(float** matriz,int linha,int lP,int coluna){ //lP => linha Principal, linha usada para subtrair 
    //Cria a varivel que representa k em ln -> ln - k*lm
    float variavel = matriz[linha][coluna];
    //Verifica se o valor é diferente de 0 pois não tem sentido subtrair de 0
    if(variavel!=0){
        //Mostra a operação que esta fazendo
        printf("linha l%d -> l%d - %0.2f*l%d",linha+1,linha+1,variavel,lP+1);
        //Estrutura de repetição que viaja por todas as colunas da matriz
        for (int coluna = 0; coluna <= j; coluna++){
            //Realiza a operação: ln -> ln - k*lm
            matriz[linha][coluna] = matriz[linha][coluna] - (variavel*matriz[lP][coluna]);
        }
        //Chama a função que mostra a matriz
        mostra(matriz);
    }
}

//Função que divide a linha da matriz
void dividi(float** matriz,int linha,int coluna){
    //Cria a varivel que representa k em ln -> ln/k
    float variavel = matriz[linha][coluna];
    //Verifica se o valor é diferente de 0 pois não tem sentido subtrair de 0
    if(variavel!=0){
        //Mostra a operação que esta fazendo
        printf("linha l%d -> l%d/%0.2f",linha+1,linha+1,variavel);
        //Estrutura de repetição que viaja por todas as colunas da matriz
        for (int coluna = 0; coluna <= j; coluna++){
            //Realiza a operação: ln -> ln/k
            matriz[linha][coluna] = matriz[linha][coluna]/variavel;
        }
        //Chama a função que mostra a matriz
        mostra(matriz);
    }
}

//Função que adiciona ou retira espaços da variavel esp
void espaco(float numero,int n,char * esp){
    //verifica se n é igua a -1
    if (n == -1){
        // Retorna para nõ ficar em um loop infinito
        return;
        //Verifica se o numero dividido por 10 ou -10 é maior ou igual a 1
    }else if(((numero/10)>=1)||((numero/-10)>=1)){
        //Adiciona valor zero na posição n do vetor esp 
        esp[n] = 0; // 0 = ''
        //Caso não entre nos dois a cima entra nesse
    }else{
        //Coloca o valor ' ' na posição n de esp
        esp[n] = ' ';
    }
    //Chama função, subtraindo 1 de n (n-1)
    espaco(numero/10,(n-1),esp);
}

//Função que mostra a matriz
void mostra(float** matriz){
    //Mostra um traço para melhorar a visibilidade
    printf("\n--------------------------------------------------------------\n");
    //Cria a varivel que serve para adicionar espaço na frente do numero
    char esp[4] = "   ";
    //Estrutura de repetição que viaja por todas linha
    for (int linha = 0; linha < i; linha++){ 
        //Mostra um traço para a barreira esquerda da matriz
        printf("|");
        //Estrutura de repetição que viaja por todas as colunas
        for (int coluna = 0; coluna <= j; coluna++){
            //Verifica se o valor da matriz[linha][coluna] é igual a zero
            if(matriz[linha][coluna]==0){
                //Zera o valor da matriz por causa do '-0' existente em c
                matriz[linha][coluna] = !(!(matriz[linha][coluna]));
            }
            //Verifica se a coluna é igual a j
            if (coluna==j){
                //Mostra o traço para separar os coeficientes dos resultados
                printf(" | ");
            }
            //Verifica se a matriz[linha][coluna] é maior ou igual a zero
            if(matriz[linha][coluna]>=0){
                //Adiciona um espaço para igual a distancia que o sinal de negativo faz 
                printf(" ");
            }
            //Chama a função espaco que modifica a variavel esp
            espaco(matriz[linha][coluna],3,esp);
            //Mostra o esp mais valor da matriz[linha][coluna]
            printf(" %s%.2f ",esp,matriz[linha][coluna]);
        }
        //Mostra o traço(vertical) que fecha a matriz
        printf(" |%s\n",esp);
    }
    //Mostra um traço(horizontal) para melhorar a visibilidade
    printf("--------------------------------------------------------------\n\n");
}

//Valida se o sistema é SPI, SPD ou SI
void validaSistema(float** matriz){
    //Cria as variaveis utilizadas na função
    int pa = 0,pc = 0,n = j,p = 0;
    //Estrutura de repetição que viaja por todas as linha da matriz
    for (int linha = 0; linha < i; linha++){
        //Estrutura de repetição que viaja pelas calunas dos coeficientes
        for (int coluna = 0; coluna < j; coluna++){
            //Verifica se matriz[linha][coluna] é igual a zero
            if(matriz[linha][coluna]!=0){
                //Incrementa mais 1 na variavel pc
                pc++;
                //Finaliza a estrutura de repetção 
                break;
            }
        }
        //Estrutura de repetição
        for (int coluna = 0; coluna <= j; coluna++){
            //Verifica se matriz[linha][coluna] é diferente de zero
            if(matriz[linha][coluna]!=0){
                //Incrementa mais 1 na variavel pa
                pa++;
                //Finaliza a estrutura de repetção 
                break;
            }
        }
    }
    printf("\n\npa: %d\npc: %d\n",pa,pc);
    // verifica se pa e pc são iguais
    if(pa==pc){
        //Adiciona no valor de p o de pa;
        p = pa;
        printf("p: %d\nn-p = %d\n",p,n-p);
        //verifica se n-p é igual a zero
        if((n-p)<=0){
            
            //Mostra uma frase e pula linha
            printf("Sistema Possível Determinado!(SPD)\n");
        }else{
            //Mostra uma frase e pula linha
            printf("Sistema Possível Indeterminado!(SPI)\n");
        }
        //Caso pa for diferente de pc entra aqui
    }else{
        //Mostra uma frase
        printf("Sistema imposivel!(SI)\n");
    }
}

//Função que valida a existencia de linhas com todos os coeficientes igual a zero
int validaZero(float** matriz,int linha){
    //Estrutura de repetição
    for(int coluna = 0;coluna < j;coluna++){
        //Verifica se a matriz[linha][coluna] tem um numero diferente de zero
        if(matriz[linha][coluna]!=0){
            //Retorna zero que representa falso em c
            return 0;
        }
    }
    //Retorna um que representa true(verdadeiro) em c
    return 1;
}