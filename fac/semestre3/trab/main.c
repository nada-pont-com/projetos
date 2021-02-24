#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

// Integrantes : Vinicius Dall Olivo Gonçalves e Ana Luiza Croce de Miranda

int precedencia(char a);
int calculo(char *string);
int isNumber(char a);
int executaOperacao(int num1,int num2,char simb);
void validaSimbolo (Pilha *chars,char c, char *s, char *x);

int main(){
	Pilha chars;
	inicializa_pilha( &chars, 10);

	int erro = 0;

	char string[100];
	printf("Digite a conta a ser calculada:\n" );
	scanf("%[^\n]",string);

	char x[2] = {' ','\0'};

	char s[100];

	strcpy(s,"");
	int aux;
	// printf("%s\n", string);
	int num = 0;
	for (int i = 0; i < strlen(string); ++i){
		if(erro) break;
		x[0] = string[i];
		switch(string[i]){
			case ' ':
				if(num>0) num = -3;
				break;
			case '0' ... '9':
				if(num==-1 || num==-3){
					erro = 2;
					break;
				}else if(num<0){
					num = 0;
				}
				num++;
				strcat(s,x);
				break;
			case '(':
				if(num>0 || num==-3){
					strcat(s," ");
					validaSimbolo(&chars,'*',s,x);
				}
				num = -2;

				empilha(&chars,string[i]);
				break;
			case ')':
				if(num==-2) {
					erro = 2;
					break;
				}
				num = -1;
				while(( le_topo(chars,&aux) != ERRO_PILHA_VAZIA ) && ( aux !='(' )){
					desempilha(&chars, &aux);
					x[0] = (char) aux;
					strcat(s,x);
				}
				if(le_topo(chars,&aux)==ERRO_PILHA_VAZIA){
					printf("Erro: ')' sem '('!\n");
					erro = 1;
				}else{
					desempilha(&chars, &aux);
				}
				break;
			case '+': // + *
			case '-':
			case '*':
			case '/':
				num = 0;
				strcat(s," ");
				validaSimbolo(&chars,string[i],s,x);

				break;
			default:
				erro = 1;
				printf("Erro: caractere inválido: c!\n");
				break;
		}
	}
	if(!erro){
		while((le_topo(chars,&aux) != ERRO_PILHA_VAZIA) && ( aux!='(' )){
			desempilha(&chars,&aux);		
			x[0] = (char) aux;
			strcat(s,x);
		}

		if(le_topo(chars,&aux)== ERRO_PILHA_VAZIA){
			desaloca_pilha(&chars);
			printf("%s\n", s);
			printf("Resultado : %d\n", calculo(s));
		}else{
			printf("Erro: ')' sem '('!\n");
		}
	}
	if(erro == 2){
		printf("Erro: ordem de caracteres inválida\n");	
	}

	return 0;
}

void validaSimbolo (Pilha *chars,char c, char *s, char *x){
	int aux = 0;
	le_topo(*chars,&aux);
	if(( le_topo(*chars,&aux) == ERRO_PILHA_VAZIA ) || ( aux=='(' )){
		empilha(chars,c);
	}else{
		while(( le_topo(*chars,&aux) != ERRO_PILHA_VAZIA )  
			&& (precedencia(c) >= precedencia( (char) aux) )){
			desempilha(chars,&aux);
			x[0] = (char) aux;
			strcat(s,x);
		}
		empilha(chars,c);
	}
}

int precedencia(char a){
	if((a=='-') || a=='+'){
		return 2;
	}else if((a=='*') || (a=='/')){
		return 1;
	}
	return 0;
}

int calculo(char *string){
	Pilha p;
	inicializa_pilha(&p,strlen(string));
	int num = 0,aux;
	for (int i = 0; i < strlen(string); ++i){
		char c = string[i];
		if(isNumber(c)){
			aux = (int) c - 48;
			if(num!=0){
				char a[5];
				strcpy(a,"");
				char x[2] = {' ','\0'};
				desempilha(&p,&aux);
				for (int i2 = num; i2 >= 0; --i2){
					x[0] = string[i-i2];
					strcat(a,x);
				}
				aux = atoi(a);
			}
			empilha(&p,  aux );
			num++;
		}else if(c==' '){
			num = 0;
		}else{
			num = 0;
			int aux2,aux1;
			desempilha(&p,&aux2);
			desempilha(&p,&aux1);
			empilha(&p, executaOperacao(aux1,aux2,string[i]));
		}
	}
	int retorno;
	desempilha(&p,&retorno);
	desaloca_pilha(&p);

	return retorno;
}

int isNumber(char a){
	retunr (a>=48 && a<=57);
}

int executaOperacao(int num1,int num2,char simb){
	switch(simb){
		case '+':
			return num1+num2;
			break;
		case '-':
			return num1-num2;
			break;
		case '*':
			return num1*num2;
			break;
		case '/':
			return num1/num2;
			break;
	}
}