#include <stdio.h>
#include <stdlib.h>

int main(){
    
/*  Ex2*/
    int subs = 0;
    float temp = 0;
    do{
        printf("Escolha uma das substancias abaixo:(Ex:1)\n1- agua\n2- etanol\n3- ferro\n4- ouro\n5- mercurio\n");
        scanf("%d",&subs);
        if((subs<1)||(subs>5)){
            printf("Substancia invalida!\n");
            subs=-12;
        }
    }while(subs==-12);
    printf("Digite a temperatura da substancia!(Ex:30.545)\n");
    scanf("%f",&temp);
    switch(subs){
    case 1:
        if(temp>=100){
            printf("Agua a %.2f graus celsius, esta no estado gasoso",temp);
        }else if(temp>0){
            printf("Agua a %.2f graus celsius, esta no estado liquido",temp);
        }else{
            printf("Agua a %.2f graus celsius, esta no estado solido",temp);
        }
    break;
    case 2://etanol
        if(temp>=78.37){
            printf("Etanol a %.2f graus celsius, esta no estado gasoso",temp);
        }else if(temp>-114,1){
            printf("Etanol a %.2f graus celsius, esta no estado liquido",temp);
        }else{
            printf("Etanol a %.2f graus celsius, esta no estado solido",temp);
        }
        
    break;
    case 3://Ferro 
        if(temp>=2862){
            printf("Ferro a %.2f graus celsius, esta no estado gasoso",temp);
        }else if(temp>1538){
            printf("Ferro a %.2f graus celsius, esta no estado liquido",temp);
        }else{
            printf("Ferro a %.2f graus celsius, esta no estado solido",temp);
        }
    break;
    case 4://Ouro 
        if(temp>=2700){
            printf("Ouro a %.2f graus celsius, esta no estado gasoso",temp);
        }else if(temp>1064){
            printf("Ouro a %.2f graus celsius, esta no estado liquido",temp);
        }else{
            printf("Ouro a %.2f graus celsius, esta no estado solido",temp);
        }
    break;
    case 5://merculio
        if(temp>=356.7){
            printf("Mercurio a %.2f graus celsius, esta no estado gasoso",temp);
        }else if(temp>-38,83){
            printf("Mercurio a %.2f graus celsius, esta no estado liquido",temp);
        }else{
            printf("Mercurio a %.2f graus celsius, esta no estado solido",temp);
        }
    break;
    default:
        printf("Substancia invalida!");
    break;
    }

}