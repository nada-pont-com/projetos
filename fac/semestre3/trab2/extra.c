#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define starter 1

typedef struct cadastro_estudante {
            char nome[40];
            char sexo[40];
            int id;
            float nota1;
            float nota2;
            float nota3;
            float media;
            float pontuacaoTotal;
    } cadastro_estudante;
    cadastro_estudante spec[10];
     
    int i=0, j = 0; 
    int qualEstud;
    float media = 00.00;
    int opcao;
    
void add(){
    printf("Digite qual aluno deseja editar: \n");
    scanf("%d", &qualEstud);
    // getchar();
    
    printf(" Digite nome do aluno: ");
    scanf("%s%*c", &spec[qualEstud].nome);
    printf(" Digite o sexo do aluno: ");
    scanf("%s%*c", &spec[qualEstud].sexo);
    printf(" Digite a primeira nota: ");
    scanf("%f", &spec[qualEstud].nota1);
    printf(" Digite a segunda nota: ");
    scanf("%f", &spec[qualEstud].nota2);
    printf(" Digite a terceira nota: ");
    scanf("%f", &spec[qualEstud].nota3);

    spec[qualEstud].media = (spec[qualEstud].nota1 + spec[qualEstud].nota2 + spec[qualEstud].nota3) / 3;
}
    
void funcao_ordena(){
    printf("teste");
    int i, j;
    cadastro_estudante aux;

    for( i=0; i<10; i++ ){
        
        for( j=i+1; j<10; j++ ){
            if( spec[i].media < spec[j].media ){
                aux = spec[i];
                spec[i] = spec[j];
                spec[j] = aux;
            }
        }
    }
    
    printf(" \n O nome do aluno é: %s ", spec[0].nome);
    printf(" \n O id do estudante é: %d ", spec[0].id);
    printf(" \n A média do estudante é: %.2f ", spec[0].media);
    printf(" \n ");
      
   
    printf("\n Ordenado com sucesso!");
}
    
void printer(){
    for(i=0; i<=0; i++) {
        
        spec[qualEstud].media = (spec[qualEstud].nota1 + spec[qualEstud].nota2 + spec[qualEstud].nota3) / 3;
    
        printf(" \n O nome do aluno e: %s ", spec[qualEstud].nome);
        printf(" \n O sexo do estudante e: %s ", spec[qualEstud].sexo);
        printf(" \n O id do estudante e: %d ", spec[qualEstud].id);
        printf(" \n A média do estudante e: %.2f ", spec[qualEstud].media);
        printf(" \n ");
    }
}
    
void printer2(){
    for(i=0; i<10; i++) {
        
        spec[qualEstud].media = (spec[qualEstud].nota1 + spec[qualEstud].nota2 + spec[qualEstud].nota3) / 3;
    
        printf(" \n O nome do aluno é: %s ", spec[i].nome);
        printf(" \n O sexo do estudante é: %s ", spec[i].sexo);
        printf(" \n O id do estudante é: %d ", spec[i].id);
        printf(" \n A média do estudante é: %.2f ", spec[i].media);
        printf(" \n ");
    }
}

int main() {
    
    for(i=0; i<10; i++) {
       int number = i;
             strcpy(spec[i].nome, "NULL");
             strcpy(spec[i].sexo, "NULL");
             spec[i].id = number;
             spec[i].nota1 = 0.0;
             spec[i].nota2 = 0.0;
             spec[i].nota3 = 0.0;
             spec[i].pontuacaoTotal = 0.0;
    }
    
    do{
        printf(" [1] Para criar, editar e deletar um estudante \n [2] Media por id \n [3] Maiores medias \n\n");
        scanf("%d", &opcao);
        // getchar();
    
        
        switch (opcao){
            case 1:
                // while(j == 0){
                   add();
                   printer();
                //    scanf("%d", &j);
                // }
                   printer2();
            break;
                   
            case 2:
                   printer();
            break;
            
            case 3: 
                   funcao_ordena();
                   
            break;
            case 4:
                printer2();
            break;
            }
    }while(opcao != 0);
   

    return 0;
}