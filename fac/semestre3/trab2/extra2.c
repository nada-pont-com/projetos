#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * codifica(char*);


int main(){

    char texto1[100];
    char array[100];
    strcpy(array,"");
    char *token;

    int i = 0, j = 0;
    
    printf("Insira a frase a ser separada por espaço: \n\n");
    gets(texto1);
    printf("%s\n", texto1);

    token = strtok(texto1," ");
    char *temp = codifica(token);
    strcat(array,temp);
    free(temp);

    while(token = strtok(NULL, " ")){
        temp = codifica(token);
        strcat(array," ");
        strcat(array,temp);
        free(temp);
    }

    printf("%s\n",array);

    return 0;
}

char* codifica(char *toks){
    char *str = malloc(sizeof(char) * (strlen(toks)+2));
    char temp;
    int i, j;

    printf("%s\n", toks);
    i = 0;
    j = strlen(toks) - 1;
    temp = toks[0];

    for (int i = 0; i < j; i++){
        toks[i] = toks[i+1];
    }

    toks[j] = temp;
    strcpy(str,toks);
    strcat(str, "ei");
    return str;
    // do{
    //     temp = toks[i];
        
        
    //     toks[i] = ' ';
    //     toks[j-1] = temp3;
    //     toks[j] = temp2;
    //     toks[j+1] = temp;
    //     i++;
    // }while(i <1);
    // strcat(toks, "ei");
    // printf("1:");

    // printf("%s\n", str);
}