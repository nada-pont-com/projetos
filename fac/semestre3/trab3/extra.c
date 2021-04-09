#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef union {
    char itens[50];
    float total;
} Itens;

int integrantes = 0;
int escolha = 0;
int i = 1;


void festa(Itens *item){
    int a = 1;
    int total = 0, quant = 0;
    float custo = 0;
    printf("\n Enter with the item name: ");
    scanf("%s", &(item->itens));
    getchar();
    
    printf("\n Enter with the item cost: ");
    scanf("%f", &custo);
    
    printf("\n Enter with the item quantity: ");
    scanf("%d", &quant);
    
    total = (custo * quant);
    printf("Item: %s \n",item->itens);
    printf("Total: %d \n", total);
    item->total = total;
}

float total(Itens *itens,int cont){
    int pessoas = 1;
    printf("Quantas pessoas tem na festa \n:");
    scanf("%d", &pessoas);

    float total = 0,totalPerPessoa = 0;
    for (int i = 0; i < cont; i++){
        total += itens[i].total;
    }

    totalPerPessoa = total/pessoas;
    return totalPerPessoa;
}

int main (){
    Itens* itens = calloc(5,sizeof(Itens));
    int cont = 0;
    int max = 5;
    do{
        printf("Digite (1) Para adicionar os itens da festa.\nDigite (2) Para ver as despezas por pessoa. \nDigite (0) para sair\n: ");
        scanf("%d", &escolha);
   
        switch(escolha){
            case 1:
                if(cont>=max){
                    realloc(itens,max+=5 * sizeof(Itens));
                }
                festa(&itens[cont]);
                cont++;
                //printf("Ai que delicia cara ");
            break;
            case 2:
                printf("%.2f\n", total(itens,cont));
            break;
        }
    }while(escolha != 0);
  
   return 0;

}
