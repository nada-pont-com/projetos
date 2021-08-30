#include <stdio.h>
#include <stdlib.h>

int busca(char* c,char* c2,int n,int cont,FILE *);

int main(int argc, char const *argv[]){
    char c[20];

    printf("Digite o que deseja buscar(Uma palavra sem espaco)\n");
    scanf("%s",c);

    FILE *arquivo = fopen("texto.txt","r");
    if(arquivo==NULL){
        printf("Não foi possivel abrir o arquivo\n");
    }else{
        char *c2;
        fscanf(arquivo,"%s",c2);
        int a = busca(c,c2,0,0,arquivo);
        printf("Foram encontradas: %d palavras iguais.\n", a);
    }
}

int busca(char* c,char* c2,int n,int cont,FILE *arquivo) {
     if((c2[n]=='\0')&&(c[n]=='\0')){
        if(feof(arquivo)){
            return cont+1;
        }
        fscanf(arquivo,"%s",c2);
        return busca(c,c2,0,(cont+1),arquivo);
    }else if((c2[n]=='\0')||(c[n]=='\0')){        
        if(feof(arquivo)){
            return cont;
        }
        fscanf(arquivo,"%s",c2);
        
        return busca(c,c2,0,cont,arquivo);
    }else if(c[n]==c2[n]){
        return busca(c,c2,n+1,cont,arquivo);
    }else if(c[n]!=c2[n]){

        if(feof(arquivo)){
            return cont;
        }
        fscanf(arquivo,"%s",c2);
        return busca(c,c2,0,cont,arquivo);
    }
}
