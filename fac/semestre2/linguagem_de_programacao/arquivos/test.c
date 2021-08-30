#include <stdio.h>
#include <stdlib.h>

int main(){
    char texto[20] = "Ola mundo";
    FILE *arquivo = fopen("texto.txt","w"); 
    char nome[] = "jorge";
    if(arquivo != NULL){
        int retorno = fputs(texto,arquivo); 
        fprintf(arquivo,"No:%s",nome);
        fprintf(arquivo,"\nNome: %s",nome);
        fprintf(arquivo,"N: %d",1000);
        if(retorno == EOF){
            printf("deu ruim!");
        }
        fclose(arquivo);
    }else{
        printf("deu ruim!");
    }
    arquivo = fopen("texto.txt","r");
    if(arquivo != NULL){
        fgets(texto,20,arquivo);
        //for (int i = 0; i < 20; i++){
        //    printf("%c",retorno[i]);
        //}
        //retorno = fgets(texto,100,arquivo);
        //printf("%s",retorno);
        char a[20];
        fscanf(arquivo,"%[^\n]%s",a);
        printf("%s",texto);
        printf("%s",a);
        //fscanf(arquivo,"%s",retorno);
        //printf("%s",retorno);
    
    }
}