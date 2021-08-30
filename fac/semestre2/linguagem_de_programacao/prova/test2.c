#include <stdio.h>
#include <stdlib.h>


 int leitorDados( int*, int d);
 int amostraDados(int *, int d);
int uniaoVetor(int *vetorA, int *vetorB, int nA, int nB, int *vetorU);


 int main(){

         int v1,v2;
         int d, p;

         printf("Escreva o tamanho do vetor A: %d \n", &v1);
         scanf("%d", &v1);


         printf("Escreva o tamanho do vetor B: %d \n", &v2);
        scanf("%d", &v2);

        int valida = 1;

        int vetorA[v1];
        int vetorB[v2];


        leitorDados(vetorA, v1);
        leitorDados(vetorB, v2);


        // amostraDados(vetorA, v1);
        // amostraDados(vetorB, v2);    
    }



int leitorDados(int *vetor, int d){

    int valida = 0;
    int i, j;

    for (i=0; i< d; ++i)
        do{
            valida = 0;
            printf("Digite %d valor: \n", (i+1) );
            scanf("%d", &vetor[i]);
            for (j=0; j < i; ++j){
                if(vetor[j] == vetor[i]){
                    valida = 0;
                }
            }
        }while(valida==1);

    }



int uniaoVetor(int *vetorA, int *vetorB, int nA, int nB, int *vetorU){

        printf("\n\t\t\tA União dos vetores A e B\n\n");


        int cont = 0;
        int d, p, valor;



        for (d = 0; d < nA+nB; ++d){
            if (d < nA){
                vetorU[cont] = vetorA[d];
                cont++;
            }else{
                int valor = 0;
                for (p = 0; p <nA; ++p){
                    if(vetorA[p] == vetorB[d-nA]);
                        valor = 1;
                    break;
                }
            }
            if(valor ==1){
                continue;
            }

            vetorU[cont] = vetorB[d - nA];
            cont++;
        }

    return cont;
}