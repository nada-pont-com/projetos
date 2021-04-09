#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char lampadas; 1 2 4 8 16 32 64 128 <- int 0 - 7
// 
// potencia 2 ^ posicao
// 7 --;
/*  
valor = (int) lampada
for (i>0;i--){
    if(valor< 2 ^ posicao){
        valor = valor - 2 ^ posicao;
    }
}

*/
int potencia(int base,int n){
    if(n<=0) return 1;
    return potencia(base,n-1) * base;
}

int validaEstado(char *lampada,int n){
    int valor = *lampada;
    int valida = 0;
    for (int i = 7; i >= 0 && i >= n; i--){
        valida = 0;
        if(valor>=potencia(2,i)){
            valida = 1;
            valor = valor - potencia(2,i);
        }
    }
    return valida;
}
    
void cadastra(char *lampada){
    int estado;
    int cont;
    printf("Digite qual lâmpada alterar o estado:");
    scanf("%d",&cont);
    printf("%d\n",cont);
    if(cont>8 || cont<1)
        return;
    
    cont--;
    printf("Digite o novo estado da Lâmpada: \n(1) ligado\n(2) desligado\n");
    scanf("%d", &estado);
    if(estado==1){
        if(!validaEstado(lampada,cont)){
            *lampada += potencia(2,cont);
        }
    }else{
        if(validaEstado(lampada,cont)){
            *lampada -= potencia(2,cont);
        }
    }

    printf ("\n\n");
}

void printer(char lampada, int n){
    int valida = 0;
    if(lampada>=potencia(2,n)){
        valida = 1;
        lampada = lampada - potencia(2,n);
    }
    if(n>0){
        printer(lampada,n-1);
    }
    printf("\nL%d -> %s \n", n+1, valida ? "ligada" : "desligada" );
}

int main() {
    char lampada = 0;
    int opcao;
    do{
        printf (" [1] Editar ou adicionar lâmpada \n [2] Imprimir status das lâmpadas\n [0] Deixar do Programa\n\n" );
        printf ("Ação desejada: ");
        scanf("%d", &opcao);
        
        switch (opcao){
            case 1:
                cadastra(&lampada);
                printf ("Lâmpada cadastrada!\n\n");
            break;
                   
            case 2:
                printf("%d",lampada);
                printer(lampada,7);
            break;
            
            }
    }while(opcao != 0);
   

return 0;

}