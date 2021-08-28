#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    float preco;
    int quant;
}produto;

void mostrarLista(produto produtos[],int cont);

int main(){
    produto produtos[100];
    int cont = 0,opcao = 0,valor = 0;
    float valorTotal = 0;
    int quant = 0;
    do{
        printf("Escolha um das opcoes abaixo:\n1 - Adicionar\n2 - Remover\n3 - Finalizar\n");
        scanf("%d",&opcao);
        switch (opcao){
        case 1:
            printf("Digite o nome do produto:\n");
            fflush(stdin);
            sscanf(fgets(produtos[cont].nome,20,stdin),"%[^/0]s",produtos[cont].nome);
            fflush(stdin);
            printf("Digite o preco do produto:\n");
            scanf("%f",&produtos[cont].preco);
            printf("Digite o quantidade do produto:\n");
            scanf("%d",&produtos[cont].quant);
            cont++;
            break;
        case 2:
            mostrarLista(produtos,cont);
            printf("Digite o id do produto a ser excluido:(Ex: -1 para cancelar)");
            scanf("%d",&opcao);
            printf("%d\n\n",opcao);
            printf("%d\n\n",opcao);
            if((opcao>=0)&&(opcao<cont)){
                strcpy(produtos[opcao].nome,produtos[cont].nome);
                produtos[opcao].preco = produtos[cont].preco;
                produtos[opcao].quant = produtos[cont].quant;
                cont--;
            }else if(opcao==cont){
                cont--;
            }
            break;
        case 3:
            
            for (int i = 0; i < cont; i++){
                printf("Id:%d\nNome: %c\nQuantidade: %d\nProco uni:%.2f\nPreco:%.2f",(i+1),produtos[i].nome,produtos[i].quant,produtos[i].preco,produtos[i].preco*produtos[i].quant); 
                printf("\n----------------------------------------------------------\n\n");
                valorTotal +=produtos[i].preco*produtos[i].quant;
                quant += produtos[i].quant;
            }   
            float descont = 0;
            if(quant>15){
                descont = 0.1*valorTotal;
            }else if(quant>5){
                descont = 0.2*valorTotal;
            }
            printf("Valor Total: %f\nQuantidade Total: %d\nValor com desconto: %f\n",valorTotal,quant,(valorTotal-descont));
            valor = 1;
            break;
        default:
            printf("\nValor invalido!\n");
            valor = 0;
            break;
        }
    } while (valor==0);
    
    return 0;
}

void mostrarLista(produto produtos[],int cont){
    for (int i = 0; i < cont; i++){
       printf("Id:%d\nNome: %c\nQuantidade: %d\nProco uni:%.2f\nPreco:%.2f",(i+1),produtos[i].nome,produtos[i].quant,produtos[i].preco,produtos[i].preco*produtos[i].quant); 
       printf("\n----------------------------------------------------------\n\n");
    }
    
}

/*
nome do produto
preco uni
quant
valor tot
descontos:
a. até 5 uni sem desc
b. de 6 a 15 10%
c. 16+ 20%
*/
