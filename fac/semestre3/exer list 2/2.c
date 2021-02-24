#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repetidor(char* string,int);


int main(int argc, char const *argv[]){
	char*a = calloc(100,sizeof(char));
	printf("Digite um texto.\n" );
	scanf("%s",a);
	int b= 0.;
	printf("Digite o numero de vezes que o texto ira repetir:\n" );
	scanf("%d",&b);
	
	char *c = repetidor(a,b);
	
	printf("a = %s\n", a);
	printf("c = %s\n", c);
	return 0;
}

char* repetidor(char* s,int n){
	char* s2= calloc((n*strlen(s)+1),sizeof(char));
	int cont = 0;
	for (int i = 0; i < n; ++i){
		for (int i2 = 0; i2 < strlen(s); ++i2){
			*(s2+cont) = *(s + i2);
			cont++;
		}
	}
	*(s2+cont) = '\0';
	return s2;
}
